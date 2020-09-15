# C++ - Module 05

Week 1 revisions, Exceptions

## 일반 지침

앞과 동일.

## 특별 규칙

클래스는 요구가 없어도 캐노니컬 폼으로 작성되어야 합니다.

## Exercise 00: Mommy, when I grow up, I want to be a bureaucrat !

| Exercise : 00 |
| --- |
| 제출 디렉토리: ex00/ |
| 제출할 파일: Bureaucrat.hpp Bureaucrat.cpp main.cpp |
| 금지 함수: 없음 |
| 비고: 없음 |

오늘, 우리는 회사, 복도, 양식 및 줄을 서서 기다리는 인공적인 악몽을 만들어 볼 것입니다. 재밌어보이죠? 아니라고요? 안됐군요.

우선, 광활한 기계의 가장 작은 톱니바퀴인 관료부터 시작합니다.

이것은 constant name을 가져야하고, 1(가능한 제일 높은)부터 150(가능한 제일 낮은) 범위의 grade를 가져야합니다. 유효하지 않은 등급으로 관료를 생성하려는 시도는 예외를 던져야 합니다. 이는 `Bureaucrat::GradeTooHighException` 또는 `Bureaucrat::GradeTooLowException`이 될 것입니다.

이 두가지 속성에 대해 getter를 제공합니다(getName과 getGrade). 그리고 grade를 낮추거나 높이는 두 함수를 제공합니다. 이 두 함수는 마찬가지로 성적이 너무 높거나 낮은 경우, 예외를 던집니다. 기억하세요. grade 1이 가장 높고 150이 가장 낮으므로, 3을 올리면 2가 됩니다...

던지는 예외는 다음과 같이 블록에서 캐치할 수 있어야 합니다:
```
try
{
    /* do some stuff with bureaucrats */
}
catch (std::exception & e)
{
    /* handle exception */
}
```

ostream에 <name>과 <grade>를 출력하는 << 연산자 오버로딩을 제공해야 합니다.

당연히, 적절한 메인문도 제출하세요.

## Exercise 01: Form up, maggots !

| Exercise : 01 |
| --- |
| 제출 디렉토리: ex01/ |
| 제출할 파일: Same as before + Form.cpp Form.hpp |
| 금지 함수: 없음 |
| 비고: 없음 |

이제 관료들이 있으니, 그들에게 그들의 시간과 관련된 무언가를 주는 것이 좋습니다. 