# 🌐 컴퓨터네트워크 (Computer Networks)

컴퓨터네트워크는 인터넷을 구성하는 **프로토콜 스택(애플리케이션 → 전송 → 네트워크 → 링크/무선/보안)** 의 동작 원리를 학습합니다.  
본 문서는 **강의 기반 개념 정리 + 면접 대비 QnA + 필기 자료**를 체계적으로 관리하기 위한 대시보드 역할을 합니다.  
또한, 실제 소켓 프로그래밍 등 **실습(labs)** 을 직접 해보면서 이해를 심화합니다.

---

## 📌 학습 현황

상태 이모지: ⏳ 미시작 · 🔄 진행 · ✅ 1회독 · ✅✅ 2회독 · 🔁 재복습 · 🚀 완숙

📅 1회독: 2025년 9월 8일 ~ (진행 중)

| No. | 챕터         | 상태 | 링크                                                       |
| --- | ------------ | ---- | ---------------------------------------------------------- |
| 01  | 네트워크 개요    | ✅   | [01-overview](./01-overview/README.md)                   |
| 02  | 애플리케이션 계층 | ✅   | [02-application-layer](./02-application-layer/README.md) |
| 03  | 전송계층       | ⏳   | [03-transport-layer](./03-transport-layer/README.md)     |
| 04  | 네트워크 계층    | ⏳   | [04-network-layer](./04-network-layer/README.md)         |
| 05  | 링크 계층      | ⏳   | [05-link-layer](./05-link-layer/README.md)               |
| 06  | 무선이동네트워크 | ⏳   | [06-wireless](./06-wireless/README.md)                   |
| 07  | 멀티미디어 네트워크 | ⏳ | [07-multimedia](./07-multimedia/README.md)               |
| 08  | 네트워크 보안    | ⏳   | [08-security](./08-security/README.md)                   |
| 09  | 마무리        | ⏳   | [09-summary](./09-summary/README.md)                     |

---

## 🗓️ 학습 체크리스트

### Part 0: 네트워크 개요
- [x] Lec 1. 컴퓨터네트워크 기본 (1) — 인터넷 역사, 네트워크 개념
- [x] Lec 2. 컴퓨터네트워크 기본 (2) — 프로토콜 스택, 표준화

### Part 1: 애플리케이션 계층
- [x] Lec 3. 애플리케이션 계층 (1) — 애플리케이션 유형, 클라이언트/서버, P2P
- [x] Lec 4. 애플리케이션 계층 (2) — 소켓 프로그래밍, UDP/TCP 소켓

---

## 📚 학습 리소스

- 강의: [한양대학교 이석복 – 컴퓨터네트워크 (KOCW)](https://www.kocw.net/home/cview.do?cid=6166c077e545b736)
- 참고 교재: *Computer Networking: A Top-Down Approach (Kurose & Ross)*, *TCP/IP Illustrated Vol.1 (Stevens)*
- 면접 대비: Tech Interview Handbook, CS Interview Repo

---

## 🗂️ 폴더 구조

```

computer-networks/
│── README.md
│
├── 01-overview/              # 네트워크 개요/역사/스택
│   ├── README.md
│   ├── interview\.md
│   ├── notes/
│   └── labs/                 # 실습 코드 (server\_a.c, server\_b.c …)
│       ├── www/              # 정적 파일 예제 (index.html 등)
│       └── ...               # 실습용 서버 코드 (a, b, c … 계속 추가)
│
├── 02-application-layer/
│   ├── README.md
│   ├── interview\.md
│   └── notes/
...

```

---

## 📝 필기 자료 (Handwritten Notes)

- 각 챕터별 `notes/` 폴더에 업로드  
- 권장 규칙: `챕터번호-주제-날짜.jpg` (예: `01-overview-intro-2025-09-09.jpg`)  
- 챕터별 README.md에 필요시 삽입 가능  
