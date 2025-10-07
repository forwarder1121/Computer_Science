# 🔐 Chapter 8. Network Security

## 📌 보안 계층의 필요성

> OSI 7계층 중 TCP/IP 계층에는 보안 기능이 부족하다.
> 따라서 네트워크 상에서 안전한 통신을 보장하기 위해
> 암호화, 인증, 무결성 검증 등을 제공하는 보안 계층이 추가로 필요하다.

### 주요 위협

-   **도청(eavesdropping)** — 패킷 스니핑으로 민감정보 유출
-   **변조(modification)** — 중간 공격자가 데이터 위조
-   **위장(spoofing)** — 발신자·수신자 신원 위조
-   **서비스 거부(DoS, DDoS)** — SYN Flood 등으로 자원 고갈

---

## 🧱 보안의 4대 목표 (CIAA)

| 항목                                        | 설명                                                            |
| ------------------------------------------- | --------------------------------------------------------------- |
| **Confidentiality (기밀성)**                | 송신자–수신자만 메시지 내용을 이해할 수 있어야 함. → **암호화** |
| **Authentication (인증)**                   | 상대방의 신원을 확인해야 함. → **서명, 인증서**                 |
| **Message Integrity (무결성)**              | 전송 중 데이터가 변조되지 않았음을 확인. → **해시(MAC)**        |
| **Access & Availability (접근통제·가용성)** | 인가된 사용자만 접근 가능, 24시간 서비스 유지                   |

---

## 🔑 Cryptography (암호화 기법)

### 1️⃣ Symmetric Key (대칭키 암호)

-   송신자와 수신자가 **하나의 동일한 키 Ks**를 공유.
-   암호화/복호화 모두 같은 키 사용.
-   문제점: **키 교환**이 어렵다 (어떻게 안전하게 공유할까?).

> 암호화: `ciphertext = E(Ks, m)`
> 복호화: `m = D(Ks, ciphertext)`

예: AES, DES, 3DES 등.

---

### 2️⃣ Public Key (비대칭키 암호)

-   서로 다른 두 개의 키 사용

    -   **공개키 (Public Key)** : 모두가 볼 수 있음
    -   **개인키 (Private Key)** : 소유자만 알고 있음

-   송신자는 수신자의 **공개키**로 암호화,
    수신자는 자신의 **개인키**로 복호화.

> `m = D(K⁻ᴮ, E(K⁺ᴮ, m))`

**장점:** 키 배포 문제 해결
**단점:** 연산량이 크고 느림 (대칭키보다 비효율적)

---

### 3️⃣ Digital Signature (디지털 서명)

> “메시지의 작성자와 무결성을 보장하기 위한 전자 도장”

#### 🔹 절차

1. 송신자가 메시지 `m`을 해시해서 `H(m)` 계산
2. `H(m)`을 자신의 **개인키(K⁻)** 로 암호화 → 서명 생성
3. 수신자는 송신자의 **공개키(K⁺)** 로 복호화
4. 자신이 다시 계산한 `H(m)`과 비교 → 같으면 변조X

> **즉,** `Decrypt(K⁺, Encrypted(H(m))) == H(m)`

💡 **위조 방지 + 송신자 인증 + 무결성 보장**

---

### 4️⃣ Certificates & CA

-   신뢰할 수 있는 제3자 기관인 **CA(Certificate Authority)** 가
    공개키의 주체가 진짜임을 보증.
-   브라우저는 미리 Root CA 공개키를 내장 → 검증에 사용.
-   CA → Intermediate CA → 서버 인증서 순으로 **서명 체인** 구성.

---

## 🔒 SSL / TLS (Secure Sockets Layer / Transport Layer Security)

### 🔹 개념

> TCP 위에서 동작하는 **보안 계층(Transport Layer Security)**.
> TCP는 데이터의 신뢰성만 보장하므로,
> SSL/TLS가 그 위에서 **암호화·무결성·인증**을 담당한다.

📎 HTTPS = HTTP + SSL/TLS
(즉, Application Layer에서 보안을 추가한 형태)

---

### 🔹 Handshake 과정 요약

```
1. TCP connection 수립
2. Client → Server : hello (지원 암호 알고리즘, client nonce)
3. Server → Client : certificate, server nonce
4. Client → Server : {Master Secret} encrypted with Server public key
5. Master Secret 기반 세션키 생성 → 이후 모든 데이터 암호화
```

---

### 🔹 Data Record Layer 구조

| 필드       | 설명                                                     |
| ---------- | -------------------------------------------------------- |
| **Length** | 레코드 길이                                              |
| **Data**   | 실제 애플리케이션 데이터 (HTTP 메시지 등)                |
| **MAC**    | Message Authentication Code = H(data + key + seq + type) |

→ 각 record 단위로 암호화 + 무결성 검증 수행.

---

### 🔹 Sequence Number & Nonce

-   **Sequence Number**
    → 각 record마다 순번 부여, 재전송·순서변경 공격 방지.
-   **Nonce (number used once)**
    → 세션 고유 식별용 랜덤 값, 이전 세션 재사용 방지.

---

## 🔥 Firewalls (방화벽)

### 🔹 목적

-   **DoS 방지**: SYN Flood 차단
-   **불법 접근 차단**: 내부 데이터 무단 수정 방지
-   **인가된 접근만 허용**: 인증된 사용자/호스트만 접근

---

### 🔹 종류

| 유형                            | 특징                                    |
| ------------------------------- | --------------------------------------- |
| **Stateless Packet Filter**     | 단순 IP/Port 기반 필터링 (세션 추적X)   |
| **Stateful Packet Filter**      | TCP 연결 상태(SYN, ACK 등) 추적         |
| **Application Gateway (Proxy)** | 애플리케이션 데이터 내용 분석 (예: WAF) |

---

### 🧠 Application Gateway 예시 (Telnet)

1. 내부 사용자는 Gateway를 통해서만 외부 Telnet 접속 가능
2. Gateway가 사용자 인증 후 외부 호스트와 Telnet 연결 생성
3. Router는 Gateway 이외의 직접 Telnet 트래픽 차단

💡 즉, Gateway가 **중간 대리인(proxy)** 으로 동작하며
사용자와 외부 서버 간 트래픽을 **검사·중계**한다.

---

## 🧱 정리

| 구분             | 기능                                         |
| ---------------- | -------------------------------------------- |
| **암호화**       | 기밀성 (Confidentiality)                     |
| **디지털 서명**  | 인증 + 무결성                                |
| **SSL/TLS**      | TCP 상 보안 계층 (암호화 + MAC)              |
| **Nonce/SeqNum** | Replay, Reordering 방지                      |
| **Firewall**     | 네트워크 입출구 제어 (패킷/세션/콘텐츠 수준) |

---

## 💬 한 문장 요약

> Network Security는 암호화·인증·무결성 검증을 기반으로
> **SSL/TLS**를 통해 안전한 전송을 보장하고,
> **Firewalls**로 네트워크 경계를 보호한다. 🔐
