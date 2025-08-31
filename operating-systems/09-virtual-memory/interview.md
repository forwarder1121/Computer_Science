# 📑 Interview Q\&A — Non-Continuous Memory Allocation

## Q1. Continuous vs Non-continuous Allocation의 차이는 무엇인가요?

✅

-   **Continuous**: 프로세스를 하나의 연속된 메모리 공간에 배치

    -   장점: 단순, 주소 변환 비용 적음
    -   단점: **외부 단편화 발생**, 프로세스 크기가 메모리보다 크면 실행 불가

-   **Non-continuous**: 프로세스를 여러 블록(Page/Segment)으로 나누어 배치

    -   장점: 물리 메모리보다 큰 프로그램도 실행 가능 (**Virtual Memory**)
    -   단점: 주소 변환 필요 → 오버헤드 발생

---

## Q2. Non-continuous Allocation이 Virtual Memory와 어떤 관계가 있나요?

✅

-   Virtual Memory는 “물리 메모리보다 큰 주소 공간을 사용하는 개념”
-   이를 구현하기 위한 대표 기법이 **Paging, Segmentation** → Non-continuous Allocation
-   즉, **Virtual Memory = 개념**, **Non-continuous Allocation = 구현 방법**

---

## Q3. Paging System의 장단점은 무엇인가요?

✅

-   장점: External Fragmentation 없음, 메모리 관리 단순
-   단점: Internal Fragmentation 존재, 논리적 구조 반영 어려움 (sharing/protection 복잡)

---

## Q4. Segmentation System의 장단점은 무엇인가요?

✅

-   장점: 프로그램 논리 구조 반영, Sharing/Protection 용이, Internal Fragmentation 없음
-   단점: External Fragmentation 발생 가능, Address Mapping 오버헤드 큼

---

## Q5. Paging과 Segmentation을 혼합하는 이유는 무엇인가요?

✅

-   Paging은 관리가 단순하지만 프로그램 논리 구조 반영이 어렵다.
-   Segmentation은 논리 구조 반영이 쉽지만 External Fragmentation 발생 가능.
-   Hybrid 방식: **논리적으로 Segment → 내부적으로 Page로 관리**

    -   장점: Sharing/Protection 용이 + External Fragmentation 제거
    -   단점: 테이블 수 많고, 주소 변환 단계 복잡

---

## Q6. Address Mapping에서 TLB의 역할은 무엇인가요?

✅

-   PMT(Page Map Table)는 메모리에 저장되어 있어 접근 시 2번 메모리 접근 필요
-   TLB는 **최근 사용된 Page Table Entry를 캐싱**하여 병렬 탐색 → 메모리 접근 비용 감소
-   단점: 하드웨어 비용이 비쌈, 용량 제한적

---

## Q7. Paging에서 Page Fault가 발생하면 어떤 일이 일어나나요?

✅

1. Residence Bit = 0 확인
2. **Page Fault 발생** → OS가 디스크 I/O 요청
3. 필요한 페이지를 **Swap Device → 메모리 Page Frame**으로 로드
4. PMT 갱신 후 프로세스 재시작
5. Context Switching + Disk I/O로 인해 매우 큰 오버헤드

---

## Q8. Segmentation에서 발생할 수 있는 오류는 무엇이 있나요?

✅

-   **Segment Fault**: 존재 비트 0 → 세그먼트 없음
-   **Segment Overflow**: Displacement > Segment Limit
-   **Segment Protection Fault**: 허용되지 않은 연산(쓰기/실행 등) 수행
