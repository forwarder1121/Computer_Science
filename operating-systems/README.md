# 🖥️ 운영체제 (Operating Systems)

운영체제(OS)는 컴퓨터 하드웨어와 소프트웨어 자원을 관리하고, 사용자와 하드웨어 간의 인터페이스 역할을 수행합니다.  
본 문서는 **강의 기반 개념 정리 + 면접 대비 QnA + 직접 필기 자료**를 체계적으로 관리하기 위한 대시보드 역할을 합니다.

---

## 📌 학습 현황
상태 이모지: ⏳ 미시작 · 🔄 진행 · ✅ 1회독 · ✅✅ 2회독 · 🔁 재복습 · 🚀 완숙

| No. | 챕터 | 상태 | 링크 |
|-----|------|------|------|
| 01 | 컴퓨터 시스템 개요 | ✅  | [01-introduction](./01-introduction/README.md) |
| 02 | 운영체제 개요 | ✅  | [02-os-overview](./02-os-overview/README.md) |
| 03 | 프로세스 관리 | ✅ | [03-process-management](./03-process-management/README.md) |
| 04 | 스레드 관리 | ✅ | [04-thread-management](./04-thread-management/README.md) |
| 05 | CPU 스케줄링 | ✅ | [05-cpu-scheduling](./05-cpu-scheduling/README.md) |
| 06 | 동기화 | ✅ | [06-synchronization](./06-synchronization/README.md) |
| 07 | 교착상태 (Deadlock) | ✅ | [07-deadlock](./07-deadlock/README.md) |
| 08 | 메모리 관리 | ✅ | [08-memory-management](./08-memory-management/README.md) |
| 09 | 가상 메모리 | ✅ | [09-virtual-memory](./09-virtual-memory/README.md) |
| 10 | 가상 메모리 관리 | ✅ | [10-virtual-memory-mgmt](./10-virtual-memory-mgmt/README.md) |
| 11 | 파일 & 저장장치 | ⏳ | [11-file-storage](./11-file-storage/README.md) |
| 12 | I/O 시스템 & 디스크 스케줄링 | ⏳ | [12-io-disk](./12-io-disk/README.md) |
| 13 | 마무리 | ⏳ | [13-summary](./13-summary/README.md) |

---


## 🗓️ 학습 체크리스트 (강의 단위)

### Part 1: 운영체제 개요
- [x] Lec 1. Computer System Overview
- [x] Lec 2. OS Overview (1/3)
- [x] Lec 2. OS Overview (2/3)
- [x] Lec 2. OS Overview (3/3)

### Part 2: 프로세스와 스레드
- [x] Lec 3. Process Management (1/2)
- [x] Lec 3. Process Management (2/2)
- [x] Lec 4. Thread Management

### Part 3: CPU 스케줄링
- [x] Lec 5. Process Scheduling (1/4)
- [x] Lec 5. Process Scheduling (2/4) - FCFS, RR
- [x] Lec 5. Process Scheduling (3/4) - SPN, SRTN, HRRN
- [x] Lec 5. Process Scheduling (4/4) - MLQ, MFQ

### Part 4: 동기화
- [x] Lec 6. Synchronization (1/7) - Intro
- [x] Lec 6. Synchronization (2/7) - SW solutions
- [x] Lec 6. Synchronization (3/7) - HW solution
- [x] Lec 6. Synchronization (4/7) - Spinlock
- [x] Lec 6. Synchronization (5/7) - Semaphore
- [x] Lec 6. Synchronization (6/7) - Eventcount/Sequencer
- [x] Lec 6. Synchronization (7/7) - Monitor

### Part 5: 교착상태 (Deadlock)
- [x] Lec 7. Deadlock (1/5) - Deadlock and Resource types
- [x] Lec 7. Deadlock (2/5) - Deadlock model
- [x] Lec 7. Deadlock (3/5) - Deadlock Prevention
- [x] Lec 7. Deadlock (4/5) - Deadlock Avoidance
- [x] Lec 7. Deadlock (5/5) - Deadlock Detection & Recovery

### Part 6: 메모리 관리
- [x] Lec 8. Memory Management (1/3) - Backgrounds
- [x] Lec 8. Memory Management (2/3) - Fixed Partition
- [x] Lec 8. Memory Management (3/3) - Variable Partition

### Part 7: 가상 메모리
- [x] Lec 9. Virtual Memory (1/5) - Non-continuous allocation
- [x] Lec 9. Virtual Memory (2/5) - Paging (1)
- [x] Lec 9. Virtual Memory (3/5) - Paging (2)
- [x] Lec 9. Virtual Memory (4/5) - Segmentation
- [x] Lec 9. Virtual Memory (5/5) - Hybrid Paging-Segmentation

### Part 8: 가상 메모리 관리
- [x] Lec 10. VM Management (1/6) - Cost model, HW components
- [x] Lec 10. VM Management (2/6) - SW components
- [x] Lec 10. VM Management (3/6) - Replacement (Fixed 1)
- [x] Lec 10. VM Management (4/6) - Replacement (Fixed 2)
- [x] Lec 10. VM Management (5/6) - Replacement (Variable)
- [x] Lec 10. VM Management (6/6) - Other considerations

### Part 9: 파일 시스템 & 저장장치
- [ ] Lec 11-1. Disk System
- [ ] Lec 11-2. File System Overview
- [ ] Lec 11-3. Directory Structure
- [ ] Lec 11-4. File Protection
- [ ] Lec 11-5. File System Implementation

### Part 10: I/O 시스템 & 디스크 스케줄링
- [ ] Lec 12-1. I/O System
- [ ] Lec 12-2. Disk Scheduling
- [ ] Lec 12-3. RAID Architecture

### Part 11: 마무리
- [ ] Lec 13. 마무리 인사 (총정리)

---

## 📚 학습 리소스
- 강의: [김덕수 교수님 운영체제 (YouTube Playlist)](https://www.youtube.com/watch?v=EdTtGv9w2sA&list=PLBrGAFAIyf5rby7QylRc6JxU5lzQ9c4tN)
- 참고 교재: *쉽게 배우는 운영체제 (조성호)*, *Operating System Concepts (Silberschatz)*
- 면접 대비: Tech Interview Handbook, CS Interview Repo

---

## 🗂️ 폴더 구조

```

operating-systems/
│── README.md                 # 전체 개요 & 현황판 & 진도표
│
├── 01-introduction/          # 컴퓨터 시스템 개요
│   ├── README.md             # 강의 요약
│   ├── interview.md          # 면접 QnA
│   └── notes/                # 손필기 (이미지/스캔)
│
├── 02-os-overview/           # 운영체제 개요
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
├── 03-process-management/    # 프로세스 관리
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
├── 04-thread-management/     # 스레드 관리
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
├── 05-cpu-scheduling/        # CPU 스케줄링
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
├── 06-synchronization/       # 동기화
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
├── 07-deadlock/              # 교착상태
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
├── 08-memory-management/     # 메모리 관리
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
├── 09-virtual-memory/        # 가상 메모리
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
├── 10-virtual-memory-mgmt/   # 가상 메모리 관리
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
├── 11-file-storage/          # 파일 & 저장장치
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
├── 12-io-disk/               # I/O & 디스크
│   ├── README.md
│   ├── interview.md
│   └── notes/
│
└── 13-summary/               # 마무리
├── README.md
├── interview.md
└── notes/

````

---

## 📝 필기 자료 (Handwritten Notes)

- 모든 챕터별 `notes/` 폴더에 업로드  
- 권장 규칙: `챕터번호-주제-날짜.jpg` (예: `03-process-context-2025-08-20.jpg`)  
- 챕터별 README.md에 직접 삽입 가능  
