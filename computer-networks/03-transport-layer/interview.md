# 💡 Transport Layer Interview QnA

## Reliable Data Transfer (RDT)

**Q1. Stop-and-Wait 방식의 한계는 무엇인가요?**
A. 매번 하나씩 보내고 ACK을 기다려야 해서 RTT가 긴 네트워크에서 심각하게 비효율적이다.

**Q2. Go-Back-N과 Selective Repeat의 차이는?**

-   GBN: 수신자가 out-of-order 패킷을 버리고, 송신자가 누락된 이후 모든 패킷을 재전송.
-   SR: 수신자가 out-of-order 패킷을 버퍼링하고, 손실된 것만 재전송.

**Q3. 시퀀스 번호 공간은 왜 GBN은 N+1, SR은 2N이 필요한가요?**

-   GBN: outstanding은 송신자 N + 수신자 기대 1 → 최소 N+1.
-   SR: 송신자 N + 수신자 N → 최소 2N.
    → **시퀀스 번호는 패킷 상태(과거/미래)를 구분하는 도구**다.

---

## TCP Basics

**Q4. TCP는 메시지 경계(Message Boundary)가 없다고 하는데, 무슨 뜻인가요?**
A. TCP는 바이트 스트림으로 동작하여 애플리케이션에 전달되는 경계를 보장하지 않는다. 송신자가 두 번 보낸 데이터가 수신자에게 한 번에 도착할 수도, 나누어 도착할 수도 있다.

**Q5. TCP는 왜 연결(Connection)을 맺나요?**
A. 단순히 데이터를 교환하기 전에 **시퀀스 번호 동기화 + 상태 초기화**를 하여 양쪽이 같은 맥락을 공유하도록 하기 위해서다.

---

## TCP Connection Management

**Q6. TCP 연결은 왜 3-way handshake인가요?**
A. 양쪽 모두 자신의 시퀀스 번호를 상대방에게 알리고, 상대방의 것도 확인해야 하므로 **3단계가 최소**다.

**Q7. 연결 해제는 왜 4-way인가요?**
A. 데이터 전송 방향이 독립적이기 때문. 각 방향마다 FIN-ACK 절차가 필요해서 총 4번 교환한다.

**Q8. Closing 과정에서 클라이언트가 "timed wait"을 하는 이유는?**
A. 마지막 ACK이 유실되었을 때 서버가 FIN을 재전송할 수 있기 때문. 일정 시간 기다리면서 유실 대비를 한다.

---

## TCP Flow & Congestion Control

**Q9. TCP Flow Control의 목적은?**
A. 수신 버퍼 overflow를 막는 것. 수신자가 `RcvWindow` 크기를 광고하고 송신자는 그 이하만 보낸다.

**Q10. TCP Congestion Control의 핵심 아이디어는?**
A. AIMD (Additive Increase, Multiplicative Decrease)

-   처음엔 Slow Start로 지수적 증가
-   네트워크 용량에 가까워지면 선형 증가
-   패킷 손실 발생 시 혼잡을 감지하고 절반으로 감소

**Q11. 중복 ACK을 3번까지 기다렸다가 손실로 판단하는 이유는?**
A. 네트워크에서 out-of-order로 인해 한두 번 중복 ACK은 흔히 발생하므로, 진짜 손실인지 확실히 하기 위해 3번을 기준으로 한다.
