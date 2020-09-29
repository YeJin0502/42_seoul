
<details>
<summary>정리 필요</summary>

# cpp00: 네임스페이스, 클래스, 멤버 함수, 표준입출력 스트림, 초기화 리스트, static, const...

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



# cpp01: 메모리 할당, 레퍼런스, 포인터, 파일 스트림

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



# cpp02: Ad-hoc 다형성(오버라이딩), 연산자 오버로드, 캐노니컬 클래스

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



# cpp03: 상속

### switch case
* https://boycoding.tistory.com/186
* https://studymake.tistory.com/129

### const
* https://dhna.tistory.com/25 : const 위치에 따른 동작
* https://www.cppkorea.org/CppCoreGuidelines/Const/ : c++ 핵심 가이드라인 - const
* https://dydtjr1128.github.io/cpp/2020/01/08/Cpp-const.html

### 상속
* https://wikidocs.net/21857 : 다른 것들도 볼만할 듯. 글들이 짧고 코드 위주라 좋음.



# cpp04: 다형성, 추상 클래스, 인터페이스

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



# cpp05: 예외

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
    ```c++
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



# cpp06: 캐스트(형변환)

### 캐스트, 캐스팅
* https://eastroot1590.tistory.com/entry/C-%ED%83%80%EC%9E%85-%EC%BA%90%EC%8A%A4%ED%8C%85
* https://mynameisdabin.tistory.com/20
* https://doitnow-man.tistory.com/215

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

### 난수 생성
* https://modoocode.com/304
    > 다른 사람들의 풀이에서 `rand()`가 잘 보이지 않는 이유.

### 정수 제한
* https://docs.microsoft.com/ko-kr/cpp/c-language/cpp-integer-limits?view=vs-2019
    > C++ 표준 라이브러리 헤더 `<limits>`에 정수 제한 상수가 정의되어 있다.
* https://riptutorial.com/ko/cplusplus/example/15879/%EC%88%AB%EC%9E%90-%ED%98%95%EC%9D%98-%EB%B2%94%EC%9C%84
    > `std::numeric_limits<int>::min()`  
    > `INT_MIN`은 안되나? `INT32_MIN`, `INT64_MIN` 등은 뭐지? 내가 아는 int의 최소값은 `INT32_MIN`이던데...



# cpp07: 템플릿

### 템플릿
* https://thrillfighter.tistory.com/408
    > 템플릿이란? 함수나 클래스를 만들 수 있는 틀.

    > 템플릿 문법
    > ```c++
    > template <typename T>
    > T myFunc(T a, T b)
    > {
    >     return a + b;
    > }
    > ```

### 템플릿 사용
* `myfunc<int>(a, b)`
* `myfunc(a, b)`
* `::myfunc(a, b)`
* 첫 번째는 std::stirng을 넣는 경우, `error: call to 'swap' is ambiguous` 오류가 뜨는 경우가 있었음. 왜?
* 두 번째는 컴파일러가 알아서 자료형을 판별한다고 함.
* 세 번째는 두 번째랑 같은 것 아닐까? 네임스페이스가 없어서 저런 형태가 아닐까 추측.

### 함수 포인터
* https://boycoding.tistory.com/233
* https://m.blog.naver.com/PostView.nhn?blogId=tipsware&logNo=221619466275&proxyReferer=https:%2F%2Fwww.google.com%2F
* https://aahc.tistory.com/17
    > 함수의 이름 자체가 하나의 함수 포인터. (그래서 매개변수로 넘겨줄 수 있는건가?)

    > 함수 포인터는 참조하거나 역참조해도 여전히 같은 기능을 수행함.
    > ```c++
    > // 아래는 전부 같은 기능을 하는 코드임.
    > fun_ptr = &fun;
    > fun_ptr = fun;
    > fun_ptr = *fun;
    > fun_ptr = **fun;
    > ```

### 클래스 템플릿
* http://tcpschool.com/cpp/cpp_template_class
* https://blockdmask.tistory.com/45
    > 멤버함수가 클래스 외부에서 선언되면, 다시 템플릿 선언을 해주어야 함.
    > ```c++
    > template <typename T>
    > Array<T>::Array()
    > {
    >     ...
    > }
    > ```

### [] 연산자 오버로딩
* https://www.qaupot.com/wordpress/?p=2304

### typename vs class
* https://hashcode.co.kr/questions/554/%ED%85%9C%ED%94%8C%EB%A6%BF%EC%97%90%EC%84%9C-typename%ED%82%A4%EC%9B%8C%EB%93%9C%EC%99%80-class%ED%82%A4%EC%9B%8C%EB%93%9C%EC%9D%98-%EC%B0%A8%EC%9D%B4

### 클래스 템플릿의 멤버함수는 헤더파일에서 구현
* cpp 파일을 따로 만들어서 구현하면 `undefined reference to `Array<int>::Array(unsigned int)'`의 에러가 뜬다.
* 따라서 헤더파일 내에서 멤버함수를 구현해야 하는 듯.

### 배열의 기본 초기화
```c++
int* a = new int;
std::cout << *a << std::endl; // 0으로 초기화
// std::cout << a << std::endl; // int* a의 주소

char* b = new char;
std::cout << (int) *b << std::endl; // 0으로 초기화
```
기본으로 0으로 초기화된다.

### int* array = new int[0];
* https://stackoverflow.com/questions/1087042/c-new-int0-will-it-allocate-memory
* https://roybatty.tistory.com/14
    > `int* array = new int[0];`은 크기가 0인 배열(NULL이 아님) 할당. 그러나 역참조(*array)의 동작은 정의되어 있지 않음.  

    > `delete[]`는 NULL에 대해 동작 취하지 않으므로 안전(권장하지는 않음). 크기가 0인 배열 또한 안전.

    > 그런데 왜 안전하다면 ex02의 생성자에서 `delete[] array_;`를 하면 에러가 나는거지?
    > ```
    > Array<T>::Array()
    > {
    >     if (array_) // array_는 클래스 생성시 생성되므로, 항상 존재하는 것 아닌가? 항상 통과하는 조건문?
    >         delete[] array_; // 안전하다면 왜 delete[]하면 seg fault가 뜨지?
    >     size_ = 0;
    >     array_ = new T[0]; // 빈 배열이 뭐지?
    >     // array_ = nullptr; // 위하고 차이가 뭐지?
    > }
    > ```
* 빈 배열이 뭘까? 할당에 실패하면 nullptr이 되나? 그래서 nullptr이 아니고 값은 없는 걸 빈 배열이라고 하는건가?

### 동적 할당
* 왜 에러가 안날까?
    ```c++
    int* int_array = new int[0];
    int_array[0] = 1;
    int_array[1] = 2;
    int_array[3] = 3; // 에러가 안난다?

    std::cout << int_array[3] << std::endl; // 에러가 안난다? 왜?
    ```
* https://egg-money.tistory.com/161



# cpp08: 컨테이너, 반복자(iterator), 알고리즘

### exception 클래스
* https://docs.microsoft.com/ko-kr/cpp/standard-library/exception-class?view=vs-2019

### C++ 표준 라이브러리 컨테이너
* https://docs.microsoft.com/ko-kr/cpp/standard-library/stl-containers?view=vs-2019
* https://min-zero.tistory.com/entry/C-STL-2-1-%EB%B0%98%EB%B3%B5%EC%9E%90-%EB%B0%98%EB%B3%B5%EC%9E%90iterator
    > 컨테이너, 반복자, 알고리즘 종류

### array
* https://boycoding.tistory.com/213

### map
* https://blockdmask.tistory.com/87
* https://twpower.github.io/91-how-to-use-map-in-cpp
    > pair 객체로 다룬다. `it->first`, `it->second` 이런 식으로 key나 value에 접근.
* https://hugman.tistory.com/entry/C-map%EC%97%90%EC%84%9C-find-%EB%A5%BC-%EC%9D%B4%EC%9A%A9%ED%95%B4%EC%84%9C-%EC%97%86%EB%8A%94-%ED%95%AD%EB%AA%A9-%EC%B0%BE%EA%B8%B0
    > map의 find 메서드 사용법
* https://en.cppreference.com/w/cpp/utility/pair
    > pair 객체

### sort
* https://blockdmask.tistory.com/178

### stack
* https://kldp.org/node/71479
    > stack이나 queue는 컨테이너에 대한 접근을 제한하는 어댑터. 즉, 컨테이너 어댑터이다.
* https://stackoverflow.com/questions/38136137/does-stack-have-iterators-in-c
    > stack에는 반복자가 없으나, 상속을 통해 protected 멤버인 c(the underlying container)에 접근해서 반복자를 사용하는 클래스를 만들 수 있음. (예제 포함)
* https://docs.microsoft.com/ko-kr/cpp/standard-library/stack-class?view=vs-2019
    > container_type이란 기본 컨테이너. 즉 `std::deque<T>` 인 듯?

### auto
* https://boycoding.tistory.com/184
    > 값에 맞춰서 변수의 형식이 자동으로 결정되는 타입 추론 기능.

### iterator
* https://egg-money.tistory.com/200
* https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=60208809639&proxyReferer=https:%2F%2Fwww.google.com%2F
* `begin()`, `cbegin()`, `rbegin()`, `crbegin`
    * `cbegin()`: const_iterator 반환. 포인터는 변경 가능하나, 포인터가 가르키는 값이 변경 불가능.
        ```c++
        auto it = mst.cbegin();
        std::cout << *it << std::endl;
        it++; // 변경 가능.
        std::cout << *it << std::endl;
        // *it += 10; // 포인터가 가르키는 값 변경 불가능(컴파일 에러).
        ```
    * `rbegin`: 뒤집어진 순서로 반환.
        ```c++
        // mst에 {1,2,3} 저장된 상태
        for (auto it = mst.rbegin(); it < mst.rend(); it++)
            std::cout << *it << std::endl; // 3 2 1 출력
        ```

### ipp 확장자
* https://simcho999.blogspot.com/2018/01/c-cpp-h-hpp-c.html
    > 헤더의 정의는 hpp, 템플릿의 정의는 tpp, 인라인 함수 정의는 ipp에?



# C++ 참고 사이트

### 공식
* https://en.cppreference.com/w/
* http://www.cplusplus.com/

### 준 공식
* https://www.ibm.com/support/knowledgecenter/ko/ssw_ibm_i_73/rzahg/rzahgcandcplus.htm
* https://riptutorial.com/ko/cplusplus
* https://modoocode.com/143

### 그 외
* https://boycoding.tistory.com/category/C%2B%2B%20%EC%9D%B4%EC%95%BC%EA%B8%B0