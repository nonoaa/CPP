# CPP08_ex02

- iterator 기능이 있는 custom stack 만들기
	- stack 내부에는 protected 접근권한자로 _Container 타입의 c 변수가 있고, _Container 타입은 deque<_Ty>와 같다.
	- stack을 상속 받아 c 멤버변수를 통해 deque의 함수를 호출할 수 있다.
	- deque에 존재하는 iterator와 begin, end함수 등을 사용가능!