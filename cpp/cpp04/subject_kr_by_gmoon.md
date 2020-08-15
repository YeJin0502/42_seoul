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

정말 꼼꼼한 경우, 몇 테스트를 더 만들 수 있습니다: 파생 클래스 추가 등... (아뇨, 이건 사실 제안이 아닙니다, 진짜로 해봐야해요.)

당연히, 평소와 같이, 테스트되지 않은 것은 채점되지 않습니다.

## Exercise 01: I don't want to set the world on fire

| Exercise : 01 |
| --- |
| 제출 디렉토리: ex01/ |
| 제출할 파일: AWeapon.[hpp,cpp], PlasmaRifle.[hpp,cpp], PowerFist.[hpp,cpp], Enemy.[hpp,cpp], SuperMutant.[hpp,cpp], RadScorpion.[hpp,cpp], Character.[hpp,cpp], main.cpp |
| 금지 함수: 없음 |

황무지에서는 많은 것을 찾을 수 있습니다. Bits of metal, strange chemicals, crosses between cowboys and homeless wannabe punks, but also a boatload of improbable (but funny!) weapons. And it’s about time too, I wanted to hit some stuff in the face today.

이 모든 쓰레기들 사이에서 살아남을 수 있도록, 몇 무기를 코딩하는 것으로 시작해야 합니다. 다음의 클래스들을 완성하고 구현하세요(Copline 형식을 잊지마세요...):

```
class AWeapon
{
    private:
        [...]
    public:
        AWeapon(std::string const & name, int apcost, int damage);
        [...] ~AWeapon();
        std::string [...] getName() const;
        int getAPCost() const;
        int getDamage() const;
        [...] void attack() const = 0;
};
```

정보:
* 무기에는 이름, 명중 시 가하는 데미지 포인트, AP(액션 포인트)의 슈팅 비용 등이 있습니다.
* 무기는 attack() 할 때 특정 소리와 발광 효과를 생성합니다. 이것은 상속 클래스에게 연기될 것입니다.

그 다음, 구체적인 클래스 PlasmaRifle과 PowerFist를 구현할 수 있습니다. 특징은 다음과 같습니다:

* PlasmaRifle:
    * Name: "Plasma Rifle"
    * Damege: 21
    * AP cost: 5
    * Output of attack(): "* piouuu piouuu piouuu *"
* PowerFist:
    * Name: "Power Fist"
    * Damage: 50
    * AP cost: 8
    * Output of attack(): "* pschhh... SBAM! *"

이제 놀 수 있는 반짝이는 무기들이 많으니, 싸울 적들이 필요합니다!

다음의 모델로 Enemy 클래스를 만드세요(Coplien 형식으로 완료해야 합니다...):

```
class Enemy
{
    private:
        [...]
    public:
        Enemy(int hp, std::string const & type);
        [...] ~Enemy();
        std::string [...] getType() const;
        int getHP() const;

        virtual void takeDamage(int);
};
```

제약:
* enemy는 여러 hp와 type을 가지고 있습니다.
* enemy는 (hp를 줄이는) 피해를 입을 수 있습니다. 데미지가 0보다 작으면, 아무 것도 하지 마세요.

그 다음 구체적인 enemy들을 구현할 것입니다.

첫번째로, SuperMutant입니다:
* HP: 170
* Type: "Super Mutant"
* On birth, displays: "Gaaah. Me want smash heads!"
* Upon death, displays: "Aaargh..."
* 3 데미지를 덜 받게 takeDamege를 오버로드.

RadScorpion입니다:
* HP: 80
* Type: "RadScorpion"
* On birth, displays: "* click click click *"
* Upon death, displays: "* SPROTCH *"

이제 무기도 적도 시험해볼 수 있으므로, 우리 자신만 존재하면 되겠죠.

따라서 Character 클래스를 다음의 모델로 만듭시다:
```
class Character
{
    private:
        [...]
    public:
        Character(std::string const & name);
        [...]
        ~Character();
        void recoverAP();
        void equip(AWeapon*);
        void attack(Enemy*);
        std::string [...] getName() const;
};
```

* 이름, AP, AWeapon(현재 무기를 가리키는 포인터)를 가집니다.
* 생성시 40AP를 배치하고, 사용할 때마다 보유한 무기에 해당하는 AP를 잃고 recoverAP() 때마다 최대 40AP까지 10AP씩 회복합니다. AP가 없으면, 공격도 못합니다.
* attack()을 호출하면 현재 무기의 attack()을 호출하기 전에 "NAME attacks ENEMY_TYPE with a WEAPON_NAME"을 표시합니다. 장착된 무기가 없으면 아무것도 하지 않습니다. 그 후 적의 HP에서 무기의 데미지만큼 뺍니다. 대상의 HP가 0이거나 더 낮으면, 삭제해야 합니다.
* equip()은 무기의 포인터를 저장합니다. 복사는 포함하지 않습니다.

또한 Character을의 속성을 표시하는 << 오버로드를 구현해야 합니다. 필요한 모든 getter 함수를 구현하세요. 이 오버로드는 다음을 표시합니다:<br>
`NAME has AP_NUMBER AP and wields a WEAPON_NAME`

장착된 무기가 없으면 다음을 표시합니다:<br>
`NAME has AP_NUMBER AP and is unarmed`