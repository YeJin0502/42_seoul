# C++ - Module 06
C++ Casts

## 일반 지침
cpp00과 동일

## 보너스 룰
각 문제에서, 모든 캐스트는 특정 캐스트에 의해 해결됩니다. 평가는 당신의 선택이 예상 캐스트와 일치하는지 확인합니다.

## Exercise 00: Scalar conversion

| Exercise : 00 |
| --- |
| 제출 디렉토리: ex00/ |
| 제출할 파일: Any file you need and a Makefile |
| 허용 함수: 문자열에서 int, float, double로 변환하는 모든 함수. 도움이 될 것이지만, 모든 일을 해주진 않을 것입니다. |

C++의 리터럴 값 (가장 일반적인 형식)의 문자열 표현을 매개변수로 취하는 프로그램을 작성하세요. 이 리터럴은 다음의 scalar 유형 중 하나에 속해야합니다: char, int, float, double. 십진수 표기법만 사용됩니다.

char 리터럴 값의 예: 'c', 'a'... 단순화하기 위해서, 이것에 주목하세요: 표시할 수 없는 문자는 프로그램에 매개변수로 전달할 수 없으며, char로의 변환을 표시할 수 없는 경우, 대신 알림을 출력합니다.

int 리터럴 값의 예: 0, -42, 42...

float 리터럴 값의 예: 0.0f, -4.2f, 4.2f... 과학을 위해 이러한 의사 리터럴도 허용합니다: -inff, +inff, nanf

double 리터럴 값의 예: 0.0, -4.2, 4.2... 재미로 이러한 의사 리터럴도 허용합니다: -inf, +inf, nan

프로그램은 리터럴의 유형을 감지하고, 올바른 타입의 리터럴을 획득한 다음 (따라서 더이상 문자열이 아님), 다른 세 가지 유형으로 명시적으로 변환하고 아래와 같은 형식으로 결과를 표시해야 합니다. 만약 변환이 의미가 없거나 오버플로우되면, 변환이 불가능함을 표시하세요. 당신은 숫자 제한이나 특수 값을 처리하기 위해 헤더를 추가할 수 있습니다.

예시:
```
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0
```