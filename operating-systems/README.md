# 🖥️ 운영체제 (Operating Systems)

운영체제(OS)는 컴퓨터 하드웨어와 소프트웨어 자원을 관리하고, 사용자와 하드웨어 간의 인터페이스 역할을 수행합니다.  
본 문서는 **강의 기반 개념 정리 + 면접 대비 QnA + 직접 필기 자료**를 체계적으로 관리하기 위한 대시보드 역할을 합니다.

---

## 📌 학습 현황
상태 이모지: ⏳ 미시작 · 🔄 진행 · ✅ 1회독 · ✅✅ 2회독 · 🔁 재복습 · 🚀 완숙

| No. | 챕터 | 상태 | 링크 |
|-----|------|------|------|
| 01 | 컴퓨터 시스템 개요 | ⏳ | [01-introduction](./01-introduction/README.md) |
| 02 | 운영체제 개요 | ⏳ | [02-os-overview](./02-os-overview/README.md) |
| 03 | 프로세스 관리 | ⏳ | [03-process-management](./03-process-management/README.md) |
| 04 | 스레드 관리 | ⏳ | [04-thread-management](./04-thread-management/README.md) |
| 05 | CPU 스케줄링 | ⏳ | [05-cpu-scheduling](./05-cpu-scheduling/README.md) |
| 06 | 동기화 | ⏳ | [06-synchronization](./06-synchronization/README.md) |
| 07 | 교착상태 (Deadlock) | ⏳ | [07-deadlock](./07-deadlock/README.md) |
| 08 | 메모리 관리 | ⏳ | [08-memory-management](./08-memory-management/README.md) |
| 09 | 가상 메모리 | ⏳ | [09-virtual-memory](./09-virtual-memory/README.md) |
| 10 | 가상 메모리 관리 | ⏳ | [10-virtual-memory-mgmt](./10-virtual-memory-mgmt/README.md) |
| 11 | 파일 & 저장장치 | ⏳ | [11-file-storage](./11-file-storage/README.md) |
| 12 | I/O 시스템 & 디스크 스케줄링 | ⏳ | [12-io-disk](./12-io-disk/README.md) |
| 13 | 마무리 | ⏳ | [13-summary](./13-summary/README.md) |

---

## 🗓️ 학습 체크리스트 (강의 단위)

*(생략 — 위에서 작성한 체크리스트 그대로 유지)*

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
│   ├── interview\.md          # 면접 QnA
│   └── notes/                # 손필기 (이미지/스캔)
│
├── 02-os-overview/           # 운영체제 개요
│   ├── README.md
│   ├── interview\.md
│   └── notes/
│
├── 03-process-management/    # 프로세스 관리
│   ├── README.md
│   ├── interview\.md
│   └── notes/
│
├── 04-thread-management/     # 스레드 관리
│   ├── README.md
│   ├── interview\.md
│   └── notes/
│
├── 05-cpu-scheduling/        # CPU 스케줄링
│   ├── README.md
│   ├── interview\.md
│   └── notes/
│
├── 06-synchronization/       # 동기화
│   ├── README.md
│   ├── interview\.md
│   └── notes/
│
├── 07-deadlock/              # 교착상태
│   ├── README.md
│   ├── interview\.md
│   └── notes/
│
├── 08-memory-management/     # 메모리 관리
│   ├── README.md
│   ├── interview\.md
│   └── notes/
│
├── 09-virtual-memory/        # 가상 메모리
│   ├── README.md
│   ├── interview\.md
│   └── notes/
│
├── 10-virtual-memory-mgmt/   # 가상 메모리 관리
│   ├── README.md
│   ├── interview\.md
│   └── notes/
│
├── 11-file-storage/          # 파일 & 저장장치
│   ├── README.md
│   ├── interview\.md
│   └── notes/
│
├── 12-io-disk/               # I/O & 디스크
│   ├── README.md
│   ├── interview\.md
│   └── notes/
│
└── 13-summary/               # 마무리
├── README.md
├── interview\.md
└── notes/

````

---

## 📝 필기 자료 (Handwritten Notes)

- 모든 챕터별 `notes/` 폴더에 업로드  
- 권장 규칙: `챕터번호-주제-날짜.jpg` (예: `03-process-context-2025-08-20.jpg`)  
- 챕터별 README.md에 직접 삽입 가능  
