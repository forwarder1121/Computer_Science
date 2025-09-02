# 📑 Virtual Memory Management – Interview QnA

## Q1. Virtual Memory 관리의 목적은 무엇인가요?

✅ 실제 메모리보다 큰 프로그램 실행을 가능하게 하고, **Page Fault를 최소화**하여 **시스템 성능 최적화**를 달성하는 것입니다.

---

## Q2. Page Fault는 왜 비용이 큰가요?

✅ Page Fault → 디스크 I/O + Context Switching + Kernel 개입 필요

-   디스크 접근은 메모리보다 수천 배 느림
-   따라서 **Page Fault Frequency (PFF)**, **Page Fault Rate**를 최소화하는 것이 중요합니다.

---

## Q3. HW 지원 장치에는 어떤 것들이 있나요?

✅

-   **TLB, Cache**: 주소 변환 및 접근 속도 개선
-   **Reference Bit**: 최근 참조 여부 추적 (지역성 활용)
-   **Dirty Bit(Update Bit)**: 페이지 수정 여부 → 스왑 아웃 시 Write-back 필요

---

## Q4. Allocation Strategies에는 어떤 방식들이 있나요?

✅

-   **Fixed Allocation**: 프로세스 실행 동안 고정된 page frame 수를 할당
-   **Variable Allocation**: 실행 중 동적으로 page frame 수를 조정

---

## Q5. Fetch Strategies는 무엇인가요?

✅

-   **Demand Paging**: 접근 시점에 적재 (현실적으로 대부분 OS 채택)
-   **Pre-paging**: 미래 참조를 예측하여 미리 적재 (비현실적)

---

## Q6. Replacement Algorithms 비교

-   **MIN**: 이론적 최적, 성능 평가 기준
-   **Random**: 최악 성능 기준
-   **FIFO**: 오래된 페이지 교체 → FIFO anomaly 발생 가능
-   **LRU**: 가장 오랫동안 참조되지 않은 페이지 교체 → Locality 기반, 가장 많이 활용
-   **LFU**: 참조 횟수가 가장 적은 페이지 교체 → 최근 참조된 페이지도 교체될 수 있음
-   **NUR**: Reference/Dirty bit 기반 → LRU 성능에 근접, Overhead 낮음
-   **Clock**: Reference bit 활용, FIFO + LRU 절충

---

## Q7. Variable Allocation 기반 기법에는 어떤 것이 있나요?

✅

-   **Working Set (WS)**: Δ(window size) 동안 자주 참조된 page 집합 유지 (Locality 반영)
-   **PFF (Page Fault Frequency)**: Page fault rate에 따라 frame 수를 동적으로 조정
-   **VMIN**: 미래 참조를 가정한 최적 (비현실적, 성능 비교용)

---

## Q8. Thrashing(스래싱)이란 무엇인가요?

✅ 과도한 Page Fault로 인해 **CPU가 I/O 대기**에 묶여버리고 성능이 급격히 저하되는 현상

-   원인: Over-loaded 상태에서 지나치게 많은 프로세스를 실행
-   해결: **Multiprogramming Degree 조절** → Plateau(고원) 영역 유지

---

## Q9. Page Size 선택은 어떻게 하나요? (기본 Trade-off)

✅

-   **크면**: 내부 단편화 ↑, TLB Reach ↑, I/O 전송 효율 ↑
-   **작으면**: 관리 오버헤드 ↑, Locality 활용 ↑
-   정답은 없고 시스템 특성에 따라 다름

---

## Q10. TLB Reach란 무엇인가요?

✅ TLB로 접근 가능한 메모리의 총량

-   향상 방법:

    -   TLB 크기 증가 (비용 ↑)
    -   Page Size 증가
    -   다양한 Page Size 지원

---

## Q11. Page Size는 현재 HW 발전 관점에서 어떻게 선택하는 게 좋나요?

✅ 최근 HW 발전에 따라 **CPU가 메모리보다 훨씬 빨라져 I/O bottleneck이 심각**해졌습니다.

-   이를 줄이기 위해 **Page Size를 크게** 하여 **디스크 I/O 횟수를 줄이고 전송 효율을 높이는 방향**으로 발전 중입니다.
-   즉, Locality 관리 부담은 커지더라도, **큰 Page Size 선호**가 최근 트렌드입니다.
