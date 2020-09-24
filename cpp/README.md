
<details>
<summary>정리 필요</summary>

## cpp00

### cpp
* https://modoocode.com/135 : 모두의코드
* https://boycoding.tistory.com/135?category=1006674 : 소년코딩
* https://blog.hexabrain.net/167

### 레퍼런스, 참조
* https://modoocode.com/141

### 객체, 클래스, 인스턴스
* https://modoocode.com/172
* https://andrew0409.tistory.com/8

### string
* https://modoocode.com/233

### setw()

### cin clear ignore
* https://satrol.tistory.com/m/69 : 숫자만 입력받기
* https://dodnet.tistory.com/488 : 숫자를 입력해야 빠져나가는 루프문.



## cpp01

### c++ 네이밍
* https://torbjorn.tistory.com/257 : 멤버변수 뒤에 추가로 언더바(_) 붙여서 구분.

### 랜덤 문자열 생성
* https://m.blog.naver.com/ktguni/221249010968 : `rand()`, `srand()`, `time()`을 사용.

### c++ const 함수
* https://dydtjr1128.github.io/cpp/2019/08/05/Cpp-const-after-function.html : 함수 뒤에 const는 함수가 멤버 변수를 변경할 수 없다는 뜻.

### stringstream
* `#include <sstream>`

### const 멤버변수 초기화
* https://simplesolace.tistory.com/entry/const-%ED%81%B4%EB%9E%98%EC%8A%A4-%EB%A9%A4%EB%B2%84%EB%B3%80%EC%88%98-%EC%B4%88%EA%B8%B0%ED%99%94%ED%95%98%EA%B8%B0 : 초기화하려면 `생성자 : id_(id)` 이런 식으로 생성자 시작 전에.

### c++ 파일 입출력
* `#include <fstream>`
* https://modoocode.com/213 : c++의 입출력. 좋은 내용인데 다는 안 읽음... 나중에.
* https://modoocode.com/215 : c++의 파일 입출력.

### throw
* https://modoocode.com/230 : c++에서의 예외처리. `try`, `catch`, `throw`.

### c++ 예외 처리
* https://blog.hexabrain.net/179 : 이외에 좋은 글 많음.
* https://www.cppkorea.org/CppCoreGuidelines/Errors/ : 읽기는 어렵지만... 나중에 도움될 수?



## cpp02

### 할당 연산자 오버로딩
* https://edykim.com/ko/post/c-operator-overloading-guidelines/
* https://blog.hexabrain.net/177
* https://modoocode.com/202

### 복사 생성자
* https://udpark.tistory.com/29

### 비트 연산자
* http://tcpschool.com/c/c_operator_bitwise
    > `<<` 비트들을 왼쪽으로 이동시킴.

### 고정 소수점
* https://gsmesie692.tistory.com/94
    > 고정 소수점은 10진수를 2진수로 바꾸고 정수부와 소수부에 나누어 그대로 저장.

### roundf
* http://www.cplusplus.com/reference/cmath/round/

### 소수 2진법 변환
* http://cjyuko.blogspot.com/2018/05/10-2.html

### ostream 연산자 오버로드
* https://docs.microsoft.com/ko-kr/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=vs-2019



## cpp03

### switch case
* https://boycoding.tistory.com/186
* https://studymake.tistory.com/129

### const
* https://dhna.tistory.com/25 : const 위치에 따른 동작
* https://www.cppkorea.org/CppCoreGuidelines/Const/ : c++ 핵심 가이드라인 - const
* https://dydtjr1128.github.io/cpp/2020/01/08/Cpp-const.html

### 상속
* https://wikidocs.net/21857 : 다른 것들도 볼만할 듯. 글들이 짧고 코드 위주라 좋음.



## cpp04

### 할당 연산자 오버로딩
* https://edykim.com/ko/post/c-operator-overloading-guidelines/

### 컨테이너
* http://tcpschool.com/cpp/cpp_container_intro
    > 같은 타입의 여러 객체를 저장하는 일종의 집합.

### 공부가 필요한 내용
* const
    * 연산자 오버로딩에서의 const \<class\>&
    * getter에서의 const 반환
    * getter에서의 함수명 뒤의 const
* Coplien 형식을 잘 못 알고 있나? 캐노니컬하고 코플린은 정확히 뭐지?

</details>



## cpp05

### try catch exception
* https://egg-money.tistory.com/205
* https://blog.hexabrain.net/179

### 초기화 리스트
* https://psychoria.tistory.com/11
    > 초기화 리스트를 사용해야만 하는 경우.

### const 멤버변수
* 값이 고정된 멤버변수.
* 일반 변수의 맨 앞에 const가 붙는다.
* 따라서 생성자에서 초기화 리스트로 초기화하고, 이후 불변.
* 복사생성자에서도 초기화 리스트.
    ```c++
    Form::Form(const Form& ref)
    throw(GradeTooHighException, GradeTooLowException)
    :   name_(ref.name_),
        grade_for_sign_(validGrade(ref.grade_for_sign_)),
        grade_for_exec_(validGrade(ref.grade_for_exec_)) // 초기화 리스트
    {
        *this = ref;
    }
    ```
* 할당연산자에서도 const 멤버변수는 (불변이므로) 할당하지 못한다.
    ```c++
    Form&
    Form::operator = (const Form& ref)
    {
        if (this != &ref)
        {
            sign_ = ref.sign_; // const가 아닌 멤버변수만 할당
        }
        return (*this);
    }
    ```

### 두 클래스가 서로를 사용할 때
* A 클래스와 B 클래스가 멤버함수에서 서로 매개변수로 참조한다고 하자. 이 경우, `error unknown type name 'A'`, `error unknown type name 'B'` 등의 오류가 발생한다.
* 따라서 한 클래스에 프로토타입을 먼저 선언한 후, 클래스의 정의가 끝나면 헤더파일을 포함시켜야 한다.
    ```c++
    class B; // 프로토타입
    class A
    {
        ... // B와 관련된 내용
    };
    # include "B.hpp" // 이후에 헤더파일 포함
    ``` 

### const char*
* `char* str = "hello world!";`을 컴파일하면 `ISO C++11 does not allow conversion from string literal to 'char*'` 오류가 발생한다.
* 따라서 const를 붙여서, `const char* str = "hello world!";`와 같이 해주어야 한다.
* [ ] 한편, 여러줄의 선언은 다음과 같이 한다. 여러 방법이 있는 것 같다.
    ```
    const char *TREE =
    {
        "\n"
        "    oxoxoo    ooxoo \n"
        "  ooxoxo oo  oxoxooo \n"
        " oooo xxoxoo ooo ooox \n" 
        " oxo o oxoxo  xoxxoxo \n"
        "  oxo xooxoooo o ooo \n"
        "    ooo\\oo\\  /o/o \n"
        "        \\  \\/ / \n"
        "         |   / \n"
        "         |  | \n"
        "         | D| \n"
        "         |  | \n"
        "         |  | \n"
        "  ______/____\\____ \n"
    };
    ```

### 공부가 필요한 내용
* const 위치
    * 포인터에서의 const
    * 레퍼런스에서의 const
        * https://boycoding.tistory.com/208
* 매개변수나 반환값
    * 포인터? 레퍼런스? 복사본?
    * std::string의 경우?
* 복사생성자와 할당연산자 등의 작동 순서 및 원리
* 파일 입출력
    * \<fstream>, \<iostream> 등의 관계.
        * \<iostream>만 포함하면 ofstream같은 객체가 선언이 안된다.



## cpp06

### float vs double
* https://codingdog.tistory.com/entry/c%EC%96%B8%EC%96%B4-double%ED%98%95-vs-float%ED%98%95-%EC%96%B4%EB%96%A4-%EC%B0%A8%EC%9D%B4%EA%B0%80-%EC%9E%88%EC%9D%84%EA%B9%8C%EC%9A%94<br>
    > 정확도의 차이

### 변수 타입 확인
`std::cout << typeid(<변수>).name() << std::endl;`

### 소수점 자리수 출력
* https://pmoncode.tistory.com/20
* https://semaph.tistory.com/7
* https://boycoding.tistory.com/152
    > `std::cout << std::fixed; std::cout.precision(1);`

### 자료형의 크기 및 범위
* https://myblog.opendocs.co.kr/archives/1230
    > int는 4바이트, char는 1바이트.

### 동적 메모리 할당
* https://boycoding.tistory.com/204
* https://boycoding.tistory.com/205

### 캐스트, 캐스팅, 형변환
* https://eastroot1590.tistory.com/entry/C-%ED%83%80%EC%9E%85-%EC%BA%90%EC%8A%A4%ED%8C%85
* https://mynameisdabin.tistory.com/20
* https://doitnow-man.tistory.com/215

### 난수 생성
* https://modoocode.com/304
    > 다른 사람들의 풀이에서 rand()가 잘 보이지 않는 이유.

### 정수 제한
* https://docs.microsoft.com/ko-kr/cpp/c-language/cpp-integer-limits?view=vs-2019
    > C++ 표준 라이브러리 헤더 <limits>에 정수 제한 상수가 정의되어 있다.
* https://riptutorial.com/ko/cplusplus/example/15879/%EC%88%AB%EC%9E%90-%ED%98%95%EC%9D%98-%EB%B2%94%EC%9C%84
    > `std::numeric_limits<int>::min()`  
    > INT_MIN은 안되나? INT32_MIN, INT64_MIN 등은 뭐지? 내가 아는 int의 최소값은 INT32_MIN이던데...



## C++ 참고 사이트

### 공식
* https://en.cppreference.com/w/
* http://www.cplusplus.com/

### 준 공식
* https://www.ibm.com/support/knowledgecenter/ko/ssw_ibm_i_73/rzahg/rzahgcandcplus.htm
* https://riptutorial.com/ko/cplusplus


