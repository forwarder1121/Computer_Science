# 🔒 Lecture 7. Deadlock

## 1. Deadlock 정의
- **Deadlock state**: 프로세스가 **발생 불가능한 이벤트를 무기한 대기**하는 상태  
- 시스템 내에 하나 이상의 프로세스가 Deadlock에 빠져 있으면 → 시스템이 Deadlock 상태  

⚠️ 참고  
- **Blocked / Asleep state**: 특정 이벤트를 기다리는 상태 → 조건 충족 시 깨어남  
- Deadlock은 Blocked 상태가 영원히 풀리지 않는 특수한 경우  

---

## 2. Deadlock vs Starvation
- **Starvation**: CPU를 기다리는 상태, 언젠가는 실행될 수 있음 (ready queue → running 불가)  
- **Deadlock**: 자원을 기다리는 상태, 절대 실행 불가 (blocked state에서 멈춤)  

---

## 3. 자원(Resource) 분류
- **HW 자원**: 프로세서, 메모리, 디스크 등  
- **SW 자원**: 파일, 세마포어, 메시지 큐 등  

특성에 따른 분류:
1. **선점 가능 여부**
   - 선점 가능: CPU, 메모리 (context-switch로 복원 가능)
   - 선점 불가: 디스크 드라이브(쓰기 도중 뺏기면 손상 발생 → 롤백/재시작 필요)  
2. **할당 단위**: 전체 / 부분 할당  
3. **동시 사용 가능 여부**: 공유 가능 / 배타적 사용 (exclusive)  
4. **재사용 가능 여부**: 일회성 / 반복 사용 가능  

➡️ Deadlock은 보통 자원이 **선점 불가, 동시 사용 불가, 반복 재사용 가능**일 때 발생  

---

## 4. Deadlock 발생 필요조건 (ENCH)
Deadlock이 발생하려면 아래 네 가지 조건이 모두 만족해야 함:  

1. **E (Exclusive use)**: 자원은 배타적으로 사용됨 (exclusive allocation)  
2. **N (Non-preemptive)**: 자원은 선점 불가 (non-preemptible resource)  
3. **C (Hold and wait)**: 자원을 보유한 상태에서 추가 자원 요청 가능  
4. **H (Circular wait)**: 프로세스 집합 간에 원형 대기 발생  

➡️ **ENCH**로 외우면 쉽다.  
➡️ 하나라도 깨면 Deadlock 발생 불가  

---

## 5. Deadlock 해결 방법
### 5.1 Prevention (예방)
- ENCH 조건 중 하나를 원천적으로 깨서 Deadlock이 아예 발생하지 않게 함  
- 단점: 현실적으로 대부분 불가능  
  - Exclusive use 제거 → 자원을 전부 공유? 불가  
  - Non-preemptive 제거 → 디스크 같은 자원은 선점 불가  
  - Hold and wait 제거 → 모든 자원을 한 번에 할당? 비현실적  
  - Circular wait 제거 → 자원 순서 강제? 낭비 심함  
- ➡️ Prevention은 실제로 거의 쓰이지 않음  

---

### 5.2 Avoidance (회피)
- Deadlock이 발생하지 않도록 **자원 할당을 감시하며 Safe State 유지**  
- **Safe State**: 모든 프로세스가 정상 종료 가능한 상태 (Safe Sequence 존재)  
- 알고리즘:
  - **Banker’s Algorithm (Dijkstra)**  
  - **Habermann’s Algorithm**  
- 방식: 요청이 들어오면 “자원을 준다고 가정” → Safe Sequence 존재하면 할당 허용  
- 단점:
  - 프로세스/자원 수 고정 필요  
  - 각 프로세스의 최대 자원 수를 미리 알아야 함  
  - 오버헤드 ↑, 자원 활용률 ↓  

---

### 5.3 Detection & Recovery (검출과 복구)
- Deadlock 방지를 위한 조치 없이 그냥 발생을 허용  
- 대신 **주기적으로 Deadlock 탐지 → 복구**  

**Detection**  
- 자원 할당 그래프(RAG) 활용  
- **Graph Reduction 기법**: 프로세스를 하나씩 실행/제거 시도 → 제거 불가능한 프로세스 집합 = Deadlock 집합  
- 단점: 오버헤드 ↑ → 저비용 알고리즘 활용  

**Recovery**  
1. **Process Termination**  
   - Deadlock 프로세스를 강제 종료  
   - 체크포인트 후 재시작 가능  
2. **Resource Preemption**  
   - 특정 프로세스로부터 자원을 강제로 회수  
   - 롤백 및 재시작 필요  

---

## 6. 요약
- Deadlock: **선점 불가 + 배타적 사용 + Hold&Wait + Circular Wait** (ENCH 조건)  
- 해결 방법:
  - **Prevention**: ENCH 조건을 원천적으로 차단 (비현실적)  
  - **Avoidance**: Safe State 유지 (Banker’s Algorithm, 비효율적)  
  - **Detection & Recovery**: Deadlock 허용 → 주기적 탐지 & 복구 (현실적)  
