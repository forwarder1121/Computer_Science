# 💡 Link Layer Interview QnA

## 기본 개념

**Q1. 링크 계층(Link Layer)의 주요 역할은 무엇인가요?**
A. **한 홉 내 전송**을 담당한다. IP Datagram을 **프레임 단위**로 캡슐화하여 전송하고, **MAC 주소를 이용한 주소 지정**, **에러 검출(CRC)**, **매체 접근 제어(MAC protocol)** 기능을 수행한다.

---

## MAC 프로토콜

**Q2. CSMA/CD와 CSMA/CA의 차이는 무엇인가요?**

-   **CSMA/CD (Collision Detection)**: 유선 Ethernet.

    -   채널 사용 감지 → 충돌 발생 시 즉시 감지하고 중단 → backoff 후 재전송.

-   **CSMA/CA (Collision Avoidance)**: 무선 LAN(Wi-Fi).

    -   무선은 충돌 감지가 어려움 → 충돌을 피하려고 전송 전에 대기(backoff)나 RTS/CTS 절차 사용.

---

**Q3. 무선에서 충돌 감지가 어려운 이유는?**
A. 송신자가 보낸 신호가 너무 강해서, 자기 수신기로 들어오는 다른 신호를 동시에 구분할 수 없다(near-far problem). 그래서 감지 대신 **회피(CA)** 전략을 사용한다.

---

**Q4. Polling 방식의 문제점은 무엇인가요?**
A. 마스터(master)가 모든 노드를 초대해야 하므로 **polling overhead**와 **latency**가 크고, 마스터가 고장 나면 전체 통신이 멈추는 **single point of failure** 문제가 있다.

---

## Ethernet & Frame

**Q5. Ethernet 프레임의 구조를 설명해보세요.**
A.

-   **Preamble (8B)**: 송수신 클럭 동기화
-   **Destination MAC (6B)**, **Source MAC (6B)**
-   **Type (2B)**: 상위 계층 프로토콜 구분 (예: IPv4 = 0x0800)
-   **Data (46~1500B)**: 페이로드(IP 패킷 등)
-   **CRC (4B)**: 오류 검출

---

**Q6. 왜 Ethernet 프레임은 최소 64바이트여야 하나요?**
A. 충돌이 일어났을 때 **전파 지연(propagation delay)** 동안 충돌을 감지할 수 있어야 한다. 너무 짧으면 충돌을 못 느끼고 잘못된 프레임이 전송될 수 있다.

---

## MAC 주소 & ARP

**Q7. MAC 주소와 IP 주소의 차이는 무엇인가요?**

-   **MAC 주소**: 48비트, 전 세계적으로 고유, NIC(네트워크 인터페이스 카드)에 할당.
-   **IP 주소**: 계층적, 네트워크 변경 시 바뀔 수 있음.

---

**Q8. ARP(Address Resolution Protocol)는 무엇인가요?**
A. **IP → MAC 변환** 프로토콜.

-   ARP Request (브로드캐스트): “이 IP 가진 MAC 누구?”
-   ARP Reply (유니캐스트): “내 MAC은 XX:XX:XX:XX:XX:XX”
-   결과는 ARP 테이블에 캐싱.

---

## 스위치와 허브

**Q9. 스위치(Switch)와 허브(Hub)의 차이는?**

-   **허브**: 단순 신호 복제, 충돌 도메인 확장, 비효율적.
-   **스위치**: MAC 주소 기반으로 포워딩, 충돌 도메인 분리, self-learning 지원.

---

**Q10. 스위치의 self-learning은 어떻게 동작하나요?**
A.

1. 프레임 수신 시 Source MAC → 해당 포트로 기록.
2. 목적지 MAC 확인 → 해당 포트로만 전달 (없으면 flooding).
3. 시간이 지나면 오래된 항목은 삭제.

---

## 종합

**Q11. Link Layer의 핵심을 한 문장으로 설명한다면?**
A. “**한 홉 내에서 프레임 단위 전송을 담당하며, MAC 주소와 MAC 프로토콜을 통해 충돌을 방지/해결하는 계층**”
