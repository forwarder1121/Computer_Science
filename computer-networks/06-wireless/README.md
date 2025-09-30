# Ch.6 Wireless and Mobile Networks 요약

## 📌 Link Layer: Wired vs Wireless

-   **유선(Ethernet)**: CSMA/CD (Collision Detection)

    -   충돌 발생 시 **즉시 감지 & 중단** 가능

-   **무선(Wi-Fi, 802.11)**: CSMA/CA (Collision Avoidance)

    -   충돌 감지 불가 → **ACK 기반 회피**
    -   충돌 시 전체 프레임 재전송 → 효율 문제
    -   RTS/CTS 기법으로 hidden terminal 문제 완화

---

## 📌 무선 네트워크의 특징

1. **신호 감쇠 (Path loss)**: 거리가 멀수록 신호 세기 약화
2. **간섭 (Interference)**: 2.4GHz 등 공유 주파수 대역 → 다른 기기와 간섭
3. **다중 경로 전파 (Multipath)**: 반사/굴절로 인해 수신 시점 달라짐 → 페이딩

---

## 📌 Wi-Fi 동작

-   **Scanning**

    -   Passive: AP가 주기적으로 beacon broadcast
    -   Active: Host가 probe 요청, AP가 응답

-   **MAC Protocol (CSMA/CA)**

    -   DIFS → Data → SIFS → ACK
    -   충돌 발생 시 exponential backoff

-   **RTS/CTS**: 채널 예약으로 hidden terminal 문제 해결

---

## 📌 Frame & Addressing

-   Ethernet(802.3): 주소 2개 (DA, SA)
-   Wi-Fi(802.11): 최대 4개 주소 (RA, TA, DA, SA)

    -   **RA**: 지금 당장 무선 신호를 받는 장치 (AP 등)
    -   **TA**: 실제 전송한 장치
    -   **DA**: 최종 목적지
    -   **SA**: 최종 출발지

-   이유: **AP가 무선↔유선 브리지로 동작**하기 때문에

    -   무선 송수신자와 논리적 출발지/목적지가 다름

---

## 📌 Mobility

-   **문제**: 무선 단말이 네트워크 이동 시 IP가 바뀜 → 세션 유지 어려움
-   **TCP 연결 유지 조건**: (Src IP, Dst IP, Src Port, Dst Port) 4-tuple 불변
-   **현실 해결**: Mobile IP, VPN, NAT, 통신사 GTP 등으로 세션 유지 지원

---

## 📌 핵심 비교

| 구분      | 유선 (Ethernet) | 무선 (Wi-Fi)                   |
| --------- | --------------- | ------------------------------ |
| 매체 접근 | CSMA/CD         | CSMA/CA                        |
| 충돌 처리 | 감지 후 중단    | 감지 불가 → 회피               |
| 주소 체계 | DA, SA (2개)    | 최대 4개 주소 (RA, TA, DA, SA) |
| 제어 방식 | 충돌 감지 중심  | ACK, RTS/CTS 기반 충돌 회피    |
| 특성 문제 | 거의 없음       | 감쇠, 간섭, 다중경로 등        |
