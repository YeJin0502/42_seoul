## cpp05

### const 멤버변수
* 값이 고정된 멤버변수.
* 일반 변수의 맨 앞에 const가 붙는다.
    * 포인터나 레퍼런스에서는 얘기가 좀 다를 듯?
* 따라서 생성자에서 먼저 초기화(`{}` 바깥에서)하고, 이후 불변.
* 복사생성자에서도 먼저 초기화.
    ```c++
    Form::Form(const Form& ref)
    throw(GradeTooHighException, GradeTooLowException)
    :   name_(ref.name_),
        grade_for_sign_(validGrade(ref.grade_for_sign_)),
        grade_for_exec_(validGrade(ref.grade_for_exec_)) // 먼저 초기화
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
* 한편, 여러줄의 선언은 다음과 같이 한다. 여러 방법이 있는 것 같다.
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
* [ ] const, char 등에 대한 여러 공부 필요.

---

* [ ] const 위치
    * 포인터에서의 const
    * 레퍼런스에서의 const
        * https://boycoding.tistory.com/208

* [ ] 매개변수나 반환값
    * 포인터? 레퍼런스? 복사본?
    * std::string의 경우?

* [ ] 복사생성자와 할당연산자 등의 작동 순서 및 원리

* [ ] 파일 입출력
    * \<fstream>, \<iostream> 등의 관계.
        * \<iostream>만 포함하면 ofstream같은 객체가 선언이 안된다.

* [ ] 생성자 리스트
    * https://psychoria.tistory.com/11