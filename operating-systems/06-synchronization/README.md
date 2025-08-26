# 📘 Lecture 6. Process Synchronization & Mutual Exclusion

> 운영체제 개요 6강 — 동기화(Synchronization)와 상호배제(Mutual Exclusion)

---

## 1. 배경

-   현대 시스템은 **다중 프로그래밍** 환경을 사용한다.
-   여러 프로세스가 **동시에, 독립적으로 실행**되며 공유 자원에 접근 → 충돌 가능성 존재
-   따라서 **프로세스 간 동기화(Synchronization)** 가 필요하다.

---

## 2. 공유 데이터와 Critical Section

-   공유 자원(Shared Resource)에 접근하는 데이터를 **Critical Data**라고 한다.
-   이를 접근하는 코드 영역을 **Critical Section (CS)** 이라 함
-   문제점: 두 개 이상의 프로세스가 동시에 Critical Section에 진입 → **Race Condition** 발생

➡️ **Mutual Exclusion (상호배제)** 필요: 동시에 둘 이상의 프로세스가 CS에 진입하지 못하게 하는 것

---

## 3. Mutual Exclusion 조건 (3대 원칙)

1. **Mutual Exclusion**
    - 한 프로세스가 CS에 들어가면 다른 프로세스는 들어갈 수 없음
2. **Progress**
    - CS 안에 없는 프로세스는 다른 프로세스의 CS 진입을 방해해서는 안 됨
3. **Bounded Waiting**
    - 어떤 프로세스도 무한정 기다리지 않음 (언젠가는 CS에 들어갈 수 있어야 함)

---

## 4. Mutual Exclusion Solutions

Mutual Exclusion을 구현하는 방법은 크게 네 가지로 나눌 수 있다:

1. **Software-based Solution**
2. **Hardware-based Solution**
3. **OS-supported Solution**
4. **Language-level Solution**

---

### 4.1 Software-based Solution

-   대표 알고리즘: **Dekker’s, Peterson’s, Dijkstra’s Algorithm**
-   특징:
    -   순수 소프트웨어로 구현 가능
    -   구현 복잡, 속도 느림
    -   가장 큰 단점: **Busy Waiting (CPU 낭비)**

---

### 4.2 Hardware-based Solution

-   CPU가 제공하는 **Atomic Instruction** 이용
    -   ex) Test-and-Set, Swap
-   장점: 소프트웨어보다 단순
-   단점: 여전히 **Busy Waiting 존재**

---

### 4.3 OS-supported Solution

운영체제가 제공하는 동기화 도구

#### (1) Spinlock

-   정수 변수 `S`와 두 연산 `P(), V()` 로 구현
-   `P(S)`: 자원 획득, `V(S)`: 자원 반환
-   OS가 보장하는 atomic operation으로 실행됨
-   단점: **Busy Waiting 존재**

#### (2) Semaphore

-   음이 아닌 정수 변수, 초기화 연산 + `P(), V()`만 허용
-   **Busy Waiting 제거** → 대기 중인 프로세스를 **Blocked Queue**에 넣고, 필요 시 Wake-up
-   활용: Mutual Exclusion, Process Synchronization, Producer-Consumer, Reader-Writer, Dining Philosopher 등
-   단점: **Queue에서 깨우는 순서가 비결정적 → Starvation 발생 가능**

#### (3) Eventcount / Sequencer

-   **Sequencer**
    -   정수 변수, 0으로 초기화, 감소 불가
    -   `ticket()` 연산으로 atomic하게 순서 보장
-   **Eventcount**
    -   정수 변수, 사건 발생 횟수 기록
    -   연산:
        -   `read(E)`: 현재 값 반환
        -   `advance(E)`: `E += 1`, 대기 프로세스 깨움
        -   `await(E, v)`: `E < v`이면 큐에 넣고 Block → Wake-up 시까지 대기
-   장점: **공정성 보장, Busy Waiting 없음**

---

### 4.4 Language-level Solution

-   **Monitor**
    -   공유 데이터 + Critical Section 집합
    -   접근은 언어 차원에서 제공 → 컴파일러가 CS 접근 코드 생성
    -   조건 변수(Condition Variable): `wait()`, `signal()` 사용
-   장점: 사용 편리, 코드 직관적
-   단점: 언어 지원 필요 (예: Java synchronized, C++ monitor class)

---

## 5. Busy Waiting vs Blocking

-   **Busy Waiting**: CPU를 계속 사용하며 대기 (Spinlock, HW 솔루션 등)
-   **Blocking**: 프로세스를 대기 큐에 넣고 CPU를 다른 프로세스에게 양도 (Semaphore, Eventcount 등)

---

## 6. 요약

-   동기화 문제는 다중 프로그래밍 환경에서 필연적으로 발생
-   Mutual Exclusion 조건 3가지 (ME, Progress, Bounded Waiting) 충족 필요
-   다양한 솔루션 존재:
    -   **SW 기반**: 구현 복잡, Busy Waiting 문제
    -   **HW 기반**: Atomic Instruction 제공, 여전히 Busy Waiting 존재
    -   **OS 지원**: Spinlock(단순), Semaphore(Blocking), Eventcount/Sequencer(공정성)
    -   **Language-level**: Monitor (언어 차원 지원)

---

## 📒 참고

-   강의 영상: [Lec 6. Process Synchronization & Mutual Exclusion](https://www.youtube.com/watch?v=EdTtGv9w2sA&list=PLBrGAFAIyf5rby7QylRc6JxU5lzQ9c4tN&index=12)

---

## ✍️ 강의 필기

## ✍️ 강의 필기

-   [06-synchronization-2025-08-26-1.jpeg](./notes/06-synchronization-2025-08-26-1.jpeg)
-   [06-synchronization-2025-08-26-2.jpeg](./notes/06-synchronization-2025-08-26-2.jpeg)
