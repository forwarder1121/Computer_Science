# 💡 Network Layer Interview QnA

## Network Layer Basics

**Q1. 네트워크 계층의 주요 역할은 무엇인가요?**
A. 크게 두 가지다:

-   **Forwarding**: 패킷을 입력 링크에서 적절한 출력 링크로 전달.
-   **Routing**: 출발지에서 목적지까지 가는 최적 경로를 결정.

---

**Q2. Forwarding과 Routing의 차이는 무엇인가요?**

-   Forwarding = 개별 패킷 단위 동작 (라우터 내부에서 테이블 lookup).
-   Routing = 네트워크 전체 관점에서 경로 계산 (라우팅 알고리즘 사용).

---

## IP & Addressing

**Q3. IP는 신뢰적인 프로토콜인가요?**
A. 아니다. IP는 **best-effort service**만 제공한다. 신뢰적 전송은 상위 계층(TCP)이 담당한다.

---

**Q4. IPv4 주소 체계에서 Subnet Mask는 왜 필요한가요?**
A. IP 주소에서 어느 부분이 Network ID이고 어느 부분이 Host ID인지 구분하기 위해.

---

**Q5. CIDR(Classless Inter-Domain Routing)의 장점은 무엇인가요?**
A. 가변 길이 prefix 할당을 통해 주소 공간 낭비를 줄이고, 라우팅 테이블 크기를 줄일 수 있다.

---

**Q6. NAT(Network Address Translation)의 장점과 단점은?**

-   장점: IPv4 주소 절약, 내부 네트워크 보호.
-   단점: End-to-End 원칙 위배, 서버 운영 시 포트 포워딩 필요.

---

## Protocols

**Q7. DHCP가 없다면 어떤 문제가 생길까요?**
A. 모든 호스트에 IP를 수동으로 할당해야 하고, 중복·변경 관리가 어려워진다. DHCP는 자동화된 IP 관리(Discover-Offer-Request-Ack)로 이를 해결한다.

---

**Q8. ICMP는 어떤 역할을 하나요?**
A. 네트워크 계층 제어 및 오류 보고용. 예: `ping`(echo request/reply), `traceroute`(TTL 활용).

---

**Q9. IPv6는 IPv4와 어떤 점이 다른가요?**

-   주소 공간: 32-bit → 128-bit
-   보안, QoS 확장
-   NAT 필요성 감소
-   전환 방식: Dual Stack, Tunneling

---

## Routing

**Q10. Link State와 Distance Vector의 차이는?**

-   **Link State (OSPF)**: 각 노드가 전체 네트워크 토폴로지를 알고, Dijkstra 알고리즘으로 최단 경로 계산. 빠르고 안정적.
-   **Distance Vector (RIP)**: 이웃과 거리 벡터를 교환. 단순하지만 Count-to-Infinity 문제 발생 가능.

---

**Q11. Count-to-Infinity 문제란 무엇인가요?**
A. 링크 비용이 증가(나쁜 소식)했을 때, 잘못된 경로 정보가 라우터들 사이에서 점차 커지며 퍼져 수렴이 매우 느려지는 현상.

---

**Q12. BGP(Border Gateway Protocol)는 왜 ‘정책 기반 라우팅’이라고 불리나요?**
A. 단순히 최단 경로가 아니라 **사업자 간 정책, 비용, 보안 고려** 등 다양한 기준으로 경로를 선택하기 때문이다.

---

**Q13. Intra-AS 라우팅과 Inter-AS 라우팅의 차이는 무엇인가요?**

-   Intra-AS: 하나의 자율 시스템 내부 (RIP, OSPF 등). 최적 경로 중심.
-   Inter-AS: 서로 다른 AS 간 (BGP). 정책 기반.

---

**Q14. OSPF가 RIP보다 선호되는 이유는 무엇인가요?**
A. 빠른 수렴, 대규모 네트워크 지원(area 분할), 보안 옵션 제공, hop 제한 없음.

---

✅ 요약

-   **기본 개념**: Forwarding vs Routing
-   **IP**: Addressing, CIDR, NAT, DHCP
-   **프로토콜**: ICMP, IPv6 전환
-   **라우팅**: LS(OSPF) vs DV(RIP), Count-to-Infinity, BGP 정책
