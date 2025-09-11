// server_a.c — 가장 단순한 HTTP 서버 (요청을 콘솔에 출력 후 OK 반환)
// 빌드: cc server_a.c -o server_a
// 실행: ./server_a 8080
// 테스트: curl -v http://127.0.0.1:8080/hello
//  같은 Wi-Fi의 아이폰에서: http://<맥북_내부IP>:8080

#include <stdio.h>      // printf, perror
#include <stdlib.h>     // exit, atoi
#include <string.h>     // memset
#include <unistd.h>     // read, write, close
#include <arpa/inet.h>  // htons, htonl, inet_ntoa
#include <sys/socket.h> // socket, bind, listen, accept

int main(int argc, char **argv)
{
    // 1) 포트 결정 (기본 8080)
    int port = (argc >= 2) ? atoi(argv[1]) : 8080;

    // 2) 소켓 생성: IPv4(AF_INET), TCP(SOCK_STREAM)
    int srv = socket(AF_INET, SOCK_STREAM, 0);
    if (srv < 0)
    {
        perror("socket");
        exit(1);
    }

    // 3) TIME_WAIT 재사용 등으로 bind 에러 줄이기 위한 옵션
    int yes = 1;
    setsockopt(srv, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));

    // 4) 바인드 주소 준비: 0.0.0.0:port (모든 인터페이스에서 수신)
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);

    if (bind(srv, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        exit(1);
    }

    // 5) 리스닝 시작: 백로그(대기열) 16
    if (listen(srv, 16) < 0)
    {
        perror("listen");
        exit(1);
    }

    printf("Part A: listening on http://0.0.0.0:%d\n", port);

    // 6) 무한 루프: 연결 하나씩 수락 → 요청 읽기 → 콘솔 출력 → 간단 응답 → 종료
    for (;;)
    {
        struct sockaddr_in cli;
        socklen_t clen = sizeof(cli);
        int c = accept(srv, (struct sockaddr *)&cli, &clen); // (blocking)
        if (c < 0)
        {
            perror("accept");
            continue;
        }

        // 6-1) 요청 읽기 (간단히 한 번만 읽음: 작은 요청 가정)
        char buf[8192];
        ssize_t n = read(c, buf, sizeof(buf) - 1);
        if (n < 0)
        {
            perror("read");
            close(c);
            continue;
        }
        buf[n] = '\0';

        // 6-2) 누가 연결했는지, 무슨 요청인지 출력
        printf("\n[client %s:%d]\n%s\n",
               inet_ntoa(cli.sin_addr), ntohs(cli.sin_port), buf);

        // 6-3) 아주 간단한 HTTP/1.0 응답 (본문: "OK\n")
        const char *body = "OK\n";
        dprintf(c,
                "HTTP/1.0 200 OK\r\n"
                "Content-Type: text/plain\r\n"
                "Content-Length: %zu\r\n"
                "Connection: close\r\n"
                "\r\n"
                "%s",
                strlen(body), body);

        // 6-4) 연결 종료 (HTTP/1.0 + Connection: close)
        close(c);
    }
}
