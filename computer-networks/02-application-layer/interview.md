# ❓ Interview QnA — Application Layer

애플리케이션 계층 & 소켓 프로그래밍 면접 대비 핵심 질문 모음

---

## 1. 클라이언트 프로세스 vs 서버 프로세스

-   **Q:** 클라이언트 프로세스와 서버 프로세스의 차이는?
-   **A:**
    -   클라이언트: 요청을 시작하는 쪽, 보통 임시 포트(ephemeral port)를 사용, `connect()` 호출.
    -   서버: 항상 열려 있고 요청을 기다림, 특정 포트(예: 80, 443)에 `bind()` 후 `listen()`.

---

## 2. 소켓(Socket)

-   **Q:** 소켓이란 무엇인가?
-   **A:**

    -   프로세스가 네트워크를 통해 데이터를 주고받기 위한 **논리적 엔드포인트**.
    -   OS가 제공하는 API로, 애플리케이션 ↔ 네트워크 계층 사이의 인터페이스 역할.
    -   TCP 소켓은 연결 지향, UDP 소켓은 비연결형.

-   **Q:** 클라이언트 측에서 `bind()`가 필수가 아닌 이유는?
-   **A:**

    -   클라 소켓 포트는 보통 OS가 **자동으로 임시 포트(ephemeral port)**를 부여.
    -   서버처럼 고정 포트가 필요하지 않기 때문에 `bind()`를 생략 가능.

-   **Q:** 왜 `close()`를 반드시 호출해야 하나?
-   **A:**

    -   소켓을 닫아야 커널이 자원(포트 번호, 커넥션 상태)을 해제.
    -   닫지 않으면 `TIME_WAIT` 상태로 남아 새 연결 지연 발생 가능.

-   **Q:** 소켓은 파일처럼 취급되나?
-   **A:**
    -   네, 유닉스 계열에서 소켓도 **파일 디스크립터**로 관리됨.
    -   `read()`, `write()`, `close()` 같은 시스템 콜을 동일하게 사용할 수 있음.

---

## 3. 멀티플렉싱(Multiplexing) & 디멀티플렉싱(Demultiplexing)

-   **Q:** 멀티플렉싱과 디멀티플렉싱 차이?
-   **A:**

    -   멀티플렉싱: 여러 애플리케이션의 데이터를 하나의 네트워크 채널로 합쳐 전송. (송신 측 전송계층)
    -   디멀티플렉싱: 수신 측에서 세그먼트 헤더를 보고 데이터 흐름을 해당 소켓으로 분배.

-   **Q:** UDP와 TCP의 디멀티플렉싱 차이는?
-   **A:**
    -   UDP: `(목적지 IP, 목적지 Port)` 만으로 소켓 결정.
    -   TCP: `(출발지 IP, 출발지 Port, 목적지 IP, 목적지 Port)` **4-튜플**로 연결 구분.
    -   따라서 TCP는 동일 서버 포트에서도 여러 클라이언트와 독립적인 연결 가능.

---

## 4. HTTP

-   **Q:** HTTP는 TCP를 쓸까 UDP를 쓸까?
-   **A:** 기본적으로 TCP 위에서 동작 (HTTP/3는 UDP 기반 QUIC 사용).

-   **Q:** HTTP가 왜 무상태(stateless)인가?
-   **A:**

    -   설계 당시 단순 문서 전송 목적 → 서버가 상태를 저장하지 않음.
    -   확장성과 단순성 확보. 대신 쿠키/세션/토큰으로 상태 관리 보완.

-   **Q:** Non-persistent HTTP vs Persistent HTTP 차이?
-   **A:**
    -   Non-persistent (HTTP/1.0): 요청마다 새 연결 생성.
    -   Persistent (HTTP/1.1): 기본적으로 연결 유지(keep-alive).
    -   요즘은 대부분 Persistent HTTP 사용.

---

## 5. 신뢰적 데이터 전송 (RDT)

-   **Q:** Stop-and-Wait 방식의 한계는?
-   **A:**

    -   한 번에 하나의 패킷만 보내고 ACK 기다림 → 고속 네트워크에서 대역폭 활용률 매우 낮음.
    -   지연-대역폭 곱이 클수록 성능 저하 심각.

-   **Q:** ACKs의 의미는?
-   **A:**
    -   **ACK (Acknowledgment):** 수신자가 데이터 수신을 확인하는 제어 메시지.
    -   **ACKs:** 여러 개의 확인 응답들. TCP는 누적 ACK, 선택적 ACK(SACK) 등 확장 기능을 가짐.

---

## 6. 기타 개념

-   **Q:** Access Network란?
-   **A:** 사용자가 ISP 네트워크에 접속하는 구간. 예: 가정용 브로드밴드, Wi-Fi, LTE/5G.

-   **Q:** Circuit Switching과 Packet Switching의 차이는?
-   **A:**
    -   Circuit Switching: 회선 독점(전용 자원), 안정적이지만 비효율적.
    -   Packet Switching: 자원 공유(statistical multiplexing), 효율적이지만 지연/손실 가능.

---

## 📒 참고

-   강의자료: Lecture 2. Application Layer
-   교재: _Computer Networking: A Top-Down Approach_ (Kurose & Ross)
-   면접 대비: Tech Interview Handbook, CS Interview Repo
