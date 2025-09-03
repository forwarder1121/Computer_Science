# 📂 파일 & 저장장치 (File & Storage)

운영체제는 **보조기억장치(Disk)** 를 기반으로 파일을 관리합니다.
이 장에서는 **Disk System → File System → Directory → Protection → Implementation → Free Space Management** 의 흐름으로 다룹니다.

---

## 🔹 Disk System

-   **구성 요소**

    -   Disk Pack: 데이터를 영구 저장 (sector, track, cylinder, platter, surface 단위)
    -   Disk Drive: Disk Pack을 제어 (head, arm, positioner, spindle)

-   **주소**

    -   물리 주소: (cylinder, surface, sector)
    -   논리 주소 → 물리 주소 변환은 Disk Controller가 수행

-   **OS 관점**

    -   디스크 전체를 **Block들의 나열**로 취급

-   **접근 시간**

    -   Access Time = Seek Time + Rotational Delay + Data Transmission Time

---

## 🔹 File System

-   **정의**: 보조기억장치에 저장된 **연관된 정보들의 집합**
-   **역할**: 사용자와 프로그램이 파일을 다룰 수 있도록 System Call 제공
-   **File Access Methods**

    -   Sequential Access
    -   Direct (Random) Access
    -   Indexed Access

---

## 🔹 Directory Structure

-   Flat Directory (단일 레벨)
-   Two-Level Directory (사용자별 디렉토리 분리)
-   Hierarchical Directory (트리 구조, 오늘날 기본)
-   Acyclic Graph Directory (링크 가능, 사이클 없음)
-   General Graph Directory (사이클 허용, 복잡성 ↑)

---

## 🔹 File Protection

-   파일은 접근 권한 보호 필요
-   **보호 기법**

    1. **Password** 방식 → 비현실적 (모든 파일에 PW 필요)
    2. **Access Matrix** (Domain ↔ Object 권한 매핑)

        - 구현 방식:

            - **Global Table**: 단순하지만 크기 커짐
            - **Access List**: Object 기준, 접근자와 권한 기록 (object 중심)
            - **Capability List**: Domain 기준, 권한 증표(capability) 부여 (사용자/프로세스 중심)
            - **Lock-Key Mechanism**: Object=Lock, Domain=Key (혼합형)

-   실제 OS → Access List로 1차 확인 후 Capability 발급 → 마지막 접근 종료 시 삭제

---

## 🔹 File System Implementation

-   **연속 할당 (Contiguous Allocation)**

    -   파일을 연속된 Block에 저장
    -   장점: 순차 접근 효율 ↑
    -   단점: External Fragmentation, 크기 확장 어려움

-   **불연속 할당 (Non-contiguous Allocation)**

    1. **Linked Allocation**

        - 블록들을 Linked List로 연결
        - 장점: External Fragmentation X
        - 단점: Direct Access 비효율, Pointer 저장 필요, 신뢰성 ↓

    2. **Indexed Allocation**

        - 파일 블록 정보를 Index Block에 모음
        - 장점: Direct Access 효율 ↑
        - 단점: Index Block 유지 Overhead, Index 크기에 따른 파일 크기 제한

---

## 🔹 Free Space Management

-   **Bit Vector**: 블록 사용 여부를 비트맵으로 기록 (효율 ↑, 단점: 메모리에 전체 유지 필요)
-   **Linked List**: Free Block들을 리스트로 연결 (비효율 ↑)
-   **Grouping**: n개의 Free Block을 묶고, 그룹 단위로 리스트 연결 (Linked List 단점 보완)
-   **Counting**: 연속된 Free Block의 시작 주소 + 개수 기록 (연속 할당에 유리)
