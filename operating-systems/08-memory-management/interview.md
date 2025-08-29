# 🎤 Interview QnA — Lecture 8. Memory Management (1)

운영체제 개요 8강 — 메모리 관리 (연속 할당 중심) 면접 예상 질문 정리

---

## Q1. 메모리 계층 구조와 관리 주체는?

✅

-   레지스터, 캐시 → HW가 관리
-   메인 메모리, 보조 기억장치 → OS가 관리 (I/O 병목 해소 목적)
-   데이터 단위:
    -   메인메모리 ↔ 보조기억장치: Block
    -   레지스터 ↔ 메인메모리: Word

---

## Q2. Address Binding이란 무엇인가요? 시점에 따라 어떻게 구분하나요?

✅

-   **정의**: 프로그램의 **논리 주소(Logical Address)** → 실제 **물리 주소(Physical Address)** 로 매핑하는 과정

-   구분:
    1. **Compile-time binding**: 컴파일 시 물리적 위치 확정 → 프로그램 전체 메모리에 올라가야 함
    2. **Load-time binding**: 상대 주소 기반, 적재 시점에 시작주소로 재설정
    3. **Run-time binding**: 실행 중에도 주소 변환, MMU(HW) 도움 필요 → 현대 OS의 일반적 방식

---

## Q3. Swapping이란 무엇인가요?

✅

-   메모리와 Swap Device 간에 프로세스를 교체하는 기법
-   프로세스 종료/대기 시 Swap-out, 다시 필요하면 Swap-in
-   목적: 메모리 활용률 증가

---

## Q4. Fixed Partition Multiprogramming (FPM)의 특징과 단점은?

✅

-   메모리를 고정된 크기의 파티션으로 나눔
-   각 프로세스는 하나의 파티션에만 적재 가능
-   Multiprogramming degree = Partition 개수
-   단점:
    -   **Internal Fragmentation (파티션 내부 낭비 공간 발생)**
    -   **External Fragmentation은 전통적 분류상 발생하지 않음**
        -   이유: 이미 파티션이 고정되어 있어서, “연속 공간 부족” 문제는 생기지 않음
        -   다만, 일부 문맥에서는 “작은 프로세스가 큰 파티션만 남아있으면 적재 불가 → 외부 단편화와 유사한 낭비”라고 설명하기도 함
        -   따라서 면접 답변 시 **Internal만 발생이 정석**, 단 “외부 단편화처럼 보일 수 있다”까지 언급하면 좋음

---

## Q5. Variable Partition Multiprogramming (VPM)의 특징과 단점은?

✅

-   메모리를 동적으로 분할하여 프로세스 할당
-   Internal Fragmentation 해소 가능
-   단점: **External Fragmentation (연속 공간 부족으로 할당 불가)**
-   해결책: Coalescing holes, Storage Compaction

---

## Q6. Placement Policy에는 어떤 것들이 있나요?

✅

1. **First-fit**: 처음 만나는 충분한 공간 (빠름, O(1), 활용률 낮음)
2. **Best-fit**: 가장 작은 충분 공간 (O(n), 작은 파티션 단편화 ↑)
3. **Worst-fit**: 가장 큰 공간 (O(n), 큰 파티션 확보 어려움)
4. **Next-fit**: First-fit 변형, 탐색 시작 위치를 계속 바꿔 균등 활용

---

## Q7. Internal Fragmentation과 External Fragmentation의 차이는?

✅

-   **Internal Fragmentation**: 파티션 내부에서 사용되지 못하는 낭비 공간
-   **External Fragmentation**: 전체 빈 공간 합은 충분하지만 연속되지 않아 프로세스 할당 불가

---

## 📝 요약

-   Address Binding: Compile / Load / Run-time
-   Swapping: 메모리 ↔ Swap Device 교체
-   Allocation: FPM(Internal만), VPM(External)
-   Placement Policy: First / Best / Worst / Next-fit
-   Fragmentation: Internal vs External
