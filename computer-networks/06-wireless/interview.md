# Interview Q&A — Wireless and Mobile Networks

## 1. CSMA/CD와 CSMA/CA 차이는 무엇인가요?

**Q:** 유선 Ethernet은 CSMA/CD를 쓰는데, 무선 Wi-Fi는 왜 CSMA/CA를 쓰나요?  
**A:**

-   유선은 충돌을 **감지(CD)** 할 수 있어 충돌 발생 즉시 전송을 중단합니다.
-   무선은 전송 중에는 자신의 신호가 너무 커서 다른 신호를 감지할 수 없어 **충돌 감지 불가**합니다.
-   따라서 Wi-Fi는 **회피(CA)** 전략을 사용: ACK 기반 확인, DIFS/SIFS 간격, RTS/CTS로 충돌 가능성을 줄입니다.

---

## 2. Wi-Fi 프레임에 주소가 최대 4개 필요한 이유는?

**Q:** Ethernet은 출발지/목적지 주소 2개만 있는데, 왜 Wi-Fi는 4개나 쓰나요?  
**A:**

-   무선 네트워크에는 항상 **AP(Access Point)**라는 중계자가 있습니다.
-   따라서 **무선 송수신자**와 **논리적 출발지/목적지**가 다를 수 있습니다.
-   예: STA → AP → 서버
    -   RA: AP (무선 수신자)
    -   TA: STA (무선 송신자)
    -   DA: 서버 (최종 목적지)
    -   SA: STA (최종 출발지)

---

## 3. Wi-Fi에서 DIFS와 SIFS는 왜 존재하나요?

**Q:** 무선 MAC 프로토콜에서 DIFS와 SIFS는 각각 어떤 역할을 하나요?  
**A:**

-   **SIFS (Short IFS)**: 가장 짧은 간격. ACK, CTS 같은 **응답 프레임 우선 전송**.
-   **DIFS (DCF IFS)**: 일반 데이터 전송 전에 기다리는 간격.
-   이유: **제어 프레임(ACK/CTS)**이 항상 데이터보다 우선하도록 보장하기 위함입니다.

---

## 4. 무선 네트워크에서 생기는 문제점은?

**Q:** 무선 링크가 유선보다 어려운 이유는 뭔가요?  
**A:**

1. **감쇠(Path loss)**: 거리가 멀어질수록 신호 약화
2. **간섭(Interference)**: 동일 주파수를 쓰는 기기 간 충돌
3. **다중 경로(Multipath)**: 반사/굴절로 지연 발생 → 페이딩

---

## 5. Mobility 문제는 어떻게 해결하나요?

**Q:** 무선 단말이 네트워크를 이동하면 IP가 바뀌는데, TCP 세션은 어떻게 유지되나요?  
**A:**

-   TCP 연결은 `(Src IP, Dst IP, Src Port, Dst Port)` 4-tuple이 고정돼야 합니다.
-   이동 시 IP가 바뀌면 세션이 끊기는 문제가 있습니다.
-   해결책:
    -   **Mobile IP** (이론적, 실무에선 거의 안 씀)
    -   **VPN**: 가상 IP 유지
    -   **NAT/통신사 GTP**: 내부 터널링으로 IP 불변처럼 보이게 처리
    -   **애플리케이션 레벨**: WhatsApp, Zoom 등이 자체적으로 세션 재연결

---

## 6. Ad hoc 네트워크와 Infrastructure 네트워크의 차이는?

**Q:** Ad hoc 네트워크와 Infrastructure 네트워크의 차이를 설명해보세요.  
**A:**

-   **Infrastructure**: AP(=base station)가 있고, 모든 통신은 AP를 통해 이루어짐. 인터넷 연결 가능. (예: Wi-Fi, LTE)
-   **Ad hoc**: AP 없이 단말들이 직접 연결. 소규모, 임시 네트워크. (예: Bluetooth, Wi-Fi Direct, MANET)

---

## 7. Hidden Terminal 문제란?

**Q:** Wi-Fi에서 hidden terminal 문제란 무엇이고, 어떻게 해결하나요?  
**A:**

-   A와 C는 서로의 신호를 감지하지 못하지만, 둘 다 B와 통신하려고 하면 충돌 발생.
-   **해결책**: RTS/CTS 메커니즘으로 채널 예약 → A와 C가 동시에 송신하지 않도록 조정.
