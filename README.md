# 🎓 CS Interview Hub

> 백엔드/데이터 신입 대비 **CS 학습 허브**입니다.
> 과목별 상세 정리는 각 폴더의 **하위 README**에서 관리하고, 이 문서는 **진도/현황 대시보드** 역할만 합니다.

## 🧭 운영 규칙 (요약)

-   **구조**: 최상단(요약/현황) → 과목 폴더(깊은 정리·그림·예상문항)
-   **회독 표기**: ⏳ 미시작 / 🔄 진행 / ✅ 1회독 / ✅✅ 2회독 / 🔁 재복습 / 🚀 완숙

---

## 📌 7과목 대시보드 (개요)

| No. | 과목             | 폴더 링크                                                                                  | 상태 |
| --: | ---------------- | ------------------------------------------------------------------------------------------ | :--: |
|  01 | 운영체제(OS)     | [`operating-systems/README.md`](operating-systems/README.md)                               |  ⏳  |
|  02 | 네트워크         | [`computer-networks/README.md`](computer-networks/README.md)                               |  ⏳  |
|  03 | 자료구조         | [`data-structures/README.md`](data-structures/README.md)                                   |  ⏳  |
|  04 | 알고리즘         | [`algorithms/README.md`](algorithms/README.md)                                             |  ⏳  |
|  05 | 데이터베이스(DB) | [`databases/README.md`](databases/README.md)                                               |  ⏳  |
|  06 | SW 공학/테스팅   | [`software-engineering-and-testing/README.md`](software-engineering-and-testing/README.md) |  ⏳  |
|  07 | Java / Spring    | [`java-and-spring/README.md`](java-and-spring/README.md)                                   |  ⏳  |

> 상태 이모지: ⏳ 미시작 · 🔄 진행 · ✅ 1회독 · ✅✅ 2회독 · 🔁 재복습 · 🚀 완숙
> 난이도 메모(선택): 🥈 개념 / 🥇 실전 / 💎 심화

---

## 🧩 과목별 대표 키워드 (요약)

| 과목             | 대표 키워드                                                                                         |
| ---------------- | --------------------------------------------------------------------------------------------------- |
| 운영체제(OS)     | 실행/자원 관리, **프로세스/스레드**, 동기화(뮤텍스·세마포어·모니터), 스케줄링, 가상메모리(TLB·교체) |
| 네트워크         | **TCP/UDP**, 3/4-way, 혼잡제어, **HTTP/1.1·2·3**, TLS/HTTPS, **DNS/LB/CDN**, 프록시/캐시            |
| 자료구조         | 배열/연결리스트, 스택/큐/덱, **힙/해시**, 트리/BST, 세그먼트·펜윅                                   |
| 알고리즘         | **복잡도**, 그래프(DFS/BFS/최단경로), **DP/그리디/분할정복**, 문자열(KMP/Trie)                      |
| 데이터베이스(DB) | 정규화, **인덱스(B-Tree/해시)**, 조인 전략, 트랜잭션(ACID), **격리·락·MVCC**, 샤딩/복제             |
| SW 공학/테스팅   | **TDD**, 테스트 격리/픽스처, CI/CD, PR 리뷰, 리팩터링, **SOLID**                                    |
| Java / Spring    | **JVM/GC**, 동시성, Spring MVC/Boot, 트랜잭션, AOP, 예외/검증, 테스트                               |

---

## 📚 학습 리소스 (과목별 대표 강의)

-   **운영체제**: 김덕수 교수님 OS 강의 모음(슬라이드+YouTube). 커널/프로세스/스레드/VM까지 정통 커리큘럼. ([HPC Lab.][1])
-   **네트워크**: 한양대 이석복 교수님 _컴퓨터네트워크_ (KOCW). 2015-2/2018-2판, Top-Down 구성·수강 통계·평점 공개(2015-2: 조회수·평점 있음). ([kocw.net][2])
-   **자료구조**: 건국대 남원홍 교수님 _자료구조_ (KOCW). 전공 표준 커리큘럼으로 실습 병행. ([kocw.net][3])
-   **알고리즘**: 건국대 김강일 교수님 _알고리즘_ (KOCW). 설계기법·그래프·문제적용 중심. ([kocw.net][4])
-   **데이터베이스**: 가톨릭대 황병연 교수님 _데이터베이스설계_ (KOCW). RDBMS 구조·연산·설계·구현 기법. ([kocw.net][5])
-   **소프트웨어 공학**: 동국대 조영석 교수님 _소프트웨어공학_ (KOCW). SW 생애주기·요구/설계/품질 개론. ([kocw.net][6])
-   **Java / Spring**: Around Hub Studio _Spring Boot_ 강의(YouTube) + 예제 GitHub 레포. 프로젝트 생성/구조/구성 연계 실습. ([YouTube][7], [GitHub][8])

---

## 🗂️ 폴더 구조

```
.
├── operating-systems/
│   └── README.md
├── computer-networks/
│   └── README.md
├── data-structures/
│   └── README.md
├── algorithms/
│   └── README.md
├── databases/
│   └── README.md
├── software-engineering-and-testing/
│   └── README.md
└── java-and-spring/
    └── README.md
```

---

## 🔗 링크 모음(복사용)

> 아래 블록을 **그대로 복붙**하면 각 과목 하위 README나 본문 어디서든 바로 클릭 가능한 링크가 됩니다.

```md
-   운영체제: 김덕수 교수님 OS 강의 모음 — https://hpclab.tistory.com/1?category=887083
-   네트워크: 한양대 이석복 ‘컴퓨터네트워크’(KOCW 메인) — https://www.kocw.net/home/college/cview.do?cid=6166c077e545b736
-   자료구조: 건국대 남원홍 ‘자료구조’(KOCW) — https://www.kocw.net/home/cview.do?kemId=1190355
-   알고리즘: 건국대 김강일 ‘알고리즘’(KOCW) — https://www.kocw.net/home/cview.do?kemId=1278171
-   데이터베이스: 가톨릭대 황병연 ‘데이터베이스설계’(KOCW) — https://kocw.net/home/cview.do?kemId=1207109
-   소프트웨어공학: 동국대 조영석 ‘소프트웨어공학’(KOCW) — https://www.kocw.net/home/cview.do?kemId=1045594
-   Java/Spring(영상): Spring Boot 강의 플레이리스트 — https://www.youtube.com/playlist?list=PLlTylS8uB2fBOi6uzvMpojFrNe7sRmlzU
-   Java/Spring(소스): Around Hub Studio 예제 레포 — https://github.com/Around-Hub-Studio/around-hub-spring-boot
```

---

필요하면 각 **하위 README**에 위 링크/커리큘럼을 바로 박아 넣은 템플릿도 만들어줄게.

[1]: https://hpclab.tistory.com/1?utm_source=chatgpt.com "운영체제 강의 모음 (슬라이드 & YouTube 링크) - HPC Lab."
[2]: https://www.kocw.net/home/college/cview.do?cid=6166c077e545b736&utm_source=chatgpt.com "컴퓨터네트워크"
[3]: https://www.kocw.net/home/cview.do?ar=pop&kemId=1190355&mty=p&utm_source=chatgpt.com "자료구조 - 건국대학교 | KOCW 공개 강의"
[4]: https://www.kocw.net/home/cview.do?kemId=1278171&lid=1278172&mty=p&utm_source=chatgpt.com "알고리즘 - 건국대학교 | KOCW 공개 강의"
[5]: https://kocw.net/home/cview.do?ar=relateCourse&kemId=1207109&mty=p&utm_source=chatgpt.com "데이터베이스 설계 - 가톨릭대학교 | KOCW 공개 강의"
[6]: https://www.kocw.net/home/cview.do?kemId=1045594&mty=p&utm_source=chatgpt.com "소프트웨어공학 - 동국대학교 | KOCW 공개 강의"
[7]: https://www.youtube.com/playlist?list=PLlTylS8uB2fBOi6uzvMpojFrNe7sRmlzU&utm_source=chatgpt.com "스프링 부트 (Spring Boot) 강의"
[8]: https://github.com/Around-Hub-Studio/around-hub-spring-boot?utm_source=chatgpt.com "Around-Hub-Studio/around-hub-spring-boot"
