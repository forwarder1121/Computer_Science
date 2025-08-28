# 🎤 Interview QnA — Lecture 7. Deadlock

운영체제 개요 7강 — 교착 상태(Deadlock) 면접 예상 질문 정리

---

## Q1. Deadlock이란 무엇인가요?
✅  
- 프로세스가 **영원히 발생 불가능한 이벤트를 기다리며 Blocked 상태에 머무는 것**  
- 즉, 시스템 내 일부 프로세스가 진행 불가 → 시스템 전체도 Deadlock 상태  

---

## Q2. Deadlock과 Starvation의 차이는?
✅  
- **Deadlock**: 자원을 기다림, “절대” 진행 불가  
- **Starvation**: CPU를 기다림, 언젠가는 실행될 수 있음  
- 즉, Deadlock은 **Blocked Queue에서 진행 불가**, Starvation은 **Ready Queue에서 진행 지연**  

---

## Q3. Deadlock 발생 필요조건은 무엇인가요?
✅ (ENCH로 암기)  
1. **E (Exclusive use)**: 자원은 배타적으로 사용  
2. **N (Non-preemptive)**: 자원은 선점 불가  
3. **C (Hold and wait)**: 자원 보유한 채 추가 자원 요청  
4. **H (Circular wait)**: 원형 대기 발생  

➡️ 네 가지 조건 중 하나라도 깨면 Deadlock은 발생하지 않음  

---

## Q4. Deadlock Prevention은 어떻게 하나요? 단점은?
✅  
- ENCH 조건 중 하나를 원천적으로 깨는 방식  
- 단점: 현실적으로 불가능/비효율  
  - Exclusive 제거 → 자원 전부 공유? 불가  
  - Non-preemptive 제거 → 디스크 같은 자원은 선점 불가  
  - Hold and wait 제거 → 필요한 자원 전부 한 번에 할당? 자원 낭비  
  - Circular wait 제거 → 자원 요청 순서 고정? 유연성↓  

---

## Q5. Deadlock Avoidance란 무엇인가요? 대표 알고리즘은?
✅  
- 자원 요청 시 시스템이 **Safe State인지 검사** → Deadlock 가능성이 있으면 요청 보류  
- **Safe State**: 모든 프로세스가 정상 종료 가능한 상태 (Safe Sequence 존재)  
- 대표 알고리즘:  
  - **Banker’s Algorithm (Dijkstra)**  
  - **Habermann’s Algorithm**  
- 단점:  
  - 프로세스 수/자원 수 고정 필요  
  - 각 프로세스 최대 자원량 사전 파악 필요  
  - 자원 활용률 ↓, 오버헤드 ↑  

---

## Q6. Deadlock Detection은 어떻게 하나요?
✅  
- Deadlock을 허용하고, 주기적으로 탐지하는 방법  
- 탐지 방법:  
  - **Resource Allocation Graph (RAG)** 활용  
  - **Graph Reduction 기법**: 프로세스를 실행/제거 시도 → 제거 불가능한 프로세스 집합이 Deadlock 집합  

---

## Q7. Deadlock Recovery 방법은?
✅  
1. **Process Termination**: Deadlock 프로세스 강제 종료 → 체크포인트에서 재시작 가능  
2. **Resource Preemption**: Deadlock 프로세스로부터 자원을 강제로 회수 → 롤백 필요  

---

## Q8. Graph Reduction에서 엣지를 지울 수 없는 경우는 언제인가요?
✅  
- 특정 프로세스가 필요한 자원을 충족할 수 없어 실행 불가할 때  
- 이 경우 그 프로세스는 제거되지 않고, 끝까지 남게 됨  
- ➡️ 남아 있는 프로세스 집합이 곧 Deadlock 집합  

---

## Q9. P3은 왜 Deadlock 그래프에서 제거될 수 있었나요?
✅  
- P3이 요청한 자원은 현재 가용 자원으로 충족 가능했기 때문  
- 따라서 실행 완료 후 자원 반환 → 그래프에서 제거  
- Deadlock 사이클(P1, P2)에는 포함되지 않았음  

---

## 📝 요약
- Deadlock 발생 조건: ENCH (Exclusive, Non-preemptive, Hold & wait, Circular wait)  
- 해결 방법: Prevention(비현실적), Avoidance(Banker’s), Detection & Recovery(실용적)  
- Graph Reduction: 지워지지 않는 프로세스 집합 = Deadlock 집합  
