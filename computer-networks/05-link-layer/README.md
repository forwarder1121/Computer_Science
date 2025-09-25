# 📘 Link Layer (링크 계층)

링크 계층은 **한 홉(hop)** 내에서 데이터를 프레임 단위로 전달하는 역할을 담당한다. 네트워크 계층의 IP 패킷을 캡슐화하여 LAN, Wi-Fi 등 물리적 네트워크 매체 위에서 전송한다.

---

## 1. 역할과 특징

-   **프레이밍(Framing)**: IP Datagram → Ethernet Frame
-   **주소 지정(Addressing)**: MAC 주소 사용 (LAN Address, Physical Address)
-   **에러 검출(Error Detection)**: CRC(Cyclic Redundancy Check)
-   **매체 접근 제어(Medium Access Control, MAC)**: 공유 매체에서 충돌 방지/해결

---

## 2. Multiple Access & MAC Protocols

여러 호스트가 **하나의 매체(shared medium)**를 쓸 때 **누가 언제 전송할지** 정해야 한다.

### 1) Channel Partitioning

-   **TDMA**: 시간 슬롯 분할
-   **FDMA**: 주파수 대역 분할

### 2) Random Access

-   **ALOHA**: 충돌 나면 무작정 재전송
-   **CSMA**: 전송 전 채널 감지(Carrier Sense)

    -   **CSMA/CD**: 충돌 감지 후 중단 & backoff (Ethernet, 유선)
    -   **CSMA/CA**: 충돌 회피 (Wi-Fi, 무선)

📌 **충돌 감지/회피 물리적 이유**

-   유선: 케이블 위 신호 전압을 비교 → 충돌 감지 가능
-   무선: 송신 신호가 너무 강해 자기 신호에 묻힘 → 감지 불가 → 회피 필요

### 3) Taking Turns

-   **Polling**: master가 slave들에게 차례로 전송 기회 부여
-   **Token Passing**: 토큰 가진 노드만 전송 가능
-   단점: **single point of failure**, 오버헤드

---

## 3. Ethernet & LAN

-   **LAN**: 동일 브로드캐스트 도메인, 라우터 거치지 않고 직접 통신
-   **Ethernet Frame 구조**

    -   Preamble (동기화, 7B + 1B)
    -   Destination MAC (6B)
    -   Source MAC (6B)
    -   Type (2B, ex. IPv4=0x0800)
    -   Data (46~1500B)
    -   CRC (4B, 오류 검출)

📌 **최소 프레임 크기 64B**: 충돌 감지를 위해 필요

---

## 4. MAC Address & ARP

-   **MAC 주소**

    -   48비트, 전 세계적으로 고유
    -   제조사 OUI(Organizationally Unique Identifier) + Host ID

-   **ARP (Address Resolution Protocol)**

    -   역할: **IP → MAC 매핑**
    -   과정:

        -   ARP Request (Broadcast): “192.168.1.10의 MAC 누구?”
        -   ARP Reply (Unicast): “내 MAC은 XX:XX:XX:XX:XX:XX”

    -   결과는 **ARP Table**에 캐싱

---

## 5. Switch & Self-Learning

-   **Hub**: 단순 신호 복제, 충돌 도메인 확장
-   **Switch**: 프레임을 MAC 주소 기반으로 포워딩

    -   **Switch Table** (MAC → Port) 학습 과정

        -   프레임 수신 시: Source MAC → Port 기록
        -   목적지 MAC 확인 후 해당 포트로 전달 (없으면 Flooding)

    -   **Collision Domain 분리** → 효율적 LAN 구성

-   **Router와 차이점**

    -   Switch: MAC 주소 기반, 같은 Subnet 내부 전달
    -   Router: IP 주소 기반, 다른 Subnet 간 전달

---

## 6. 정리

-   **Link Layer 핵심**:

    -   프레임 단위 전송
    -   MAC 주소 기반 통신
    -   충돌 해결을 위한 다양한 MAC 프로토콜

-   **Ethernet** = 유선 LAN 표준 (CSMA/CD 기반)
-   **Wi-Fi (802.11)** = 무선 LAN 표준 (CSMA/CA 기반)
-   **Switch = Self-Learning + Collision Domain 분리**
