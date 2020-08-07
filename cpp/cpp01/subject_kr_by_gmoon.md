# C++ - Module 01

Memory allocation, References, Pointers to members, File streams

## 일반 지침

cpp00와 동일.

## Exercise 00: Heap of quadrupeds

| Exercies : 00 |
| --- |
| 제출 디렉토리: ex00/ |
| 제출할 파일: Pony.cpp Pony.hpp main.cpp |
| 금지 함수: 없음 |

포니를 적절하게 설명한다고 생각하는 것들을 포함하는 포니 클래스를 만드세요. 그 후 ponyOnTheHeap, ponyOnTheStack이라는 두 개의 함수를 만드세요. 이 함수는 포니를 할당하고 작업을 수행합니다.

당연히, 첫 번째 함수에서는 포니가 힙에 할당되어야 하고 두 번째 함수에서는 포니가 스택에 할당되어야 합니다.

당신은 당신이 의도한대로 잘 작동한다는 것을 증명하기 위해 충분한 코드를 메인 함수에 제공해야 합니다.

In both cases, the Pony objects must not exist after the function hands off control.
(Your main will also have to demonstrate this during the correction!)

## Exercise 01: Plumbing problem

| Exercies : 01 |
| --- |
| 제출 디렉토리: ex01/ |
| 제출할 파일: ex01.cpp |
| 금지 함수: 없음 |

다음 함수를 메모리 누수를 수정한 후 제출하세요.

당연히, 메모리 할당 및 해제를 해야합니다. 단순히 변수를 제거한다거나, 문제에 장난을 치는 것은 잘못된 답안으로 간주하겠습니다.

## Exercise 02: Plucking some brains

| Exercies : 02 |
| --- |
| 제출 디렉토리: ex02/ |
| 제출할 파일: ex02.cpp |
| 금지 함수: 없음 |

우선 **Zombie** 클래스를 만드세요. type과 name을 최소한 포함하고, **announce()** 멤버 함수를 추가하세요. 이 함수는 다음을 출력합니다: *<name (type)> Braiiiiiiinnnssss...*

실제로는 type과 name만 출력하면 어떤 내용이어도 상관은 없습니다.

그 후, **ZombieEvent** 클래스를 만드세요. 이 클래스는 객체의 타입을 저장하는 **setZombieType** 함수를 가집니다. 그리고 **Zombie* newZombie(std::string name)** 함수는 선택된 타입으로 좀비를 생성하고, 이름을 붙이고, 리턴합니다.

또한 **randomChump** 함수를 만들어야 합니다. 이 함수는 랜덤 이름을 가지는 좀비를 생성하고, announce합니다. 랜덤의 방법은 마음대로 정할 수 있습니다. 진짜로 랜덤한 이름이건, 일정 보기 중 랜덤을 선택하는 것이건, 상관 없습니다.

당신은 당신이 만든 것이 제대로 작동하는지 증명해 줄 main이 포함된 완전한 프로그램을 제출해야 합니다. 예를 들어, 새로 만들어진 좀비들이 announce하게 하세요.

이제 진짜 요점입니다: 당신의 좀비들은 적절한 시기에 파괴되어야 합니다(즉 더이상 그들이 필요하지 않을 때). 또한 좀비들은 적절한 방식으로 할당되어야 합니다. 어떤 때에는 스택에 할당하는 것이 적절할 것이고, 어떨 때에는 힙이 더 나을 것입니다. 당신은 점수를 얻기 위해 왜 그런 선택을 했는지 정당화해야 합니다.

## Exercise 03: Moar brainz!

| Exercies : 03 |
| --- |
| 제출 디렉토리: ex03/ |
| 제출할 파일: Zombie.cpp Zombie.hpp ZombieHorde.cpp ZombieHorde.hpp main.cpp |
| 금지 함수: 없음 |

앞에서 만들었던 Zombie 클래스를 다시 사용해서 ZombieHorde 클래스를 만드세요.

이 클래스는 정수 N을 사용하는 생성자를 가질 것입니다. 생성 시, 랜덤한 이름을 가진 N개의 좀비 객체를 할당하고 저장해야 합니다. 그 후 각 좀비 객체에 대해 announce() 함수를 호출하는 announce() 함수를 가집니다.

당신은 모든 좀비 객체를 단일 할당해야 하며, ZombieHorde가 파괴될 때 해제하여야 합니다. (You must allocate all the Zombie objects in a single allocation, and release them when the ZombieHorde it destroyed.)

평소처럼 메인에 테스트를 제공하고 당신의 선택을 정당화하십시오.

## Exercise 04: HI THIS IS BRAIN

| Exercies : 04 |
| --- |
| 제출 디렉토리: ex04/ |
| 제출할 파일: ex04.cpp |
| 금지 함수: 없음 |

"HI THIS IS BRAIN" 문자열을 포인터로, 레퍼런스로 가리키는 프로그램을 만드세요.

포인터를 이용해 출력하고, 레퍼런스를 이용해 출력하세요.

## Exercise 05: HI BRAIN THIS IS HUMAN

| Exercies : 05 |
| --- |
| 제출 디렉토리: ex05/ |
| 제출할 파일: Brain.cpp Brain.hpp Human.cpp Human.hpp main.cpp |
| 금지 함수: 없음 |

