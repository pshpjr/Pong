# BreakOut

BreakOut은 테트리스 99를 보고 시작하게 된 프로젝트 입니다. 99명의 플레이어가 동시에 벽돌깨기를 진행하며 목숨 3개를 모두 잃을 경우 탈락하게 됩니다.
최후의 1인은 승자가 됩니다. 

## 영상
[https://studio.youtube.com/video/dItx-sm4Z88/edit](https://youtu.be/dItx-sm4Z88)

## 목적
게임 서버 프로그래밍 공부를 위한 것으로 멀티스레딩, IOCP를 중점적으로 공부합니다.

<!-- 이 프로젝트를 통해 성취하고자 하는 목표도 기술-->
## 사용법

## 목표 기능
IOCP를 이용한 stateful 서버
99명 동시 접속
최대 10000명 접속 가능한 서버


**추가 구현 가능성**
* 로그인, 회원가입 기능
* 전적 등 회원 정보
<!---->
## 구현 내용

<details markdown="1">
<summary><h3>클라이언트</h3></summary>

* 더미 클라이언트(5000명까지 한 프로세스에서 딜레이 없이 처리 가능)

* 클라이언트 FreeGLUT으로 구현. 간단한 게임 화면 제공

* 공 위치 예측


</details>


<details markdown="2">
<summary><h3>서버</h3></summary>
<!-- 서버 내용 기입-->
  
* 패킷 헤더 및 완전한 TCP 패킷이 전송되었는지 확인
  
* 충돌 판정
  
* 플레이어 체력 및 사망 판정
  
* 세션 Connect, Disconnect 확인 및 처리
  
* 1Send
  
* JobQueue를 활용한 멀티스레딩
  
* JobTimer를 활용한 게임 루프
  
* 게임 종료 및 승패 처리, 방 초기화 후 재사용
  
* Protobuf를 활용한 객체 직렬화 전송

</details>



