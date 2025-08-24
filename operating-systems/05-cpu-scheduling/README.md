# 📘 Lecture 5. CPU Scheduling

> 운영체제 개요 5강 — 프로세스 스케줄링 개념과 알고리즘  

---

## 1. 프로세스 스케줄링 개요
- 현대 컴퓨터는 여러 프로세스를 동시에 실행한다.  
- 운영체제는 **CPU 및 자원 배분을 적절히 조율하는 스케줄링**을 수행한다.  

자원 관리 방식에는 두 가지가 있다:
1. **시간 분할(Time-sharing)**: CPU와 같은 자원을 **시간축으로 나눠** 여러 프로세스가 번갈아 사용  
   - CPU 스케줄링이 이에 해당  
2. **공간 분할(Space-sharing)**: 자원을 공간적으로 분할해 동시에 사용  
   - 메모리 분할이 대표적인 예시  

---

## 2. 스케줄링의 목적
- **시스템 성능 향상**이 핵심 목표  
- 성능 지표 (Index):
  - **응답 시간(Response Time)**  
  - **처리량(Throughput)**  
  - **자원 활용도(Utilization)**  
- 시스템 특성과 목적에 따라 적절한 지표를 기준으로 기법을 선택해야 한다.  

---

## 3. 스케줄링 기준
- **프로세스 특성**  
  - CPU-bound vs I/O-bound (CPU burst, I/O burst 비중)  
- **시스템 특성**  
  - Batch system, Interactive system, Real-time system 등  
- **프로세스 긴급성**  
  - 우선순위, deadline 등  

---

## 4. CPU/I/O Burst
- 프로세스 수행시간 = CPU 실행 시간 + I/O 대기 시간  
- CPU 사용시간이 큰 경우 → **CPU burst process**  
- I/O 대기시간이 큰 경우 → **I/O burst process**  
- 이 **burst 특성**은 스케줄링 알고리즘 설계에 중요한 기준이 된다.  

---

## 5. 스케줄링 단계
1. **Long-term scheduling (Job scheduling)**  
   - 어떤 Job을 시스템에 들일지 결정  
   - 시스템 내 프로세스 수를 제어  

2. **Mid-term scheduling (Memory allocation)**  
   - 메모리 사용량 관리, 프로세스 일시 중단/재개  

3. **Short-term scheduling (CPU scheduling)**  
   - Ready Queue에서 어떤 프로세스에 CPU를 줄지 결정  
   - **발생 빈도가 가장 높고 매우 빨라야 함**  
   - 우리가 배우는 스케줄링이 바로 여기에 해당  

---

## 6. 스케줄링 정책
- **Preemptive (선점형)**  
  - 실행 중인 프로세스를 중단하고 CPU를 다른 프로세스에 할당 가능  
- **Non-preemptive (비선점형)**  
  - 프로세스가 CPU를 스스로 반환할 때까지 실행  
- **Priority Scheduling**  
  - 프로세스의 중요도에 따라 CPU 할당  
  - **Static priority**: 우선순위 고정 → 구현 단순, 오버헤드 적음, 환경 변화 대응 어려움  
  - **Dynamic priority**: 실행 중 우선순위 변경 가능 → 복잡하지만 시스템 대응력 ↑  

---

## 7. 주요 스케줄링 알고리즘

### (1) FCFS (First Come First Served)
- 비선점형, 도착 순서대로 처리  
- 장점: 구현 단순, 스케줄링 오버헤드 없음 → CPU 활용도 ↑  
- 단점: Convoy Effect (긴 작업 때문에 짧은 작업 지연), 평균 응답시간 ↑  
- 적합: **Batch system**

---

### (2) RR (Round Robin)
- 선점형, 도착 순서대로 처리하되 **Time Quantum** 단위로 CPU 할당  
- 장점: 대화형 시스템 적합, 응답시간 개선  
- 특징: Time Quantum 값이 핵심 →  
  - 무한대면 FCFS와 동일  
  - 매우 작으면 병렬 실행과 유사  

---

### (3) SPN (Shortest Process Next)
- 비선점형, CPU Burst Time이 짧은 프로세스 먼저 실행  
- 장점: 평균 대기시간 최소화  
- 단점: 긴 프로세스는 Starvation 발생 가능, 실행시간 예측 필요  

---

### (4) SRTN (Shortest Remaining Time Next)
- SPN의 선점형 버전  
- 장점: 평균 대기시간 최소화 극대화  
- 단점: 실행시간 예측 필요, Context Switch 오버헤드 큼, 비현실적  

---

### (5) HRRN (Highest Response Ratio Next)
- SPN에 **Aging 개념** 도입 → 오래 기다린 프로세스 우선순위 ↑  
- 장점: Starvation 완화  
- 단점: 실행시간 예측 필요, 기다린 시간 계산 오버헤드 있음  

---

### (6) MLQ (Multi-Level Queue)
- 여러 종류의 프로세스를 **별도 Ready Queue**로 관리  
- Fixed Priority Preemptive Scheduling 사용  
- 단점: 큐 관리 오버헤드 ↑, 하위 큐는 Starvation 위험  

---

### (7) MFQ (Multi-Level Feedback Queue)
- MLQ + **Feedback** 개념 도입  
- 프로세스 특성에 따라 동적으로 우선순위 조정  
- 장점: 실행시간 예측 없이도 SPN/SRTN/HRRN 효과 유사  
- 단점: 큐 관리 오버헤드 ↑, Starvation 문제 (Aging 변형으로 해결)  
- 변형 기법:  
  - 큐마다 시간 할당량 다르게 배정  
  - I/O-bound 프로세스를 상위 큐로 이동  
  - 대기 시간이 길면 우선순위 ↑ (Aging)  

---

## 8. 리눅스의 Nice Value
- 리눅스는 **Priority Scheduling**에 기반  
- 프로세스는 `nice` 값으로 상대적 우선순위를 가짐  
  - 범위: `-20` (가장 높은 우선순위) ~ `+19` (가장 낮은 우선순위)  
- 기본값: `0`  
- 원리:  
  - `nice` 값이 낮을수록 CPU를 더 자주 할당받음  
  - `nice` 값이 높을수록 CPU를 양보 (백그라운드 작업 등에 사용)  
- 명령어 예시:  
  ```bash
  nice -n 10 ./myprogram     # 낮은 우선순위로 실행
  renice -n -5 -p 1234       # PID 1234 프로세스의 우선순위를 높임
````

---

## 9. 종합

* **공정성 중시**: FCFS, RR
* **효율성 중시**: SPN, SRTN, HRRN
* **현실적 대안**: MLQ, MFQ
* **리눅스**: Dynamic Priority 기반, nice value 활용

---

## 📒 참고

* 강의 영상: [Lec 5. CPU Scheduling](https://www.youtube.com/watch?v=EdTtGv9w2sA&list=PLBrGAFAIyf5rby7QylRc6JxU5lzQ9c4tN&index=8)

---

## ✍️ 강의 필기

* [05-cpu-scheduling-2025-08-24-1.jpeg](./notes/05-cpu-scheduling-2025-08-24-1.jpeg)
* [05-cpu-scheduling-2025-08-24-2.jpeg](./notes/05-cpu-scheduling-2025-08-24-2.jpeg)
* [05-cpu-scheduling-2025-08-24-3.jpeg](./notes/05-cpu-scheduling-2025-08-24-3.jpeg)
* [05-cpu-scheduling-2025-08-24-4.jpeg](./notes/05-cpu-scheduling-2025-08-24-4.jpeg)


