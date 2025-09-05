# 📝 Interview QnA: I/O 시스템 & 디스크 관리

---

## Q1. Polling과 Interrupt의 차이는?

✅

-   **Polling**: CPU가 주기적으로 I/O 장치 상태를 확인 → 구현 단순, 그러나 CPU Overhead 큼
-   **Interrupt**: 장치가 완료 시 CPU에 알림 → CPU 효율 ↑, 그러나 인터럽트 처리 오버헤드 존재

---

## Q2. DMA(Direct Memory Access)는 왜 필요할까요?

✅

-   CPU 개입 없이 I/O 장치와 메모리 간 직접 데이터 전송 수행
-   CPU는 시작/종료만 관여 → CPU 부담 최소화
-   대용량 데이터 전송 시 성능 개선

---

## Q3. Buffering, Caching, Spooling의 차이를 설명해 보세요.

✅

-   **Buffering**: 속도 차이를 완화하기 위한 임시 저장 (예: 프린터 출력 대기 버퍼)
-   **Caching**: 자주 쓰는 데이터를 빠른 저장소에 미리 복사 (지역성 활용)
-   **Spooling**: 하나의 장치에 여러 요청이 몰릴 때, 요청을 순서대로 처리하여 충돌 방지 (예: 프린터 큐)

---

## Q4. 디스크 접근 시간(Access Time)의 구성 요소는?

✅

-   `Access Time = Seek Time + Rotational Delay + Transmission Time`
-   **Seek Time**: 헤드를 원하는 실린더로 이동
-   **Rotational Delay**: 원하는 섹터가 헤드 아래로 올 때까지 회전 대기
-   **Transmission Time**: 실제 데이터 전송

---

## Q5. 디스크 스케줄링 알고리즘별 장단점을 설명하세요.

✅

-   **FCFS**: 구현 단순, Overhead 적음 / 성능 최적화 부족
-   **SSTF**: 평균 응답시간 ↓, Throughput ↑ / Starvation 발생 가능
-   **SCAN**: SSTF 기아 완화 / 진행 방향 반대 요청 응답시간 ↑
-   **C-SCAN**: 응답시간 공평성 ↑ / 이동 비용 ↑
-   **LOOK / C-LOOK**: 불필요한 헤드 이동 감소, 효율 ↑

---

## Q6. SLTF(Shortest Latency Time First)와 SPTF(Shortest Positioning Time First)는 무엇인가요?

✅

-   **SLTF**: 회전 지연(Rotational Delay)을 최소화 → Sector-level 최적화
-   **SPTF**: Seek Time + Rotational Delay = Positioning Time 최소화
-   단점: 특정 영역의 요청이 기아(Starvation)에 빠질 수 있음

---

## Q7. RAID의 목적과 각 레벨 특징은?

✅

-   목적: **성능 향상 + 신뢰성 보장**
-   **RAID 0**: Striping, 성능↑ / 장애 시 전체 손실
-   **RAID 1**: Mirroring, 신뢰성↑ / 공간 낭비
-   **RAID 3**: Byte-level Striping + 패리티 디스크 / 패리티 병목
-   **RAID 4**: Block-level Striping + 패리티 디스크 / 병목 존재
-   **RAID 5**: Block-level Striping + 패리티 분산 / 가장 널리 사용됨

---

## Q8. RAID 2가 잘 안 쓰이는 이유는?

✅

-   해밍 코드 기반의 **비트 단위 에러 정정**을 사용
-   현대 디스크는 이미 자체 **ECC(Error Correction Code)** 내장 → RAID 2 불필요

---

## Q9. RAID 3과 RAID 4의 차이는?

✅

-   **RAID 3**: 바이트 단위 Striping → 모든 디스크가 동시에 작동해야 함
-   **RAID 4**: 블록 단위 Striping → 개별 블록 단위 접근 가능, 병렬성 ↑

---

## Q10. Disk Scheduling에서 SSTF 대신 SCAN/C-SCAN을 쓰는 이유는?

✅

-   SSTF는 기아(Starvation) 발생 가능 → 특정 요청이 무한정 대기
-   SCAN/C-SCAN은 **공평성(Fairness)** 제공 → starvation 방지

---

## Q11. Spooling의 어원은?

✅

-   **Simultaneous Peripheral Operation On-Line**
-   여러 작업을 동시에 I/O 장치에 **온라인으로 제출**한다는 의미

---

## Q12. Latency(레이턴시)란? (어원 포함)

✅

-   "지연 시간"을 뜻함
-   어원: 라틴어 _latens_ (“숨은, 숨어 있는”) → "잠복해 있다가 뒤늦게 나타남"
-   컴퓨터에서 Latency = 요청과 실제 응답 사이의 시간 지연
