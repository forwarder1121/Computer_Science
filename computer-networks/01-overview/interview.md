# ❓ Interview QnA – Computer Networks (Introduction & Application Layer)

## 네트워크 기본

- **Q: Packet Switching과 Circuit Switching 차이는?**  
  **A:**  
  - Packet Switching: 공유 기반(statistical multiplexing), 효율적이지만 지연이 가변적  
  - Circuit Switching: 전용 회선 예약, 지연이 일정하고 안정적이지만 비효율적  

- **Q: 네트워크 지연 요소 4가지는?**  
  **A:** Processing delay, Queuing delay, Transmission delay, Propagation delay (PRQT)  

- **Q: Access Network란?**  
  **A:** 호스트가 ISP의 첫 라우터에 접속하는 구간 (집 앞 골목길에 해당). 유선(DSL, Cable, Fiber, Ethernet)과 무선(Wi-Fi, LTE/5G, 위성) 방식이 있다.  

---

## 애플리케이션 계층

- **Q: 클라이언트 프로세스와 서버 프로세스 차이는?**  
  **A:**  
  - 클라이언트: 요청을 initiates, 보통 사용자 단말 (예: 브라우저)  
  - 서버: well-known port에서 listen, 요청을 기다리고 응답 제공 (예: 웹 서버)  

- **Q: P2P 구조란?**  
  **A:** 모든 노드가 동등(peer)하여 동시에 client와 server 역할을 수행하는 구조. 예: BitTorrent, 블록체인.  

- **Q: 소켓(Socket)이란?**  
  **A:** 애플리케이션 ↔ 전송 계층 간 API, 네트워크 통신의 출입구 역할.  

---

## HTTP

- **Q: HTTP가 왜 무상태(stateless)인가?**  
  **A:** 단순 문서 전송을 목적으로 설계되었기 때문에 서버가 요청 상태를 저장하지 않는다. 대신 쿠키/세션/토큰으로 상태를 보완한다.  

- **Q: HTTP/1.0과 HTTP/1.1 차이는?**  
  **A:**  
  - HTTP/1.0: Non-persistent, 요청마다 TCP 연결 생성/종료  
  - HTTP/1.1: Persistent, 기본적으로 연결 유지(keep-alive)  

- **Q: HTTP/2와 HTTP/3의 특징은?**  
  **A:**  
  - HTTP/2: 멀티플렉싱, 헤더 압축, 여전히 TCP 기반  
  - HTTP/3: QUIC(UDP 기반), 지연 줄이고 TLS 내장  

- **Q: HTTP의 기본 포트는?**  
  **A:** 80번 (HTTP), 443번 (HTTPS)

