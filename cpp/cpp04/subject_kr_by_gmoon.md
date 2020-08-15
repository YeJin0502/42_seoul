# C++ - Module 04

Subtype polymorphism, abstract classes, interfaces

## 일반 지침

cpp00과 동일.

## Exercise 00: Polymorphism, or "When the sorcerer thinks you'd be cuter as a sheep"

| Exercise : 00 |
| --- |
| 제출 디렉토리: ex00/ |
| 제출할 파일: Sorcerer.hpp, Sorcerer.cpp, Victim.hpp, Victim.cpp, Peon.hpp, Peon.cpp, main.cpp |
| 금지 함수: 없음 |

다형성은 메이지, 소서러, 허풍쟁이들의 시대까지 거슬러 올라가는 오랜 전통입니다. 우리가 먼저 시도했다고 생각하게 만들 수도 있지만, 그건 거짓말이죠!

장엄한 소서러인 우리의 친구 Ro/b/ert에게 집중해봅시다.

로버트는 흥미로운 취미를 가지고 있습니다. 그가 손 위에 얹을 수 있는 모든 것을 양, 조랑말, 수달 및 기타 불가능한 것들로 변형시키는 것이죠. 

name과 title을 가지는 Sorcerer 클래스를 만드는 것으로 시작하겠습니다. 소서러 name과 title을 매개변수로 가지는 생성자를 가집니다. (이 순서대로요.)

이 클래스는 매개변수들 없이 인스턴스화 될 수 없습니다. (이건 말이 안돼요! name이나 title이 없는 소서러를 생각해 보세요...) 그러나 여전히 Coplien 형식을 사용할 수 있습니다. 맞아요, 다시 이곳에는 함정이 숨어있습니다. 우리는 이렇게 계락을 좋아하죠.

소서러가 탄생하면, 다음을 표시합니다:<br>
`NAME, TITLE, is born!`<br>
(당연히, 당신은 NAME과 TITLE을 소서러의 이름과 타이틀로 대체해야겠죠.)

그가 죽으면, 다음을 표시합니다:<br>
`NAME, TITLE, is dead. Consequences will never be the same!`

소서러는 자기 자신을 소개할 수 있습니다:<br>
`I am NAME, TITLE, and I like ponies!`

그는 모든 출력 스트림으로 자기 자신을 소개할 수 있습니다. << 연산자 오버로드 덕분에 말이죠. (friend의 사용은 금지입니다. 필요한 모든 getter을 추가하세요!)

우리의 소서러는 이제 아침에 곰 발톱과 트롤 주스 사이에서 자신을 즐겁게 해줄 희생자가 필요합니다.

그러므로 당신은 Victim 클래스를 만들어야 합니다. 소서러와 비슷하게 이름이 있고, 이 이름을 매개변수로 취하는 생성자를 가집니다.

희생자가 태어나면, 다음을 표시합니다:<br>
`Some random victim called NAME just appeard!`

죽으면, 다음을 표시합니다:<br>
`Victim NAME just died for no apparent reason!`

희생자도 자기 자신을 소개할 수 있습니다:<br>
`I'm NAME and I like otters!`

우리의 희생자는 소서러에 의해 "다형성화"될 수 있습니다. `void getPolymorphed() const` 함수를 추가하고, 다음을 표시하세요:<br>
`NAME has been turned into a cute little sheep!`

또한 Sorcerer에 `void polymorph(Victim const &)`을 추가해서, 사람들을 변형시킬 수 있게 하세요.

이제, 약간의 다양성을 추가하기 위해, 소서러는 일반적인 희생자 뿐 아니라 다른 것도 변형시키고자 합니다. 문제 없어요, 조금만 더 만들면 됩니다!

Peon 클래스를 만드세요.

💡 Peon은 희생자입니다. 그러니...

태어나면, 그는 "Zog zog."를 말할 것입니다. 죽을 때에는 "Bleuark..."를 말하고요. (팁: 예시를 보세요. 이건 그리 단순하지 않습니다...) Peon은 다음과 같이 다형성화됩니다:<br>
`NAME has been turned into a pink pony!`

다음의 코드가 컴파일 될 것이고, 다음의 결과를 출력합니다:

```c++
int main()
{
    Sorcerer robert("Robert", "the Magnificent");

    Victim jim("Jimmy");
    Peon joe("Joe");

    std::cout << robert << jim << joe;

    robert.polymorph(jim);
    robert.polymorph(joe);

    return 0;
}
```

```
$> clang++ -W -Wall -Werror *.cpp
$> ./a.out | cat -e
Robert, the Magnificent, is born!$
Some random victim called Jimmy just appeared!$
Some random victim called Joe just appeared!$
Zog zog.$
I am Robert, the Magnificent, and I like ponies!$
I'm Jimmy and I like otters!$
I'm Joe and I like otters!$
Jimmy has been turned into a cute little sheep!$
Joe has been turned into a pink pony!$
Bleuark...$
Victim Joe just died for no apparent reason!$
Victim Jimmy just died for no apparent reason!$
Robert, the Magnificent, is dead. Consequences will never be the same!$
$>
```

정말 꼼꼼한 경우, 몇 테스트를 더 만들 수 있습니다: 파생 클래스 추가 등... (아뇨, 이건 사실 제안이 아닙니다, 진짜로 해야해요.)

당연히, 평소와 같이, 테스트되지 않은 것은 채점되지 않습니다.