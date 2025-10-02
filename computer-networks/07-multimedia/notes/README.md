# README.md — Ch.7 Multimedia Networking 요약

## 📌 Multimedia: Audio

-   **아날로그 → 디지털 변환 과정**

    -   샘플링(sampling): 초당 N회 측정 (예: 8kHz = 8,000 samples/sec)
    -   양자화(quantization): 1 sample = β bit (예: 8bit → 256 단계)
    -   전송률 계산: `샘플링률 × 비트수 × 채널 수`
    -   예: 전화 음성 = 8kHz × 8bit × 1ch = **64 kbps**

-   예시 전송률

    -   CD: 1.411 Mbps
    -   MP3: 96, 128, 160 kbps
    -   인터넷 전화(VoIP): 5.3 kbps ~

---

## 📌 How to stream data?

-   스트리밍 데이터는 **실시간 연속 재생** 필요
-   → 네트워크 지연·가변성을 감안해 **버퍼(buffering)** 사용
-   일정하지 않은 지연 → **jitter** 문제 발생

---

## 📌 DASH (Dynamic Adaptive Streaming over HTTP)

-   동영상 파일을 **작은 chunk(세그먼트)**로 분할
-   여러 버전(비트레이트/화질)로 인코딩
-   **Manifest file**: 어떤 화질, 어떤 chunk가 있는지 목록 제공
-   클라이언트(YouTube, Netflix 등)는 네트워크 상황에 따라

    -   빠르면 고화질 chunk
    -   느리면 저화질 chunk

-   장점: HTTP 기반 → 기존 웹 인프라(CDN, 캐시, 방화벽) 그대로 활용

---

## 📌 CDN (Content Delivery Network)

-   콘텐츠를 **전 세계 캐시 서버(edge server)**에 분산 배치
-   사용자는 가까운 CDN 서버에서 데이터 수신
-   장점

    -   지연(latency) 감소
    -   서버 부하 분산
    -   대규모 스트리밍 지원

-   유튜브/넷플릭스: 원본 서버는 **manifest file만 제공**, 실제 콘텐츠는 CDN 서버에서 전송

---

## 📌 핵심 개념 정리

| 개념             | 설명                                         |
| ---------------- | -------------------------------------------- |
| **Sampling**     | 아날로그 신호를 일정 간격으로 측정           |
| **Quantization** | 각 샘플을 이산값(비트)로 근사                |
| **Jitter**       | 패킷 도착 시간이 불규칙하게 흔들림           |
| **Buffering**    | 네트워크 변동성 보완을 위해 데이터 미리 저장 |
| **DASH**         | HTTP 기반 적응형 스트리밍 (화질 자동 조정)   |
| **CDN**          | 사용자 근처 서버에서 콘텐츠 제공 (지연 감소) |
