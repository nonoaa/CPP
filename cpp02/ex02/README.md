# CPP02_ex02

- 정적 멤버 함수 (static member function)
	- 정적 멤버 함수는 해당 클래스의 객체를 생성하지 않고 클래스 이름만으로 호출이 가능하다.
	```cpp
		std::cout << Fixed::max(a, b) << std::endl;
	```