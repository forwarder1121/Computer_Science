# 🎤 Interview QnA — File & Storage

## Q1. 파일 시스템(File System)이란?

✅

-   보조기억장치(Disk)에 저장된 **정보들의 집합**을 관리하는 운영체제의 한 부분
-   사용자와 프로그램이 파일을 다루기 위한 **System Call** 제공
-   저장/검색/보호/구조화 역할 수행

---

## Q2. 파일 접근 방식(File Access Methods)에는 어떤 것이 있나요?

✅

-   **Sequential Access**: 순차적으로 읽기/쓰기 (테이프와 유사)
-   **Direct (Random) Access**: 임의의 블록 직접 접근 (디스크 기반)
-   **Indexed Access**: 인덱스를 통해 원하는 블록에 접근 (DBMS에서 활용)

---

## Q3. Directory 구조는 어떻게 발전했나요?

✅

1. Flat Directory: 단일 디렉토리, 충돌/혼잡 ↑
2. Two-Level: 사용자별 디렉토리 분리
3. Hierarchical (트리): 오늘날 표준, 계층적 관리 가능
4. Acyclic Graph: 링크 허용, 사이클 X
5. General Graph: 사이클 허용, 복잡성 ↑

---

## Q4. 파일 보호 기법에는 무엇이 있나요?

✅

-   **Password**: 단순하지만 비현실적 (파일마다 PW 필요)
-   **Access Matrix**: Domain ↔ Object 권한 매핑

    -   **Global Table**: 시스템 전체 테이블 (공간 비효율 ↑)
    -   **Access List**: Object 중심, 누가 접근 가능한지 기록 (접근 검사 ↑)
    -   **Capability List**: Domain 중심, 권한 증표(capability)를 소지 (관리 어려움)
    -   **Lock-Key Mechanism**: Object=Lock, Domain=Key (혼합형)

---

## Q5. 연속 할당(Contiguous Allocation) vs 비연속 할당(Non-contiguous Allocation)

✅

-   **연속 할당**

    -   파일이 디스크의 연속된 블록에 저장
    -   장점: 순차 접근 빠름
    -   단점: External Fragmentation, 크기 확장 어려움

-   **비연속 할당**

    -   Linked Allocation: 블록들을 Linked List로 연결 (External Fragmentation 없음, Direct Access 비효율)
    -   Indexed Allocation: Index Block으로 관리 (Direct Access 효율 ↑, Index Block 크기 제한 존재)

---

## Q6. Free Space Management 기법에는 어떤 것들이 있나요?

✅

-   **Bit Vector**: 블록 사용 여부를 비트맵으로 관리 (효율 ↑, 메모리 부담 ↑)
-   **Linked List**: Free Block 연결 (단순하지만 비효율 ↑)
-   **Grouping**: Free Block을 그룹 단위로 관리 (Linked List 단점 보완)
-   **Counting**: 연속된 Free Block의 시작 주소 + 개수 기록 (연속 할당에 적합)

---

## Q7. Access List와 Capability List의 차이는?

✅

-   **Access List**: Object 기준 (객체별 접근 권한 목록 유지 → "누가 접근 가능한가?")
-   **Capability List**: Domain 기준 (사용자가 가진 권한 증표 목록 유지 → "내가 어떤 권한을 가졌는가?")
-   실제 OS는 혼합 → **첫 접근 시 Access List 확인 → Capability 발급 → 마지막 접근 후 삭제**

---

## Q8. Disk Access Time을 구성하는 요소는?

✅

-   **Seek Time**: 헤드를 원하는 트랙으로 이동
-   **Rotational Delay**: 디스크 회전하여 원하는 섹터가 헤드 밑에 올 때까지 대기
-   **Data Transmission Time**: 실제 데이터 전송 시간
