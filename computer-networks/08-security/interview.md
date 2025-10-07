# 💬 Chapter 8: Network Security — Q&A Summary

---

## 🔐 1. 네트워크 보안(Network Security)이 필요한 이유는?

> TCP/IP 계층은 **데이터의 전달 신뢰성만 보장**하고,
> 암호화나 인증 같은 **보안 기능이 기본적으로 없음.**

그래서 공격자는 다음과 같은 방법으로 침입 가능해요 👇

-   **도청 (Eavesdropping)** : 패킷 스니핑으로 비밀번호 탈취
-   **변조 (Modification)** : 중간 공격자가 데이터 수정
-   **위장 (Spoofing)** : 송신자/수신자 신원 위조
-   **서비스 거부 (DoS)** : SYN Flooding 등으로 서버 마비

---

## 🧩 2. 네트워크 보안의 핵심 목표 4가지는?

| 보안 목표                          | 의미                             | 대표 기술           |
| ---------------------------------- | -------------------------------- | ------------------- |
| **Confidentiality (기밀성)**       | 제3자가 내용을 볼 수 없게        | 암호화 (Encryption) |
| **Authentication (인증)**          | 상대방의 신원을 검증             | 디지털 서명, 인증서 |
| **Message Integrity (무결성)**     | 메시지가 변조되지 않음           | 해시(Hash), MAC     |
| **Access & Availability (가용성)** | 인가된 사용자만 접근, 24h 서비스 | 방화벽, 트래픽 제어 |

---

## 🔑 3. 암호화(Cryptography)의 종류에는 무엇이 있나요?

### 🔹 (1) 대칭키 암호 (Symmetric Key)

-   암호화와 복호화에 **같은 키(Ks)** 사용
-   빠르지만 **키를 교환하는 과정이 위험**
-   예시: AES, DES, 3DES

> `ciphertext = E(Ks, m)` > `m = D(Ks, ciphertext)`

---

### 🔹 (2) 비대칭키 암호 (Public Key)

-   **공개키(Encrypt)** 와 **개인키(Decrypt)** 쌍으로 구성
-   키 공유 문제 해결, 하지만 느림

> `m = D(K⁻ᴮ, E(K⁺ᴮ, m))`

예: RSA, Diffie-Hellman
→ 이 방식이 SSL/TLS의 기반이 된다.

---

## ✉️ 4. 디지털 서명(Digital Signature)이란?

> **메시지의 작성자와 무결성을 보장하는 전자 서명**

### 동작 과정

1️⃣ 송신자: `H(m)` 계산 후 개인키로 암호화 → 서명 생성
2️⃣ 수신자: 송신자의 공개키로 복호화 → `H(m)` 비교
✅ 같으면 "보낸 사람도 맞고, 변조도 없음"

→ 즉, **위조 불가 + 인증 + 무결성 보장**

---

## 🧾 5. 인증서(Certificate)와 CA는 무엇인가요?

-   **CA (Certificate Authority)**: 공개키가 진짜 주인 것임을 보증하는 기관
-   인증서에는 “도메인명 + 공개키 + CA 서명”이 포함
-   브라우저에는 **Root CA 공개키**가 내장되어 있음
-   서버 인증서의 신뢰는 “CA의 서명 검증”으로 판단

📎 구조 예시:

```
서버 인증서 (naver.com)
 └─ 서명자: KISA Intermediate CA
     └─ 서명자: DigiCert Root CA
         └─ Root 공개키 (브라우저 내장)
```

---

## 🔒 6. SSL/TLS는 무엇을 보장하나요?

> TCP 위에서 동작하는 **보안 계층 (Secure Sockets Layer)**
> 데이터 전송 시 **암호화 + 무결성 + 인증**을 담당한다.

📎 HTTPS = HTTP + SSL/TLS

---

## 🤝 7. SSL/TLS Handshake 과정은 어떻게 되나요?

1️⃣ **Client → Server : Hello**

-   지원 암호 알고리즘 목록, Client nonce 전달

2️⃣ **Server → Client : Certificate, Server nonce**

-   서버 인증서 + 공개키 제공

3️⃣ **Client → Server : Encrypted Master Secret**

-   Master Secret을 서버 공개키로 암호화해 전송

4️⃣ **Session Key 생성**

-   양측이 Master Secret 기반 대칭키 생성 → 이후 통신 암호화

---

## 🧩 8. SSL에서 MAC과 Record 구조는 무엇인가요?

> SSL은 데이터를 스트림으로 보내지 않고,
> **“Record 단위”로 나누어** 암호화/무결성을 확인한다.

| 필드       | 설명                                                       |
| ---------- | ---------------------------------------------------------- |
| **Length** | 레코드 길이                                                |
| **Data**   | 전송할 실제 메시지                                         |
| **MAC**    | Message Authentication Code = `H(data + key + seq + type)` |

💡 MAC은 “Message Authentication Code”로,
TCP의 Link-layer MAC 주소와 다르다!

---

## 🔢 9. Sequence Number와 Nonce의 역할은?

-   **Sequence Number**
    → 각 record의 순서를 추적, 중복/재전송 공격 방지

-   **Nonce (Number used once)**
    → 세션 식별용 임의의 랜덤값, 이전 세션 재사용 방지

---

## 🔥 10. Firewall(방화벽)의 목적은?

> 네트워크 경계에서 **트래픽을 필터링**하여
> DoS, 불법 접근, 내부 데이터 유출을 막는 보안 장치.

주요 기능:

-   SYN Flooding 등 **서비스 거부 공격 방지**
-   **내부 데이터 무단 접근 방지**
-   인증된 사용자만 접근 허용

---

## 🧱 11. 방화벽의 세 가지 유형은?

| 유형                        | 설명                               | 예시        |
| --------------------------- | ---------------------------------- | ----------- |
| **Stateless Packet Filter** | 단순 IP/포트 기반 필터링           | 라우터 ACL  |
| **Stateful Packet Filter**  | TCP 연결 상태(SYN/ACK) 추적        | 일반 방화벽 |
| **Application Gateway**     | 실제 애플리케이션 데이터 내용 분석 | Proxy, WAF  |

---

## 🧠 12. Application Gateway(Proxy)의 핵심 아이디어는?

> 내부 사용자가 외부 서버와 직접 통신하지 않고,
> **중간의 게이트웨이가 대신 요청을 수행**하는 구조.

예시 (Telnet):

1. 내부 사용자는 Gateway에 먼저 접속
2. Gateway가 인증된 사용자만 외부 Telnet 서버에 연결
3. Router는 Gateway 외의 모든 Telnet 트래픽을 차단

💡 **애플리케이션 수준에서 데이터 검사** 가능
→ SQL Injection, XSS 탐지(WAF) 등도 이런 원리로 작동

---

## 🧩 13. WAF(Web Application Firewall)는 무엇을 하나요?

> HTTP 요청의 내용 자체를 검사하는 L7(Application Layer) 방화벽

-   SQL Injection, XSS, Path Traversal 등 탐지
-   Header, URL, Body 등 **콘텐츠 레벨 보안**
-   프록시 형태로 동작 (Client ↔ WAF ↔ Server)

---

## 🧭 14. 면접용 한 줄 정리

> “네트워크 보안은 암호화(기밀성), 서명(인증/무결성),
> SSL/TLS(전송 보안), Firewall(경계 보안)의 통합 구조다.” 🔐

---

## 🧩 전체 흐름 요약 다이어그램

```
┌──────────────────────────────────────┐
│           Network Security           │
├──────────────────────────────────────┤
│ 1. 암호화 (Confidentiality)          │
│ 2. 인증/서명 (Authentication)        │
│ 3. 무결성 (Integrity / MAC)          │
│ 4. SSL/TLS - 보안 전송 채널          │
│ 5. Firewalls - 네트워크 경계 보안     │
│ 6. Application Gateway (WAF)         │
└──────────────────────────────────────┘
```
