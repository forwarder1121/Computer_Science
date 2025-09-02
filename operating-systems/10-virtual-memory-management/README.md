# 🗂️ Virtual Memory Management

가상 메모리 관리(Virtual Memory Management)는 실제 메모리보다 더 큰 메모리를 사용할 수 있도록 **swap device**를 두고, **비연속(non-continuous) 메모리 할당**을 활용하는 기법입니다.
이전 챕터에서 학습한 Paging / Segmentation 시스템 위에서, **실제 메모리 관리 전략**을 추가하여 **시스템 성능 최적화**를 목표로 합니다.

---

## 📌 성능 지표 (Performance Index)

-   **Page Fault** → 가장 핵심 지표 (디스크 I/O + Context Switching 발생 → 매우 비쌈)
-   **Page Fault Frequency (PFF)**, **Page Fault Rate** 를 통해 관리 정책을 평가

---

## ⚙️ 관리 구성요소

### ✅ HW 지원

-   **TLB, Cache** : 주소 변환 및 접근 성능 향상
-   **Bit Vectors**

    -   **Reference bit**: 참조되면 1, 주기적으로 0으로 초기화 (지역성 활용)
    -   **Dirty bit(Update bit)**: 페이지가 수정되었음을 표시 → 스왑 아웃 시 **Write-back** 필요

### ✅ SW 전략

1. **Allocation Strategies**

    - Fixed allocation: 프로세스에 고정된 수의 Page frame 할당
    - Variable allocation: 실행 도중 동적으로 Page frame 크기 조절

2. **Fetch Strategies**

    - Demand Paging: 접근 시점에 적재 (대부분의 OS가 사용)
    - Pre-paging: 미래 예측 기반 (비현실적)

3. **Placement Strategies**

    - 메모리에 어느 위치에 적재할지 결정 (First-fit, Best-fit, Worst-fit, Next-fit 등)

4. **Replacement Strategies**

    - 어떤 페이지를 교체할지 결정 (아래 상세 설명)

5. **Cleaning Strategies**

    - **Demand cleaning**: 스왑 아웃 시점에 Write-back
    - **Pre-cleaning**: 미리 Write-back (실제 OS에서는 Demand cleaning 사용)

6. **Load Control Strategies**

    - Multiprogramming degree 조절
    - Under-loaded → CPU 자원 낭비
    - Over-loaded → **Thrashing** (과도한 Page Fault 발생)
    - Plateau(고원) 영역 유지가 성능 최적

---

## 🔄 Replacement Strategies

모든 알고리즘은 **Locality**를 전제로 설계됨.

### 📍 Fixed Allocation 기반

-   **MIN**: 앞으로 가장 오랫동안 참조되지 않을 페이지 교체 (이론적 최적 → 성능 비교용)
-   **Random**: 무작위 교체 (최악 성능 기준)
-   **FIFO**: 가장 오래된 페이지 교체 → Locality 고려 부족 → FIFO anomaly 존재
-   **LRU**: 가장 오래 참조되지 않은 페이지 교체 → Locality 기반, 가장 많이 사용됨
-   **LFU**: 참조 횟수가 가장 적은 페이지 교체 → 최근 참조된 페이지도 교체될 수 있음
-   **NUR (Not Used Recently)**: Reference bit + Dirty bit 조합 (0,0 → 0,1 → 1,0 → 1,1 순 교체)
-   **Clock Algorithm**: 포인터를 회전하며 Reference bit 확인 → FIFO + LRU 절충

    -   변형: Second Chance Algorithm (Reference + Modify bit 고려)

### 📍 Variable Allocation 기반

-   **Working Set (WS) Algorithm**

    -   일정 시간(Δ, window size) 동안 참조된 페이지 집합 유지
    -   Locality 기반 but 관리 오버헤드 큼

-   **Page Fault Frequency (PFF) Algorithm**

    -   Page fault rate에 따라 Window size 동적으로 조절

-   **Variable MIN (VMIN)**

    -   미래 참조를 가정한 최적 알고리즘 (비현실적 → 비교 기준용)

---

## 📊 기타 고려사항

-   **Page Size**

    -   너무 크면 내부 단편화 증가, 너무 작으면 관리 오버헤드 증가
    -   최근 HW 발전에 따라 **큰 Page size** 선호 (I/O 병목 완화)

-   **Program Restructuring**

    -   VM 시스템의 특성을 고려하여 프로그램 구조를 재조정 (예: C 언어 2D 배열 접근 순서)

-   **TLB Reach**

    -   TLB로 접근 가능한 메모리 양
    -   TLB 크기를 늘리거나, **Page size 확대 / 다양한 Page size 지원**으로 보완

---

✍️ 느낀 점:
운영체제 기술은 “가정”을 점점 완화하면서 발전했고, 그 기반은 결국 **HW 발전**이 받쳐줬기 때문에 가능했습니다.
