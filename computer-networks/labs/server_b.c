// mini_server.b — 가장 단순화한 정적 HTTP/1.0 서버
// 목표: "www/index.html" 하나만 서비스. 어떤 경로로 와도 index.html을 내려준다.
//      (요청 라인은 파싱하지 않고, 매 요청에 같은 파일을 보냄 → 코드 단순화 극대화)
// 빌드: cc mini_server.b -o mini_server
// 테스트: 브라우저/아이폰에서 http://<Mac_IP>:8080/  또는  curl -i http://127.0.0.1:8080/

#include <stdio.h>      // printf, perror, dprintf, FILE, fopen, fread, fseek, ftell, rewind
#include <stdlib.h>     // exit, atoi
#include <string.h>     // memset
#include <unistd.h>     // read, write, close
#include <arpa/inet.h>  // htons, htonl, inet_ntoa
#include <sys/socket.h> // socket, bind, listen, accept
#include <netinet/in.h> // struct sockaddr_in

int main(int argc, char **argv)
{
    // 1) 사용할 포트 결정 (인자로 주면 그 값을, 없으면 기본 8080)
    int port = (argc >= 2) ? atoi(argv[1]) : 8080;

    // 2) 서버 소켓 생성: IPv4(AF_INET) + TCP(SOCK_STREAM)
    int srv = socket(AF_INET, SOCK_STREAM, 0);
    if (srv < 0)
    {
        perror("socket");
        exit(1);
    }

    // 3) 빠르게 재시작할 수 있도록 주소 재사용 옵션 설정 (TIME_WAIT 문제 완화)
    int yes = 1;
    setsockopt(srv, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));

    // 4) 바인드할 로컬 주소 구조체 준비: 0.0.0.0:port (모든 인터페이스에서 수신)
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;                // 주소 체계: IPv4
    addr.sin_addr.s_addr = htonl(INADDR_ANY); // 0.0.0.0 (모든 NIC)
    addr.sin_port = htons(port);              // 네트워크 바이트 순서로 변환

    // 5) 소켓을 IP:PORT에 묶기 (실패 시 보통 이미 사용 중인 포트)
    if (bind(srv, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(1);
    }

    // 6) 리스닝 시작: 커널에게 "연결을 받아줄 서버 소켓"임을 알림
    if (listen(srv, 16) < 0)
    {
        perror("listen");
        exit(1);
    }

    printf("mini_server: http://0.0.0.0:%d  (always serves www/index.html)\n", port);

    // 7) 무한 루프: 연결 수락 → 요청을 대충 읽고(무시) → index.html 전송 → 연결 종료
    for (;;)
    {
        // 7-1) 클라이언트 연결 수락 (blocking)
        struct sockaddr_in cli;
        socklen_t clen = sizeof(cli);
        int c = accept(srv, (struct sockaddr *)&cli, &clen);
        if (c < 0)
        {
            perror("accept");
            continue;
        }

        // [참고] 요청 파싱을 생략하기 위해, 한 번 읽어서 버퍼에 담아두고 그대로 무시한다.
        //       (헤더를 분석하지 않아도, 최소한으로는 응답을 보낼 수 있다)
        char req[4096];
        ssize_t rn = read(c, req, sizeof(req) - 1);
        if (rn < 0)
        {
            perror("read");
            close(c);
            continue;
        }
        req[rn] = '\0';
        // 디버깅용으로 첫 줄만 대강 찍어보려면(선택):
        // printf("[client %s:%d] %.*s\n", inet_ntoa(cli.sin_addr), ntohs(cli.sin_port), (int)strcspn(req, "\r\n"), req);

        // 7-2) 매 요청마다 "www/index.html"을 열어서 보낸다.
        //      (가장 단순한 구현을 위해, 경로/메서드/버전을 전혀 검사하지 않음)
        FILE *fp = fopen("www/index.html", "rb");
        if (!fp)
        {
            // 파일이 없으면 404로 간단 응답
            dprintf(c,
                    "HTTP/1.0 404 Not Found\r\n"
                    "Content-Type: text/plain\r\n"
                    "Content-Length: 10\r\n"
                    "Connection: close\r\n"
                    "\r\n"
                    "Not Found\n");
            close(c);
            continue;
        }

        // 7-3) 파일 크기를 구해 Content-Length 헤더에 넣기 (HTTP/1.0에서 매우 중요)
        fseek(fp, 0, SEEK_END);
        long fsize = ftell(fp);
        rewind(fp); // 파일 포인터를 처음으로 되돌림

        // 7-4) 헤더 전송 (항상 200 OK, text/html, 연결은 처리 후 닫음)
        dprintf(c,
                "HTTP/1.0 200 OK\r\n"
                "Content-Type: text/html; charset=utf-8\r\n"
                "Content-Length: %ld\r\n"
                "Connection: close\r\n"
                "\r\n",
                fsize);

        // 7-5) 바디 전송 (작은 버퍼로 반복 복사)
        char buf[8192];
        size_t n;
        while ((n = fread(buf, 1, sizeof(buf), fp)) > 0)
        {
            if (write(c, buf, n) < 0)
                break; // 네트워크 오류 시 중단
        }
        fclose(fp);

        // 7-6) 연결 종료 (HTTP/1.0 + Connection: close 설계이므로 한 요청당 한 연결)
        close(c);
    }
}
