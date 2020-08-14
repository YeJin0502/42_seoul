# cpp03

\# FR4G-TP
* https://namu.wiki/w/CL4P-TP/%EC%9E%91%EC%A4%91%20%EB%82%B4%EC%97%AD
* https://www.giantbomb.com/fragtrap/3005-19706/

\# c++ switch case
* https://boycoding.tistory.com/186
* https://studymake.tistory.com/129

\# const
* https://dhna.tistory.com/25 : const 위치에 따른 동작
* https://dydtjr1128.github.io/cpp/2020/01/08/Cpp-const.html : const 위치에 따른 동작 2

\# 상속
* https://wikidocs.net/21857 : 다른 것들도 볼만할 듯. 글들이 짧고 코드 위주라 좋음.

---

* [] 멤버 변수를 어떤 식으로 초기화하면 좋은지
    * {} 내에서? 아니면 그 전에 :로? (:의 검색 키워드는 뭘까.) 두 방법이 무슨 차이가 있는 것일까.
* [] const
    * 인스턴스의 고유한 값을 const 값으로 멤버 변수에 선언하는게 아닌가? ex03의 ClapTrap.hpp에 자세히 적혀있는 궁금증.
    * 변경할 수 없는 변수를 선언하고 싶은데 어떻게 해야하는 것일까? 이런 경우를 const로 하는 것이 맞는건가? const 변수는 생성자 실행 전에 멤버 초기화로 넣어주어야 하는 것으로 알고 있는데, 그러면 결국 생성자에 매개변수로 전달되어야만 하는 것이 아닌가? 어떻게 매개변수로 전달 받지 않는 멤버 변수를 고정시키지? max_hp_같은 것을 매개변수로 받는 생성자는 이상하지 않은가... 아예 생성자 밖에서 초기화하는건가?
    * const int 와 int const 는 다른가?
* [] std::ostream& 을 반환하는 함수