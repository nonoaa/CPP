# CPP05_ex00

+ 예외 처리 클래스
	+ exception class를 상속받아 what()을 오버라이드 한다.
	```cpp
		class A : public exception
		{
		public:
			const char *what() const throw()
			{
				return "message";
			}
		}
	```
