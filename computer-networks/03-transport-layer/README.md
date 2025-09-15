# 🚚 Transport Layer (전송 계층)

TCP/UDP 등 전송 계층은 **신뢰적 데이터 전송(RDT)**, **흐름 제어(Flow Control)**, **혼잡 제어(Congestion Control)** 를 핵심으로 한다.
이번 챕터에서는 Go-Back-N, Selective Repeat, TCP의 구조와 동작 방식을 정리한다.

---

## 1. Reliable Data Transfer (RDT)

네트워크는 **packet error / loss**가 발생할 수 있다.
따라서 전송 계층은 **신뢰적 데이터 전송 프로토콜**을 구현한다.

-   **에러 검출 + 피드백(ACK/NAK) + 재전송** 기반
-   기본 방식: **Stop-and-Wait**

    -   한 번에 하나만 보내고 ACK을 기다림 → 비효율적

-   개선: **Pipelining**

    -   여러 패킷을 동시에 전송
    -   두 가지 구현 방식

        -   **Go-Back-N (GBN)**
        -   **Selective Repeat (SR)**

---

## 2. Go-Back-N (GBN)

-   송신자는 **Window size = N** 만큼 보낼 수 있음
-   수신자는 **Expected SeqNum 하나만 기억** (버퍼링 없음)
-   ACK: **누적 ACK (Cumulative ACK)**
-   패킷 손실 발생 시:

    -   해당 패킷 이후 전체를 재전송 (윈도우 크기만큼)

👉 **장점**: 구현 간단
👉 **단점**: 한 패킷만 유실되어도 불필요한 재전송 발생

---

## 3. Selective Repeat (SR)

-   송신자 윈도우: N
-   수신자 윈도우: N
-   수신자는 out-of-order 패킷을 **버퍼링** 후, 개별 ACK
-   손실된 패킷만 재전송 → 효율적

👉 **장점**: 불필요한 재전송 줄임
👉 **단점**: 구현 복잡, 시퀀스 번호 공간이 더 필요함 (≥ 2N)

---

## 4. Sequence Number의 본질

-   목적: **패킷의 상태(과거/현재/미래)** 를 구분
-   GBN:

    -   송신자: N (과거 outstanding)
    -   수신자: 1 (기대하는 미래 하나)
    -   필요 SeqNum ≥ N+1

-   SR:

    -   송신자: N (과거 outstanding)
    -   수신자: N (미래 수용 가능)
    -   필요 SeqNum ≥ 2N

---

## 5. TCP 개요

-   **Point-to-Point**: 송신자 ↔ 수신자
-   **Reliable, In-order Byte Stream**
-   **Full Duplex Data** (양방향 동시에 데이터 교환)
-   **Connection-oriented**: 3-way handshake
-   **Flow Control + Congestion Control** 내장

---

## 6. TCP Segment 구조

-   **Seq #**: 데이터 바이트 번호
-   **ACK #**: 기대하는 다음 바이트 번호
-   **누적 ACK**: "N-1까지 잘 받음 → N부터 보내라"
-   **윈도우(Flow Control)**: 수신 버퍼 여유 공간 (RcvWindow)
-   주요 필드: URG, ACK, PSH, RST, SYN, FIN

---

## 7. TCP Connection Management

-   **3-way Handshake**

    1. SYN
    2. SYN + ACK
    3. ACK (+ data)

-   **4-way Teardown**

    1. FIN
    2. ACK
    3. FIN
    4. ACK

    -   클라이언트는 **timed wait** (유실 대비)

---

## 8. TCP Flow Control

-   수신자는 **RcvWindow**로 버퍼 여유 공간을 광고
-   송신자는 unACKed 데이터 ≤ RcvWindow 로 제한
-   목적: 수신 버퍼 overflow 방지

---

## 9. TCP Congestion Control

-   기본 가정: 네트워크 혼잡 → 패킷 loss (Timeout / DupACK)
-   **세 단계**

    1. **Slow Start**

        - 처음엔 병목 대역폭 모름 → cwnd 지수적 증가

    2. **Additive Increase**

        - 용량에 가까워질수록 선형 증가

    3. **Multiplicative Decrease**

        - 손실 감지 시 cwnd 절반 감소

-   결과: **AIMD (Additive Increase, Multiplicative Decrease)**
    → 여러 연결 간 공평성(Fairness) 보장

---

## 📒 강의 필기

-   [03-2025-09-15-1.jpeg](./notes/03-2025-09-15-1.jpeg)
-   [03-2025-09-15-2.jpeg](./notes/03-2025-09-15-2.jpeg)
-   [03-2025-09-15-3.jpeg](./notes/03-2025-09-15-3.jpeg)
