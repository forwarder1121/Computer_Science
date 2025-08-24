# 🎤 Interview QnA — Lecture 5. CPU Scheduling

운영체제 개요 5강에서 다룬 CPU 스케줄링 관련 면접 예상 질문 정리

---

## Q1. Preemptive Scheduling과 Non-preemptive Scheduling의 차이는?
✅  
- **Preemptive (선점형)**  
  - 실행 중인 프로세스가 있더라도 커널이 CPU를 강제로 회수해 다른 프로세스에 할당 가능  
  - **장점**: 응답 시간 개선, 긴급 작업 처리 가능, 공정성 ↑  
  - **단점**: Context Switch 오버헤드 ↑, 구현 복잡  

- **Non-preemptive (비선점형)**  
  - 프로세스가 CPU를 스스로 반환할 때까지 실행  
  - **장점**: 구현 단순, Context Switch 오버헤드 ↓  
  - **단점**: 평균 응답시간 ↑, 우선순위 역전(Priority Inversion) 가능  

---

## Q2. 고정 우선순위(Static Priority)와 동적 우선순위(Dynamic Priority)의 장단점은?
✅  
- **Static Priority**  
  - 프로세스 생성 시 우선순위를 고정  
  - **장점**: 구현 단순, 관리 오버헤드 ↓  
  - **단점**: 시스템 환경 변화 반영 불가, 장기 대기 프로세스 발생 (Starvation)  

- **Dynamic Priority**  
  - 실행 시간, 대기 시간, 자원 사용 패턴 등에 따라 우선순위 변경  
  - **장점**: 적응력 ↑, Aging 기법으로 Starvation 완화 가능  
  - **단점**: 계산 및 관리 오버헤드 ↑, 구현 복잡  

---

## Q3. 왜 I/O-bound 프로세스와 CPU-bound 프로세스를 섞어 스케줄링해야 하나요?
✅  
- **I/O-bound**: CPU 사용은 짧고 I/O 대기시간이 김  
- **CPU-bound**: CPU를 오랫동안 점유, I/O 사용 적음  
- 한쪽만 있으면 자원이 놀게 됨 → CPU는 놀거나, I/O 장치가 놀거나  
- 두 유형을 섞어야 **CPU와 I/O 자원이 동시에 활용**되어 Throughput ↑, 응답성 ↑  

---

## Q4. 스케줄링에서 성능 지표(Performance Metrics)에는 어떤 것들이 있나요?
✅  
- **CPU Utilization (CPU 활용도)**: CPU가 놀지 않고 일하는 비율  
- **Throughput (처리량)**: 단위 시간당 완료된 작업 수  
- **Turnaround Time (소요 시간)**: 제출 → 완료까지의 총 시간  
- **Waiting Time (대기 시간)**: Ready Queue에서 기다린 총 시간  
- **Response Time (응답 시간)**: 요청 제출 후 첫 응답까지의 시간  
- 목적에 맞는 지표를 선택하는 것이 중요  

---

## Q5. Convoy Effect란 무엇인가요?
✅  
- 긴 CPU-bound 프로세스가 먼저 실행되면, 뒤에 있는 짧은 프로세스들이 오래 기다려야 하는 현상  
- 대표적으로 FCFS에서 발생  
- **해결책**: SPN, SRTN, RR 등의 기법 적용  

---

## Q6. Round Robin에서 Time Quantum은 무엇이고, 크기에 따라 어떤 영향이 있나요?
✅  
- **Time Quantum** = 한 프로세스가 CPU를 점유할 수 있는 최대 시간 단위  
- 너무 크면 → FCFS와 동일 (응답성 ↓)  
- 너무 작으면 → Context Switch 빈번 (오버헤드 ↑)  
- 적절한 Time Quantum 선택이 핵심  

---

## Q7. Starvation 문제는 왜 발생하며, 해결 방법은 무엇인가요?
✅  
- 낮은 우선순위 프로세스가 영원히 CPU 기회를 못 얻는 문제  
- 주로 Priority Scheduling, MLQ에서 발생  
- **해결 방법**: **Aging 기법** → 기다린 시간에 따라 우선순위를 점차 ↑  

---

## Q8. Scheduling 단계에는 무엇이 있나요?
✅  
- **Long-term scheduling**: 어떤 Job을 시스템에 들일지 결정 (Job Scheduling)  
- **Mid-term scheduling**: 메모리 관리, 프로세스 일시 중단/재개  
- **Short-term scheduling**: Ready Queue에서 어떤 프로세스가 CPU를 얻을지 결정  
- 이 중 **Short-term Scheduling**이 CPU Scheduling에 해당  

---

## Q9. 공정성(Fairness)과 효율성(Efficiency)의 Trade-off는 무엇인가요?
✅  
- **공정성 강조** → FCFS, RR  
  - 모든 프로세스에게 CPU 기회 제공, 응답성 보장  
  - 효율성(Throughput)은 상대적으로 ↓  
- **효율성 강조** → SPN, SRTN, HRRN  
  - 평균 대기시간 최소화, 처리량 ↑  
  - 그러나 특정 프로세스는 불리 (Starvation)  

---

## Q10. Linux의 nice value란 무엇인가요?
✅  
- 리눅스에서 프로세스의 상대적 우선순위를 나타내는 값  
- 범위: `-20` (가장 높은 우선순위) ~ `+19` (가장 낮은 우선순위), 기본값 `0`  
- 값이 낮을수록 CPU를 더 자주 할당받음  
- 예시:  
  ```bash
  nice -n 10 ./program     # 낮은 우선순위 실행
  renice -n -5 -p 1234     # PID 1234 프로세스의 우선순위 높이기
