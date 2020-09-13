/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 08:16:28 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/13 23:32:13 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"

int main()
{
    ISpaceMarine *bob = new TacticalMarine;
    ISpaceMarine *jim = new AssaultTerminator;

    ISquad *vlc = new Squad;
    vlc->push(bob);
    vlc->push(jim);
    for (int i = 0; i < vlc->getCount(); ++i)
    {
        ISpaceMarine *cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    delete vlc;

    std::cout << "==================== my test1 ====================" << std::endl;
    ISpaceMarine *gmoon = new TacticalMarine;
    ISpaceMarine *seo = new TacticalMarine(); // 위와 아래는 무슨 차이?
    // ISpaceMarine *kim = new TacticalMarine(*gmoon); // 이런 식으로는 안됨.
    // ISpaceMarine *kim = new TacticalMarine(*(TacticalMarine *)gmoon); // 이런 식으로 되는 듯? 유닛들은 멤버 변수가 없어 의미가 없으므로, 스쿼드에서 테스트.
    ISquad *cadet = new Squad;

    cadet->push(gmoon);
    cadet->push(seo);
    for (int i = 0; i < cadet->getCount(); i++)
    {
        cadet->getUnit(i)->battleCry();
        cadet->getUnit(i)->rangedAttack();
        cadet->getUnit(i)->meleeAttack();
    }

    std::cout << "==================== my test2 ====================" << std::endl;
    ISpaceMarine *kim = new AssaultTerminator;
    ISquad *piscine = new Squad(*(Squad *)cadet);

    std::cout << ">> Squad's size is " << piscine->push(kim) << std::endl;
    piscine->push(kim);
    for (int i = 0; i < piscine->getCount(); i++)
    {
        piscine->getUnit(i)->battleCry();
        piscine->getUnit(i)->rangedAttack();
        piscine->getUnit(i)->meleeAttack();
    }

    if (piscine->getUnit(2))
        std::cout << ">> 2nd unit is exist." << std::endl;
    if (piscine->getUnit(3))
        std::cout << ">> is 3rd unit exist?" << std::endl;

    delete cadet;
    delete piscine;

    return 0;
}

/*
Tactical Marine ready for battle!$
* teleports from space *$
For the holy PLOT!$
* attacks with a bolter *$
* attacks with a chainsword *$
This code is unclean. PURIFY IT!$
* does nothing *$
* attacks with chainfists *$
Aaargh...$
I'll be back...$
*/
