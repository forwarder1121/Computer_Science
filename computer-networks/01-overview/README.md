# 🌐 01. Introduction

## 📌 핵심 개념 정리

### 네트워크 구조
- **Host (종단 시스템)**: 클라이언트/서버 프로세스 실행
- **Network Edge**: 호스트들이 존재하는 네트워크 끝단
- **Network Core**: 라우터/스위치로 구성, 패킷 스위칭 기반
  - **Circuit Switching**: 전용 회선 예약 (dedicated path)
  - **Packet Switching**: 데이터를 패킷 단위로 전송, statistical multiplexing 기반
- **Access Network**: Host ↔ ISP 첫 라우터 구간 (Ethernet, Wi-Fi, LTE/5G)
- **Physical Media**: twisted pair, coaxial cable, fiber, 무선 채널

### Delay 4요소 (PRQT)
1. **Processing delay**: 라우터에서 헤더 검사, 에러 체크
2. **Queuing delay**: 출력 큐에서 대기
3. **Transmission delay**: 링크에 비트 밀어넣는 시간  
   \[
   d_{trans} = \frac{L}{R}
   \]
   (L=패킷 길이 bits, R=링크 전송률 bps)
4. **Propagation delay**: 신호가 매체를 따라 이동하는 시간  
   \[
   d_{prop} = \frac{d}{s}
   \]
   (d=거리, s=전파속도)

---

# 🌐 02. Application Layer

## 📌 핵심 개념 정리

### 클라이언트–서버 구조
- **클라이언트 프로세스**: 요청을 initiates (예: 브라우저)
- **서버 프로세스**: well-known port에서 listen, 항상 켜져 있음
- **소켓(Socket)**: 애플리케이션 ↔ 전송 계층 간 인터페이스 (네트워크 출입구)

### P2P 구조
- 모든 노드가 동등(peer), 동시에 client+server 역할 수행
- 예: BitTorrent, 블록체인, 초기 Skype

### HTTP (HyperText Transfer Protocol)
- **Stateless**: 서버가 이전 요청 상태를 저장하지 않음
- **버전별 발전**
  - HTTP/1.0 → non-persistent (요청마다 연결)
  - HTTP/1.1 → persistent (기본), keep-alive
  - HTTP/2 → 멀티플렉싱, 헤더 압축
  - HTTP/3 → QUIC(UDP 기반), 지연 감소
- **포트**: 80 (HTTP), 443 (HTTPS)
- **메시지 구조**
  - 요청(Request): `GET /index.html HTTP/1.1`
  - 응답(Response): `HTTP/1.1 200 OK`

### 쿠키/세션/토큰
- **쿠키**: 클라이언트 로컬에 저장, 요청마다 전송
- **세션**: 서버가 상태 저장, 세션 ID로 식별
- **토큰(JWT)**: 클라이언트가 상태를 보관, 무상태 인증 방식

---

## 📊 요약 표

| 개념 | 설명 | 비유 |
|------|------|------|
| Circuit Switching | 전용 경로 예약 | 전용차선 예약 |
| Packet Switching | 패킷 단위 공유망 | 택배 박스 여러 개 배송 |
| Processing Delay | 패킷 검사 시간 | 택배 분류 |
| Queuing Delay | 큐 대기 | 톨게이트 줄 |
| Transmission Delay | 링크에 올리는 시간 | 차를 도로에 올림 |
| Propagation Delay | 신호 이동 시간 | 차가 도로 달림 |
| HTTP Stateless | 상태 기억 X | 패스트푸드 주문, 매번 새로 |
| Persistent HTTP | 연결 유지 | 카페 앉아서 여러 번 주문 |
