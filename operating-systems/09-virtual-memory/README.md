# 📖 Non-Continuous Memory Allocation

메모리 할당 방식은 크게 **Continuous Allocation**과 **Non-Continuous Allocation**으로 나뉜다.

---

## 1️⃣ Continuous Memory Allocation

-   프로세스를 하나의 연속된 메모리 공간에 배치하는 방식
-   **단점**

    -   외부 단편화 발생
    -   프로세스 크기가 메모리보다 크면 실행 불가능

---

## 2️⃣ Non-Continuous Memory Allocation

-   **연속 공간에 배치해야 한다는 가정을 깨고**, 프로그램을 여러 Block 단위로 분할
-   필요한 Block만 메모리에 적재 → 나머지는 **Swap Device**에 저장
-   결과적으로 물리 메모리보다 큰 프로그램도 실행 가능 → **Virtual Memory** 개념

---

## 3️⃣ Address Mapping

-   **Continuous Allocation**: 상대주소를 기준으로 실제 메모리 주소로 평행 이동만 수행
-   **Non-Continuous Allocation**:

    -   프로세스는 여전히 "연속된 메모리"에 적재된다고 가정
    -   MMU가 **Virtual Address → Real Address** 변환 수행

### Block Mapping (Python 예시)

```python
def access_memory(virtual_address, BMT, swap_device):
    b, d = virtual_address  # (block number, displacement)

    entry = BMT[b]
    if entry['residence_bit'] == 0:
        # Page fault → Swap-in
        block_data = swap_device.load(b)
        memory_address = allocate_frame()
        BMT[b] = {'residence_bit': 1, 'real_address': memory_address}
        entry = BMT[b]

    # Real address 계산
    r = entry['real_address'] + d
    return read_from_memory(r)
```

---

## 4️⃣ Virtual Storage Methods

### (1) Paging System

-   프로그램을 **고정 크기 페이지**로 분할
-   메모리는 같은 크기의 **Page Frame**으로 관리
-   **특징**

    -   External Fragmentation 없음
    -   Internal Fragmentation 존재 (고정 크기라 남는 공간 발생)
    -   단순, 빠른 관리

-   **Address Mapping**

    -   Direct Mapping
    -   Associative Mapping (TLB)
    -   Hybrid

-   **자료구조**: PMT (Page Map Table)

---

### (2) Segmentation System

-   프로그램을 **논리적 단위(가변 크기 Segment)** 로 분할
-   **특징**

    -   Internal Fragmentation 없음
    -   External Fragmentation 발생 가능
    -   Sharing/Protection 용이

-   **자료구조**: SMT (Segment Map Table)
-   **Address Mapping (Python 예시)**

```python
def segment_address_mapping(virtual_address, SMT):
    s, d = virtual_address  # (segment number, displacement)
    entry = SMT[s]

    if entry['residence_bit'] == 0:
        raise Exception("Segment fault")

    if d > entry['limit']:
        raise Exception("Segment overflow")

    if not entry['protection']:
        raise Exception("Segment protection fault")

    real_address = entry['base'] + d
    return read_from_memory(real_address)
```

---

### (3) Paging + Segmentation Hybrid

-   **Segmentation → Page 단위 분할**
-   **Address** = (segment number, page number, displacement)
-   **특징**

    -   Sharing/Protection 용이
    -   관리 오버헤드 감소
    -   단점: 테이블 수 많음, Address Mapping 복잡 (메모리 접근 3번)

---

## 📝 결론

-   **기술 발전 흐름**: 연속 메모리 → 비연속 (Paging/Segmentation) → Hybrid
-   **배경**: HW 발전이 SW(운영체제) 가정을 완화시킴
-   **본질**: "연속된 메모리에 프로그램을 올려야 한다"는 가정을 깨는 것
