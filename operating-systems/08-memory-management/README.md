# 💾 Lecture 8. Memory Management

---

## 1. 메모리 계층 구조

-   종류: **레지스터 → 캐시 → 메인 메모리 → 보조 기억장치**
-   관리 주체:
    -   레지스터, 캐시 → HW 관리
    -   메인 메모리, 보조 기억장치 → OS 관리 (I/O 병목 해소 목적)
-   데이터 단위:
    -   메인 메모리 ↔ 보조기억장치: **Block**
    -   레지스터 ↔ 메인 메모리: **Word**
    -   운영체제 bit 수(32bit/64bit)는 word 단위 크기 의미

---

## 2. 주소(Address)와 Address Binding

-   **Logical Address**: 프로그램 상의 주소 (예: `int a;` 선언한 변수 a의 주소)
-   **Physical Address**: 실제 메모리 번지

### Address Binding 종류

1. **Compile-time binding**
    - 적재 위치를 컴파일러가 알고 있음 → 프로그램 전체 메모리에 올라가야 함
2. **Load-time binding**
    - 상대 주소 사용 → 적재 시점에 시작주소로 재설정 (Address Mapping)
    - 단점: 프로그램 전체가 메모리에 올라가야 함
3. **Run-time binding**
    - 실행 도중에도 주소 매핑 가능 → HW(MMU)의 도움 필요
    - 대부분의 현대 OS에서 사용
    - **Dynamic loading**: 필요한 함수만 디스크 → 메모리로 로드

---

## 3. Swapping

-   프로세스 실행 완료/대기 시 **메모리를 Swap Device와 교체 (swap-in/out)**
-   목적: 메모리 활용률 증대

---

## 4. 메모리 할당 (Memory Allocation)

### 4.1 연속 메모리 할당 (Continuous Allocation)

-   하나의 프로세스를 **연속된 메모리 공간**에 배치하는 정책
-   고려 요소: 동시에 올라가는 프로세스 수, 메모리 분할 방식

#### (1) Fixed Partition Multiprogramming (FPM)

-   메모리를 **고정된 크기의 파티션**으로 나눔
-   프로세스는 오직 하나의 파티션에만 적재 가능
-   Multiprogramming degree = Partition 개수
-   커널/사용자 영역 보호: **Boundary Register** 사용
-   단점: **Internal Fragmentation** 발생 (파티션 내부의 낭비 공간)

#### (2) Variable Partition Multiprogramming (VPM)

-   프로세스를 배치할 때마다 메모리를 **동적으로 분할**
-   장점: Internal Fragmentation 해소
-   단점: **External Fragmentation** 발생
    -   Coalescing holes: 인접한 빈 공간 병합
    -   Storage compaction: 메모리 조각 모아 압축

---

## 5. 배치 전략 (Placement Policy)

-   **First-fit**: 처음 만나는 충분한 공간 할당 (O(1), 빠르지만 공간 활용률 낮음)
-   **Best-fit**: 가장 작은 충분 공간 선택 (O(n), 작은 파티션 단편화 ↑)
-   **Worst-fit**: 가장 큰 공간 선택 (O(n), 큰 파티션 확보 어려움)
-   **Next-fit**: First-fit 변형, 탐색 시작 위치를 계속 변경 → 균등 활용

---

## 6. 단편화(Fragmentation)

-   **Internal Fragmentation**: 파티션 내부에서 낭비되는 공간
-   **External Fragmentation**: 전체 빈 공간은 충분하지만 연속 공간 부족으로 할당 불가

---

## 📝 요약

-   메모리 계층: 레지스터 ↔ 캐시 ↔ 메인 메모리 ↔ 보조 기억장치
-   Address Binding: Compile-time / Load-time / Run-time (MMU)
-   Swapping: 메모리 ↔ Swap Device 교체
-   Allocation:
    -   FPM: 단순, Internal Fragmentation 문제
    -   VPM: 동적, External Fragmentation 문제 (해결: Coalescing, Compaction)
-   Placement Policy: First / Best / Worst / Next-fit
