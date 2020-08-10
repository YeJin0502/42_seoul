# C++ - Module 02

Ad-hoc polymorphism, operators overload and canonical classes

## 일반 지침

cpp00과 동일.

## 보너스 규칙

이제부터, 당신이 작성하는 각 클래스들은 반드시 canonical (Coplien) form 이어야 합니다: 최소한 하나의 기본 생성자, 복사 생성자, 할당 연산자 오버로드, 소멸자. 다시 요구하진 않을 것입니다.

## Exercise 00: My First Canonical Class

| Exercise : 00 |
| --- |
| 제출 디렉토리: ex00/ |
| 제출할 파일: Fixed.class.hpp and Fixed.class.cpp, or Fixed.hpp and Fixed.cpp, or Fixed.h and Fixed.cc. Pick one, I don’t care unless it’s stupid. |
| 금지 함수: 없음 |

당신은 정수를 알고 있고, 또한 부동 소수점 숫자도 알고 있습니다. 얼마나 귀엽습니까.

그렇지 않은지 이 3 페이지([1](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html), [2](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html), [3](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html))의 글을 읽고 확인하세요. 계속 읽어보세요.

오늘까지, 당신의 프로그램들에서 사용했던 모든 숫자들은 기본적으로 정수이거나 부동 소수점 숫자이거나 그 변형(short, char, long, double, 기타)들이었습니다. 앞에서 읽었던 것처럼, 정수와 부동 소수점 숫자는 반대 특성을 가지고 있다고 가정하는 것이 안전할 것입니다.

하지만 오늘, 이것이 바뀔 것입니다. 당신은 새롭고 놀라운 숫자 타입을 발견할 것입니다: 고정 소수점 숫자(fixed point numbers)! 대부분의 스칼라 타입 언어에서 누락된 고정 소수점 숫자는 성능, 정확도, 범위, 정밀도 사이의 가치 있는 균형을 제공합니다. 이러한 이유로 이 숫자는 그래픽, 사운드, 과학적 프로그래밍에서 널리 사용됩니다.

C++에는 고정 소수점 숫자가 없으므로, 당신은 오늘 직접 이것을 추가해 볼 것입니다. 시작으로 Berkeley의 [이 글](https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html)을 추천합니다. 그들에게 유용하다면, 당신에게도 유용할 것입니다.(If it’s good for them, it’s good for you.) Berkeley가 무엇인지 모른다면, 위키피디아의 [이 문항](https://en.wikipedia.org/wiki/University_of_California,_Berkeley#Notable_alumni.2C_faculty.2C_and_staff)을 읽어보세요.

고정 소수점 숫자를 나타내는 canonical 클래스를 작성하세요:

* private 멤버:
    * 고정 소수점 값을 저장할 int
    * 분수 비트 수를 저장할 static constant int. 이 상수는 항상 리터럴 8이 됩니다. (A static constant integer to store the number of fractional bits. This constant will always be the litteral 8.)

* public 멤버:
    * 고정 소수점 값을 0으로 초기화하는 기본 생성자
    * 소멸자
    * 복사 생성자
    * 할당 연산자 오버로드
    * 고정 소수점 값의 raw 값을 반환하는 멤버 함수 `int getRawBits(void) const;`
    * 고정 소수점 값의 raw 값을 설정하는 멤버 함수 `void setRawBits(int const raw);`

코드는 다음과 같습니다:
``` c++
#include <iostream>

int main( void )
{
    Fixed a;
    Fixed b( a );
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
```

아웃풋은 다음과 같습니다:
```
$> clang++ -Wall -Wextra -Werror Fixed.class.cpp main.cpp
$> ./a.out
Default constructor called
Copy constructor called
Assignation operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Assignation operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
$>
```
