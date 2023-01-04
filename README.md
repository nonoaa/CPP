# CPP02_ex02

- 정적 멤버 함수 (static member function)
	- 정적 멤버 함수는 해당 클래스의 객체를 생성하지 않고 클래스 이름만으로 호출이 가능하다.
	```cpp
		std::cout << Fixed::max(a, b) << std::endl;
	```

# CPP02_ex03

- 한 점이 삼각형의 내부에 있는지 판별
	- 선분과 점의 외적한 값의 부호에 따라 점이 선분의 왼쪽에 있는지, 오른쪽에 있는지 판별할 수 있다. (양수일 때 왼쪽, 음수일 때 오른쪽)
	- 점이 세 선분과 외적한 결과가 모두 왼쪽에 있거나, 모두 오른쪽에 있으면 삼각형의 내부에 있다고 판별할 수 있다.

# CPP03_ex03

+ 가상 상속
	+ 다중 상속을 사용하는 경우, 다이아몬드 상속 구조를 띄게 될 수 있다. 이런 경우, 상위 클래스의 생성자와 소멸자가 두번 호출 될 수 있고, 변수도 두번 선언될 수 있다. 이런 상황을 가상 상속을 통해 해결할 수 있다. 다음과 같이 사용한다.
	```cpp
		class B : virtual public A {}
	```
	+ 가상 상속시 virtual base ptr이라는 offset을 가르키는 포인터가 생성되며, virtual로 상속된 클래스는 메모리 구조에서 제일 아래로 가게된다. 맨 아래로 간 이유는 중복을 막기 위해서이고, 위치를 맨아래에 고정시킴으로써 offset 정보를 계산할 수 있기 때문이다.
	+ 복잡하게 offset을 나눈 이유는 몇개의 상속자가 올지 모르기 때문이다. 예측을 할 수가 없으니 계산을 통해 위치를 알아내려고 만든 것이다.
	+ 이러한 다중상속으로 인한 가상 상속은 기존 데이터 크기보다 더 커질 수 있으며, offset을 이용한 자료를 찾는 과정 자체가 성능에 영향을 줄 수 있기 때문에 성능 저하를 야기할 수 있다.

# CPP04_ex00

+ virtual 키워드
	+ 기반 클래스에서 파생 클래스로 다운캐스팅 된 객체가 오버라이딩 된 함수를 사용할 경우 기반 클래스의 함수가 실행 되어버린다.
	+ 이를 해결하기 위해서 함수 선언시 virtual 키워드를 사용하여 가상함수 테이블(virtual function table)에 함수의 포인터를 저장할 수 있다.
	+ 객체 생성시 객체마다 시작주소에 가상함수 테이블의 주소값이 저장되며, 가상함수 테이블에는 virtual로 선언된 가상 함수들만이 저장 되어있다.

+ 업캐스팅
	+ 파생 클래스의 객체를 기반 클래스로 형변환 하는 것
	+ 다음과 같이 명시적 타입 변환이 필요 없다.
	```cpp
		Animal* a = new Cat();
	```

+ 다운캐스팅
	+ 업캐스팅 된 객체를 다시 파생 클래스로 형변환 하는 것
	+ 다음과 같이 명시적 타입 변환이 필요 하다.
	```cpp
		Animal* a = new Cat();
		Cat b = (Cat*)a;
	```

# CPP04_ex01

+ virtual 소멸자
	+ 업캐스팅 된 파생클래스 객체의 소멸자에서 메모리해제 함수를 사용하는 경우 소멸자를 virtual 키워드로 설정해주지 않으면 소멸자가 실행이 안되면서 메모리 누수가 발생할 수 있다.
	
# CPP04_ex02

+ 순수 가상 함수(pure virtual function)
	+ 함수의 정의가 이루어지지 않고 함수의 선언만 이루어진 함수.
	+ 순수 가상 함수가 있는 클래스를 추상 클래스(abstract class)라고 부른다.
		+ 추상 클래스는 객체 선언이 불가능하다.
		+ 추상 클래스를 상속받은 클래스는 반드시 순수 가상 함수를 오버라이딩 해야한다.
	+ 순수 가상 함수는 다음과 같이 선언한다.
	```cpp
		virtual void makeSound() = 0;
	```

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

# CPP06_ex00

+ static_cast
	+ 논리적으로 타입 변경이 가능한 경우만 변경을 허용한다.
	+ 포인터 타입을 정수 타입 등으로 변환하는 것은 방지해준다.
	+ 부모->자식, 자식->부모(위험하지만 허용) 모두 가능하다.
	```cpp
		static_cast<변환할타입>(변환대상);
	```

# CPP06_ex01

+ reinterpret_cast
	+ 포인터->포인터, 포인터->일반변수, 일반변수->포인터가 가능하다.
	+ 자료형->다른자료형은 불가능하다.# CPP06_ex02

- dynamic_cast
	- 포인터는 포인터, 레퍼런스는 레퍼런스로 변환해야 한다.
	- 실행 중에 타입을 점검하여 안전한 캐스팅만 허가한다.
	- 입력값이 포인터일 때 실패할경우 반환값 : null pointer
	- 입력값이 레퍼런스일 때 실패할경우 반환값 : bad_cast (exception 처리)
	- RTTI(Run Time Type Information)의 type_info를 사용하기 때문에 가상 함수가 사용된 클래스에 한해서만 사용가능하다.
		- 클래스의 타입 관련 정보가 vtable에 같이 저장되기 때문

# CPP07_ex01

- 함수 포인터
	```cpp
		//리턴타입 (*함수이름)(매개변수);
		int (*addFunc)(int, int);
		void (*f)(std::string &);
	```

# CPP08_ex00

```cpp
template<typename T>
T::iterator easyfind(T &container, int to_find)
{
	T::iterator iter = std::find(container.begin(), container.end(), to_find);
	if (iter == container.end())
		throw NotFoundException();
	return iter;
}
```
- 위와 같이 T::iterator 타입으로 반환하는 템플릿 함수를 만드려 했는데 에러가 났다. 이 에러를 해결하려면

```cpp
template<typename T>
typename T::iterator easyfind(T &container, int to_find)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), to_find);
	if (iter == container.end())
		throw NotFoundException();
	return iter;
}
```
- 중첩 의존 타입 이름을 식별하는 용도에서는 반드시 typename을 사용해야 한다.
	- 만약 위의 STL iterator 예제에서 typename 키워드 없이 T::iterator iter 만으로 선언을 했다면, 컴파일러는 iterator가 T 클래스 내부의 멤버변수일거라고 생각해버릴 수도 있다. 아니, 컴파일러는 이런 경우 기본적으로 타입이 아니라고 가정한다.
	- 따라서 c++ 컴파일러에게 어떤 키워드는 typedef로 재정의 된 type이라는 것을 알려주기 위해 typename 키워드를 사용해야한다.
	- 위 코드는 iterator가 T의 의존타입이기 때문에 iterator가 type이라는걸 알려주기 위해 typename 키워드를 사용해야한다.

# CPP08_ex02

- iterator 기능이 있는 custom stack 만들기
	- stack 내부에는 protected 접근권한자로 _Container 타입의 c 변수가 있고, _Container 타입은 deque<_Ty>와 같다.
	- stack을 상속 받아 c 멤버변수를 통해 deque의 함수를 호출할 수 있다.
	- deque에 존재하는 iterator와 begin, end함수 등을 사용가능!

# cpp 잡지식

## cin
- 
	```cpp
	int a;
	std::cin >> a;

	int b;
	std::cin >> b;
	```
	- 위에서 a, ㅁ같은 문자를 입력할경우, cin내부 rdstate 변수의 failbit(4)를 1로 만들어준다. 이후 failbit가 1이기때문에 입력을 추가로 받을 수 없어서 b에는 0이 들어가게 된다. 따라서 다음 입력을 받기 전에 cin의 clear()함수를 사용하여 rd_state를 goodbit(0)으로 만들어준 후 사용해야 한다. 또한 ignore()함수를 통해 입력 버퍼를 비워줘야 한다.
	- 1.23같은 소수를 입력할경우, rdstate의 비트는 변화가 없고 버퍼에만 값이 남아있게 된다. 버퍼에 값이 남아있어 추가적인 입력을 받지 못한다. 이경우는 clear()함수를 실행할 필요가 없고 ignore()함수로 입력 버퍼를 비워줘야 한다.
	- iostate
		- https://en.cppreference.com/w/cpp/io/ios_base/iostate
