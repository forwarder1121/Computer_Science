# 🎤 Interview QnA — Lecture 6. Process Synchronization & Mutual Exclusion

운영체제 개요 6강 — 프로세스 동기화 & 상호배제 면접 예상 질문 정리

---

## Q1. Critical Section 문제에서 충족해야 할 조건 3가지는?

✅

1. **Mutual Exclusion**: 한 프로세스가 Critical Section(CS)에 있으면 다른 프로세스는 들어갈 수 없음
2. **Progress**: CS 안에 없는 프로세스는 다른 프로세스의 CS 진입을 방해하지 않아야 함
3. **Bounded Waiting**: 무한정 기다리지 않고 유한 시간 내에 CS에 진입 가능해야 함

---

## Q2. Busy Waiting은 왜 문제인가요?

✅

-   Busy Waiting = 프로세스가 CPU를 계속 사용하면서 조건 충족 여부를 확인하는 대기 방식
-   단점:
    -   CPU 자원 낭비
    -   다른 프로세스가 실행될 기회를 박탈 → 시스템 효율성 저하
-   Spinlock, HW 솔루션(Test-and-Set 등)은 Busy Waiting 기반 + SW 솔루션도.

---

## Q3. Semaphore의 장점과 단점은 무엇인가요?

✅

-   **장점**:
    -   Busy Waiting 제거 (대기 프로세스를 Queue에 넣고 Block → Wake-up)
    -   Mutual Exclusion + Synchronization 문제 해결 가능
-   **단점**:
    -   P(), V() 호출 순서/위치 오류 시 Deadlock 가능
    -   Wake-up 순서가 비결정적 → **Starvation 발생 가능**
    -   코드 가독성 ↓, 관리 어려움

---

## Q4. Eventcount/Sequencer는 왜 등장했나요?

✅

-   Semaphore의 비결정적 Wake-up 문제(Starvation)를 해결하기 위해 등장
-   **Sequencer**: 순서를 보장하는 티켓 발급 방식 (은행 번호표와 유사)
-   **Eventcount**: 사건 발생 횟수를 기록, 특정 시점까지 대기 → 공정성 ↑, Busy Waiting 없음

---

## Q5. Monitor란 무엇인가요? 장단점은?

✅

-   **정의**: 공유 데이터 + Critical Section을 언어 수준에서 관리하는 추상화 기법
-   **조건 변수(Condition Variable)** 사용: `wait()`, `signal()`
-   **장점**:
    -   코드 직관적, 사용 편리
    -   언어 차원 지원으로 오류 가능성 ↓
-   **단점**:
    -   언어 지원 필요 (예: Java `synchronized`, C++ Monitor class)
    -   컴파일러가 OS 동작을 이해하고 있어야 함

---

## Q6. Race Condition이란 무엇인가요?

✅

-   둘 이상의 프로세스가 공유 자원에 동시에 접근할 때, 실행 순서에 따라 결과가 달라지는 상황
-   예: 은행 계좌 입출금, 변수 증가/감소 연산
-   해결책: Mutual Exclusion 보장 (Lock, Semaphore, Monitor 등)

---

## Q7. Spinlock은 언제 유용한가요?

✅

-   Busy Waiting 방식이라 일반적으로 비효율적
-   하지만 **Context Switch 비용이 Busy Waiting보다 더 큰 경우 (짧은 대기)** → Spinlock이 유리
-   ex) 커널 내부 짧은 Critical Section 보호

---

## 📝 요약

-   Critical Section 문제: ME, Progress, Bounded Waiting 충족 필요
-   Busy Waiting: CPU 낭비 → Blocking 기법으로 해결
-   Semaphore: 범용적이나 Starvation 가능, 코드 복잡
-   Eventcount/Sequencer: 순서 보장, 공정성 ↑
-   Monitor: 언어 차원 지원, 직관적이지만 언어 종속적
-   Spinlock: 짧은 대기 상황에서만 유용
