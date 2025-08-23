# 📘 Lecture 4. Thread Management

> 운영체제 개요 4강 — 스레드의 개념과 관리  

---

## 1. 스레드(Thread)의 정의
- 스레드는 **프로세스 내에서 실행되는 독립적인 흐름**  
- 프로세스는 자원의 할당 + 제어 단위, 스레드는 **제어 단위**만 담당  
- 스레드는 흔히 **Light-weight Process (LWP)** 라고 불린다.  

---

## 2. 스레드의 필요성
- 프로세스는 자원을 공유하지 않기 때문에 Context Switching 비용이 크다.  
- 스레드는 프로세스 자원을 공유하므로 Context Switching이 가볍다.  
- 결과적으로:
  - 자원 사용 효율 ↑
  - 사용자 응답성 ↑  
  (예: 게임 실행 중 마우스 입력으로 I/O Block이 발생해도 다른 스레드가 계속 실행 가능)

---

## 3. 스레드 구조
- **공유하는 것 (프로세스 단위)**  
  - 코드, 데이터, 힙(주소 공간)  
  - 열린 파일, 전역 변수 등  

- **개별적으로 가지는 것 (스레드 단위)**  
  - 스택 영역 (함수 호출 기록, 지역 변수)  
  - 스택 포인터, 프로그램 카운터, 레지스터  

➡️ 따라서 Context Switch 시, **주소 공간 전체를 교체하지 않고** 제어요소만 교환하면 된다.

---

## 4. 스레드 구현 방식
### (1) 사용자 수준 스레드 (User-Level Thread, ULT)
- 라이브러리/런타임 레벨에서 스케줄링
- 장점: Context Switch 빠름 (커널 관여 없음)
- 단점: 커널은 스레드 존재를 모르므로 병렬 실행 불가

### (2) 커널 수준 스레드 (Kernel-Level Thread, KLT)
- 커널이 직접 스레드 관리 및 스케줄링
- 장점: 멀티코어 활용 가능 → 진정한 병렬성
- 단점: Context Switching 비용 ↑ (커널 관여)

### (3) 하이브리드 모델 (M:N Thread)
- 사용자 스레드 N개 ↔ 커널 스레드 M개 매핑
- 장점: 두 방식 장점 결합
- 단점: 구현 복잡성 ↑

---

## 5. JVM 스레드
- 현대 JVM(HotSpot 등)은 **커널 수준 스레드**를 사용  
- 자바 스레드 1개 ↔ OS 네이티브 스레드 1개 (1:1 매핑)  
- 스케줄링은 운영체제 커널이 담당  

---

## 📒 참고
- 강의 영상: [Lec 4. Thread Management](https://www.youtube.com/watch?v=EdTtGv9w2sA&list=PLBrGAFAIyf5rby7QylRc6JxU5lzQ9c4tN&index=7)

---

## ✍️ 강의 필기
- [04-thread-management-2025-08-23-1.jpg](./notes/04-thread-management-2025-08-23-1.jpg)
