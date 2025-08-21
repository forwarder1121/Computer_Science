# 📘 Lecture 2. OS Overview

> 운영체제 개요 — OS의 기능, 발전 과정, 구조

---

## 운영체제(OS)의 주된 기능

-   운영체제의 핵심 역할은 **하드웨어(HW)와 소프트웨어(SW)를 관리**하는 것
-   OS는 크게 **커널(Kernel)** 과 **유틸리티(Utility)** 로 구분됨
    -   **커널**: 하드웨어 제어, 자원 관리 담당
    -   **유틸리티**: 사용자 편의를 위한 다양한 기능 제공
-   커널에 직접 접근을 막기 위해 **System Call Interface** 제공  
    → 사용자 프로그램이 하드웨어를 직접 제어하지 못하게 하고, OS를 통해서만 접근 가능

---

## 작업 수행 방식의 발전 (스토리 라인)

운영체제는 **작업 처리 방식의 한계와 요구**에 따라 발전해왔다.

1. **순차 처리 (Sequential Processing)**

    - 초기: 천공카드를 이용, 환경을 수동으로 계속 바꿔야 함
    - 동일 언어(C, Python, Java 등) 작업을 모아서 실행

2. **배치 처리 (Batch Processing)**

    - 여러 작업을 한 번에 모아 처리
    - 단점: 응답 시간이 느림

3. **시분할 처리 (Time-Sharing System)**

    - 여러 사용자가 터미널을 통해 서버에 접속 → 응답성이 크게 향상
    - 단점: 통신 비용 증가

4. **개인용 컴퓨터 (PC)**

    - 개인 사용 가능, 즉각적인 응답
    - 단점: 당시 성능이 낮음

5. **병렬 처리 시스템 (Parallel System)**

    - 여러 CPU가 동시에 작업 수행
    - 단점: 하드웨어에 종속적

6. **분산 처리 시스템 (Distributed System)**
    - 네트워크로 연결된 여러 컴퓨터가 하나의 시스템처럼 동작
    - 확장성과 유연성이 강화됨

👉 기술 발전의 핵심: **"왜" 필요했는가를 이해하는 것**이 중요하다.

---

## 운영체제의 구조

운영체제 구조는 **성능 ↔ 유지보수성** 사이의 균형을 맞추며 발전했다.

1. **단일 구조 (Monolithic Kernel)**

    - 초기 OS는 모든 기능을 커널 내부에 포함
    - 단점: 커널 크기 비대 → 유지보수 어려움

2. **계층 구조 (Layered Kernel)**

    - OS 기능을 여러 계층으로 나누어 구현 (OSI 7계층과 유사한 발상)
    - 단점: 계층 간 호출 비용이 커져 성능 저하

3. **마이크로 커널 (Microkernel)**
    - 최소한의 핵심 기능만 커널에 포함 (스케줄링, IPC 등)
    - 나머지는 사용자 공간에서 실행
    - 장점: 모듈화·유지보수성 향상
    - 단점: 성능 손해 가능

---

## 📒 참고

-   강의 영상
    -   [Lec 2. OS Overview (1/3)](https://www.youtube.com/watch?v=EdTtGv9w2sA&list=PLBrGAFAIyf5rby7QylRc6JxU5lzQ9c4tN&index=2)
    -   [Lec 2. OS Overview (2/3)](https://www.youtube.com/watch?v=EdTtGv9w2sA&list=PLBrGAFAIyf5rby7QylRc6JxU5lzQ9c4tN&index=3)
    -   [Lec 2. OS Overview (3/3)](https://www.youtube.com/watch?v=EdTtGv9w2sA&list=PLBrGAFAIyf5rby7QylRc6JxU5lzQ9c4tN&index=4)

## ✍️ 강의 필기

-   [02-os-overview-2025-08-21-1.jpg](./notes/02-os-overview-2025-08-21-1.jpg)
-   [02-os-overview-2025-08-21-2.jpg](./notes/02-os-overview-2025-08-21-2.jpg)
