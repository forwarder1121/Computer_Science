# 🌐 컴퓨터네트워크 (Computer Networks)

컴퓨터네트워크는 인터넷을 구성하는 *프로토콜 스택(애플리케이션 → 전송 → 네트워크 → 링크/무선/보안)*의 동작 원리를 학습합니다.
본 문서는 **강의 기반 개념 정리 + 면접 대비 QnA + 직접 필기 자료**를 체계적으로 관리하기 위한 대시보드 역할을 합니다.

---

## 📌 학습 현황

상태 이모지: ⏳ 미시작 · 🔄 진행 · ✅ 1회독 · ✅✅ 2회독 · 🔁 재복습 · 🚀 완숙

📅 1회독: 2025년 9월 8일 \~ (진행 중)

| No. | 챕터         | 상태 | 링크                                                       |
| --- | ---------- | -- | -------------------------------------------------------- |
| 01  | 네트워크 개요    | 🔄 | [01-overview](./01-overview/README.md)                   |
| 02  | 애플리케이션 계층  | ⏳  | [02-application-layer](./02-application-layer/README.md) |
| 03  | 전송계층       | ⏳  | [03-transport-layer](./03-transport-layer/README.md)     |
| 04  | 네트워크 계층    | ⏳  | [04-network-layer](./04-network-layer/README.md)         |
| 05  | 링크 계층      | ⏳  | [05-link-layer](./05-link-layer/README.md)               |
| 06  | 무선이동네트워크   | ⏳  | [06-wireless](./06-wireless/README.md)                   |
| 07  | 멀티미디어 네트워크 | ⏳  | [07-multimedia](./07-multimedia/README.md)               |
| 08  | 네트워크 보안    | ⏳  | [08-security](./08-security/README.md)                   |
| 09  | 마무리        | ⏳  | [09-summary](./09-summary/README.md)                     |

📅 **2회독 계획 :** 흐름 중심, 3파트로 압축 복습

| Part   | 주제 영역         | 범위                                        |  상태 |
| ------ | ------------- | ----------------------------------------- | :-: |
| Part 1 | **L7\~L4 핵심** | TCP(연결/신뢰/혼잡), HTTP/2·3(QUIC), DNS·CDN·LB |  ⏳  |
| Part 2 | **라우팅 심화**    | OSPF/RIP, BGP(정책 라우팅), IP/서브넷/NAT         |  ⏳  |
| Part 3 | **무선·보안·미디어** | 802.11/모빌리티, TLS/PKI, 스트리밍/RTP/RTCP       |  ⏳  |

---

## 🗓️ 학습 체크리스트 (강의 단위)

### Part 0: 네트워크 개요

* [ ] Lec 1. 컴퓨터네트워크 기본 (1) — 인터넷 역사, 네트워크 개념
* [ ] Lec 2. 컴퓨터네트워크 기본 (2) — 프로토콜 스택, 표준화

### Part 1: 애플리케이션 계층

* [ ] Lec 3. 애플리케이션 계층 (1) — 애플리케이션 유형, 클라이언트/서버, P2P
* [ ] Lec 4. 애플리케이션 계층 (2) — 소켓 프로그래밍, UDP/TCP 소켓

### Part 2: 전송계층

* [ ] Lec 5. 전송계층 (1) — 전송 서비스, 다중화/역다중화, UDP
* [ ] Lec 6. 전송계층 (2) — TCP: 연결 관리(3/4-way), 신뢰 전송
* [ ] Lec 7. 전송계층 (3) — 혼잡제어(원리, AIMD, Tahoe/Reno 등)
* [ ] Lec 8. 전송계층 (4) — 혼잡제어(계속), RTT/Throughput, BDP

### Part 3: 네트워크 계층

* [ ] Lec 9. 네트워크계층 (1) — 역할, 포워딩 vs 라우팅
* [ ] Lec 10. 네트워크계층 (2) — IP: 주소, 서브넷, NAT, DHCP, ICMP
* [ ] Lec 11. 네트워크계층 (3) — 라우팅: 링크 상태(LS)
* [ ] Lec 12. 네트워크계층 (4) — 라우팅: 거리 벡터(DV)
* [ ] Lec 13. 네트워크계층 (5) — 인터도메인(BGP), 정책 라우팅
* [ ] Lec 14. 네트워크계층 (6) — 계층적 라우팅, 트래픽 엔지니어링

### Part 4: 링크 계층

* [ ] Lec 15. 링크계층 (1) — 오류검출/정정, ARQ, 신뢰 링크
* [ ] Lec 16. 링크계층 (2) — 이더넷, 스위칭, MAC(ALOHA/CSMA/CD)
* [ ] Lec 17. 링크계층 (3) — VLAN, STP(스패닝 트리)

### Part 5: 무선이동네트워크

* [ ] Lec 18. 무선 (1) — 무선 채널, 경로손실/페이딩, SNR
* [ ] Lec 19. 무선 (2) — 802.11(Wi-Fi) 프레임, 연합(association)
* [ ] Lec 20. 무선 (3) — 셀룰러 개념, 핸드오버, 이동성 관리

### Part 6: 멀티미디어 네트워크

* [ ] Lec 21. 멀티미디어 — 스트리밍, 지터/버퍼링, ABR, RTP/RTCP

### Part 7: 네트워크 보안

* [ ] Lec 22. 보안 (1) — 대칭/비대칭, 해시/서명, TLS/HTTPS
* [ ] Lec 23. 보안 (2) — 인증서/PKI, 방화벽/NAT, IDS/IPS

---

## 📚 학습 리소스

* 강의: [한양대학교 이석복 – 컴퓨터네트워크 (KOCW)](https://www.kocw.net/home/cview.do?cid=6166c077e545b736)
* 참고 교재: *Computer Networking: A Top-Down Approach (Kurose & Ross)*, *TCP/IP Illustrated Vol.1 (Stevens)*
* 면접 대비: Tech Interview Handbook, CS Interview Repo

---

## 🗂️ 폴더 구조

```
computer-networks/
│── README.md                 # 전체 개요 & 현황판 & 진도표
│
├── 01-overview/              # 네트워크 개요/역사/스택
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
├── 02-application-layer/     # HTTP, DNS, Socket, P2P
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
├── 03-transport-layer/       # UDP, TCP(3/4-way, 신뢰/혼잡/흐름)
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
├── 04-network-layer/         # IP, 서브넷, 라우팅(LS/DV/BGP)
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
├── 05-link-layer/            # 오류검출/정정, 이더넷, 스위칭, VLAN
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
├── 06-wireless/              # 802.11, CSMA/CA, 이동성/핸드오버
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
├── 07-multimedia/            # 스트리밍, RTP/RTCP, ABR
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
└── 08-security/              # 암복호화, TLS/HTTPS, PKI, 방화벽
    ├── README.md
    ├── interview.md
    └── notes/
```

---

## 📝 필기 자료 (Handwritten Notes)

* 모든 챕터별 `notes/` 폴더에 업로드
* 권장 규칙: `챕터번호-주제-날짜.jpg` (예: `03-transport-tcp-handshake-2025-09-10.jpg`)
* 챕터별 README.md에 직접 삽입 가능
