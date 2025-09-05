# 💾 I/O 시스템 & 디스크 관리

운영체제에서 **I/O 시스템**은 CPU, 메모리, I/O 장치 간의 데이터 전송을 관리합니다.  
디스크는 대표적인 보조기억장치로, 입출력 요청을 어떻게 효율적으로 처리하느냐가 시스템 성능에 큰 영향을 미칩니다.

---

## 1️⃣ I/O Mechanisms

I/O 수행 방식은 **CPU 개입 여부**에 따라 나눌 수 있습니다.

### Processor Controlled Access

-   **Polling**
    -   CPU가 주기적으로 I/O 장치 상태를 확인
    -   간단하지만 CPU가 계속 감시해야 하므로 **CPU 낭비(Overhead)** 큼
-   **Interrupt**
    -   I/O 장치가 작업 완료 후 CPU에 인터럽트를 발생시킴
    -   Polling보다 효율적이나, **Interrupt Handling Overhead** 발생

### Direct Memory Access (DMA)

-   CPU 개입 없이 **I/O Device ↔ Memory** 간 데이터 전송
-   CPU는 DMA Controller에 시작/종료만 알려주고, 실제 전송은 DMA가 담당
-   장점: CPU 부담 최소화 → 전체 시스템 성능 향상

---

## 2️⃣ OS의 I/O 서비스 기능

운영체제는 I/O 성능과 안정성을 위해 다양한 기능을 제공합니다.

-   **I/O Scheduling** : 입출력 요청 순서를 최적화
-   **Error Handling** : 입출력 중 발생한 오류를 탐지/복구
-   **Device Information Management** : I/O 장치 정보 관리
-   **Buffering** : 속도 차이를 완화하기 위해 임시 저장소(Buffer) 사용
-   **Caching** : 자주 사용하는 데이터를 미리 복사
-   **Spooling** : 하나의 장치에 여러 요청이 몰릴 때 출력이 섞이지 않도록 조정 (예: 프린터)

---

## 3️⃣ 디스크 스케줄링

디스크 접근 시간:

```

Access Time = Seek Time + Rotational Delay + Transmission Time

```

**성능 지표**

-   **Throughput**: 단위 시간당 처리량
-   **Mean Response Time**: 평균 응답 시간
-   **Predictability**: 공평성, 기아(Starvation) 방지

### 주요 알고리즘 (optimizing seek time)

1. **FCFS (First Come First Serve)**

    - 단순히 도착 순서대로 처리
    - 구현 간단, Overhead 적음
    - 최적 성능과는 거리 멂

2. **SSTF (Shortest Seek Time First)**

    - 현재 Head 위치에서 가장 가까운 요청부터 처리
    - 장점: Throughput ↑, 평균 응답시간 ↓
    - 단점: 멀리 있는 요청은 기아(Starvation) 발생 가능

3. **SCAN (엘리베이터 알고리즘)**

    - Head가 일정 방향으로 이동하며 요청 처리 → 끝까지 가면 방향 전환
    - SSTF 기아 문제 완화
    - 단점: 진행 방향 반대쪽 요청은 응답시간 ↑

4. **C-SCAN (Circular SCAN)**

    - Head가 한쪽 방향으로만 이동, 끝에 도달하면 맨 앞으로 복귀
    - 응답시간의 **공평성** 보장

5. **LOOK / C-LOOK**
    - SCAN / C-SCAN 변형
    - 실제 요청이 있는 지점까지만 이동 → 불필요한 Head 이동 줄임

---

## 4️⃣ 고급 스케줄링 기법 (optimizing rotational time, and total positional time)

-   **SLTF (Shortest Latency Time First)**

    -   회전 지연(Rotational Delay)을 줄이기 위해, 가장 빨리 올 Sector를 우선 처리
    -   Seek Time이 아닌 **회전 지연 최적화**에 초점
    -   장점: Sector-level 최적화
    -   단점: Seek Time은 고려하지 않으므로 전체 최적화는 아님

-   **SPTF (Shortest Positioning Time First)**
    -   Seek Time + Rotational Delay = Positioning Time 을 최소화
    -   단점: 디스크 가장자리 / 중심부 요청이 무시될 수 있음 → Starvation 위험

---

## 5️⃣ RAID Architecture

**RAID (Redundant Array of Inexpensive/Independent Disks)**  
: 여러 개의 물리 디스크를 묶어 **성능 향상 + 신뢰성 보장**을 목표로 하는 구조

-   **RAID 0 (Striping)**

    -   데이터를 블록 단위로 여러 디스크에 분산 저장
    -   장점: 병렬 접근 → 성능 ↑
    -   단점: 디스크 하나라도 고장나면 전체 데이터 손실

-   **RAID 1 (Mirroring)**

    -   데이터를 동일하게 복제하여 저장
    -   장점: 높은 신뢰성 (1개 디스크 장애 허용)
    -   단점: 저장공간 50% 손실 (비용 ↑)

-   **RAID 3**

    -   바이트 단위 Striping + 패리티 디스크 1개
    -   장점: 장애 복구 가능
    -   단점: 패리티 디스크 집중 사용 → 병목

-   **RAID 4**

    -   블록 단위 Striping + 패리티 디스크 1개
    -   단점: 여전히 패리티 디스크 병목 존재

-   **RAID 5**
    -   블록 단위 Striping + 패리티를 모든 디스크에 분산 저장
    -   장점: 병목 해소, 신뢰성과 성능 균형
    -   가장 널리 사용되는 RAID 방식

---

## 📚 참고

-   SLTF: Seek time 최적화 대신 **회전 지연 최적화**를 목표로 한 기법
-   RAID 2, RAID 6, RAID 10 등 다양한 레벨도 존재 (추후 보충 가능)
