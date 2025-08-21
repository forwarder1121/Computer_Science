# 📘 Lecture 3. Process Management

> 운영체제 개요 3강 — 프로세스의 개념과 관리

---

## 1. 프로세스(Process)란?

-   운영체제는 **프로세스를 관리**한다.
-   **Job**: 실행 요청 전의 프로그램 + 데이터 상태 (디스크에 존재)
-   실행 요청 시 → 커널에 의해 등록 및 관리되는 **Process**가 됨
-   프로세스는 **PCB(Process Control Block)** 로 관리됨
    -   프로세스의 메타데이터(프로세스 ID, 상태, 메모리 정보 등) 저장
    -   PCB는 **커널 공간(Kernel Space)** 에 저장
    -   PCB의 상세 항목은 OS(커널)마다 조금씩 다름

---

## 2. 프로세스 상태 (Process States)

프로세스는 실행 중 다양한 상태로 전이한다.

-   **Created**: 생성됨
-   **Ready**: 실행 준비 완료 (메모리와 CPU 외 자원 준비됨)
-   **Suspended Ready**: 메모리 부족으로 대기
-   **Running**: CPU가 할당되어 실행 중
-   **Blocked**: I/O 등 다른 자원 대기
-   **Suspended Blocked**: 메모리 부족으로 차단된 상태
-   **Terminated**: 수행 완료, PCB만 남음

### 상태 전이

-   Ready → CPU 할당 → Running
-   Running → I/O 요청 → Blocked
-   Blocked → 자원 획득 → Ready (바로 Running이 아님: 이미 CPU 점유 프로세스가 있기 때문)
-   Running → 수행 종료 → Terminated

➡️ Ready Queue, Blocked Queue 등 큐(queue) 구조로 관리되며, Blocked Queue는 자원 종류별로 따로 존재

---

## 3. 인터럽트 (Interrupt)

-   실행 중 **예상치 못한 상황** 발생 시, CPU 제어권이 커널로 넘어감
-   커널이 수행하는 동작:
    1. 인터럽트 원인 확인
    2. 서비스 필요 여부 결정
    3. **ISR (Interrupt Service Routine)** 실행

---

## 4. 컨텍스트 스위칭 (Context Switching)

-   Running 프로세스가 **선점(preemption)** 당하면 CPU를 잃게 됨
-   CPU 내 **레지스터 상태(register context)** 를 PCB에 저장
-   다시 Running 상태가 될 때 PCB에서 복구
-   컨텍스트 스위칭은 **필연적 오버헤드**를 발생시킴

### 해결책: 스레드(Thread)

-   프로세스보다 가벼운 실행 단위
-   자원 공유로 문맥 교환 부담이 줄어 효율적

---

## 📒 참고

-   강의 영상: [Lec 3. Process Management](https://www.youtube.com/watch?v=EdTtGv9w2sA&list=PLBrGAFAIyf5rby7QylRc6JxU5lzQ9c4tN&index=5)

---

## ✍️ 강의 필기

-   [03-process-management-2025-08-22-1.jpg](./notes/03-process-management-2025-08-22-1.jpg)
