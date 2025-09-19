# 🚚 Network Layer (네트워크 계층)

네트워크 계층은 **호스트 간 데이터그램 전달**을 담당한다. 주요 역할은 **포워딩(Forwarding)**, **라우팅(Routing)**, 그리고 **주소 지정(Addressing)** 이다. 또한, IP 프로토콜을 중심으로 다양한 보조 프로토콜(DHCP, ICMP, NAT 등)이 동작한다.

---

## 1. Key Functions of Network Layer

-   **Forwarding (전달)**

    -   라우터가 들어온 패킷의 목적지 주소를 보고, 적절한 출력 링크로 내보냄.
    -   포워딩 테이블(Forwarding Table) 참조.
    -   Longest Prefix Matching 방식 사용.

-   **Routing (경로 선택)**

    -   패킷이 목적지까지 가는 최적 경로를 결정.
    -   라우팅 알고리즘 기반 (Link State / Distance Vector).

-   **Addressing**

    -   호스트와 라우터의 인터페이스를 구분하는 주소(IP).
    -   계층적 구조로 네트워크 효율성 확보.

---

## 2. IP (Internet Protocol)

-   네트워크 계층의 핵심 프로토콜.
-   Best-effort 전달 (신뢰성 보장 X).
-   Transport Layer (TCP/UDP) 위에 동작.

### 📌 IP Datagram Format

-   주요 필드:

    -   **Version** (IPv4 / IPv6)
    -   **Header Length**
    -   **Time To Live (TTL)**: 네트워크에서 무한 순환 방지.
    -   **Protocol**: 상위 계층(TCP=6, UDP=17)
    -   **Source IP / Destination IP**
    -   **Checksum**
    -   **Data (Payload)**

---

## 3. IP Addressing

-   **IP Address (IPv4)**: 네트워크 상에서 Host Interface 식별.

    -   32-bit 주소 (약 43억 개).
    -   Network ID + Host ID 구조.

-   **Subnet Mask**: 네트워크 ID와 호스트 ID 구분.
-   **Classful Addressing** (과거)

    -   A/B/C Class → 비효율적.

-   **Classless (CIDR, Classless Inter-Domain Routing)**

    -   `a.b.c.d/x` 형태, Prefix 길이로 네트워크 구분.
    -   계층적 주소 할당 → 라우팅 테이블 크기 감소.

---

## 4. NAT (Network Address Translation)

-   내부 사설 IP ↔ 외부 공인 IP 매핑.
-   장점:

    -   IPv4 주소 절약.
    -   내부 네트워크 보호.

-   단점:

    -   End-to-End 원칙 위배 (Layer Violation).
    -   서버 운영 시 포트 포워딩 필요.

---

## 5. DHCP (Dynamic Host Configuration Protocol)

-   호스트에 **동적으로 IP 주소 할당**.
-   절차 (DORA):

    1. Discover (Broadcast)
    2. Offer
    3. Request
    4. Acknowledge

-   장점: 관리 자동화, 유연성.

---

## 6. IP Fragmentation & Reassembly

-   네트워크 링크마다 MTU(Maximum Transmission Unit) 제한 존재.
-   큰 IP Datagram → 작은 Fragment로 분할.
-   목적지에서 Reassembly 수행.
-   손실 시 Transport 계층에서 재전송.

---

## 7. ICMP (Internet Control Message Protocol)

-   네트워크 계층 제어/오류 메시지 전달.
-   사용 예:

    -   `ping` (echo request/reply)
    -   `traceroute`

---

## 8. IPv4 → IPv6 Transition

-   IPv4 한계: 주소 고갈, 보안 부족.
-   IPv6: 128-bit 주소 체계.
-   전환 기법:

    -   Dual Stack
    -   Tunneling

---

## 9. Routing Algorithms

-   **Link State (LS)**: Dijkstra’s Algorithm

    -   각 노드가 전체 네트워크 토폴로지를 알고, 최단 경로 계산.
    -   OSPF(Open Shortest Path First) 프로토콜에서 사용.

-   **Distance Vector (DV)**: Bellman-Ford Algorithm

    -   각 노드가 이웃과만 거리 벡터를 교환.
    -   단순하지만 count-to-infinity 문제 존재 (RIP에서 사용).

-   **Goal**: Source → Destination 최소 비용 경로 탐색.

---

## 10. Routing in the Internet

-   **Intra-AS Routing (AS 내부)**

    -   한 자율 시스템 내부.
    -   RIP (DV 기반), OSPF (LS 기반).

-   **Inter-AS Routing (AS 간)**

    -   서로 다른 AS 간 연결.
    -   BGP (Border Gateway Protocol): 정책 기반 라우팅.

---

📒 **강의 필기**

-   Forwarding = 라우터 테이블 기반 단순 전달.
-   Routing = 최적 경로 계산.
-   IP Datagram 헤더: TTL, Protocol, Checksum 중요.
-   NAT = IPv4 주소 절약 but Layer Violation.
-   DHCP = DORA 과정.
-   IPv4 한계 → IPv6 전환 (Dual Stack, Tunneling).
-   Routing: LS(OSPF) vs DV(RIP), Inter-AS = BGP.
