/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 08:16:28 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 16:07:02 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include "Squad.hpp"

int main()
{
    // ISpaceMarine *bob = new TacticalMarine; // 업 캐스팅?
    // ISpaceMarine *jim = new AssaultTerminator;

    // ISquad *vlc = new Squad;
    // vlc->push(bob);
    // vlc->push(jim);
    // for (int i = 0; i < vlc->getCount(); ++i)
    // {
    //     ISpaceMarine *cur = vlc->getUnit(i);
    //     cur->battleCry();
    //     cur->rangedAttack();
    //     cur->meleeAttack();
    // }
    // delete vlc;

    std::cout << "==================== my test1 ====================" << std::endl;
    ISpaceMarine *gmoon = new TacticalMarine;
    ISpaceMarine *seo = new TacticalMarine();
    // ISpaceMarine *kim = new TacticalMarine(*gmoon); // 이런 식으로는 안됨.
    // ISpaceMarine *kim = new TacticalMarine(*(TacticalMarine *)gmoon); // 이런 식으로.
    ISquad *cadet = new Squad;

    cadet->push(gmoon);
    cadet->push(seo);

    std::cout << ">> Squad's size is " << cadet->getCount() << std::endl;

    for (int i = 0; i < cadet->getCount(); i++)
    {
        cadet->getUnit(i)->battleCry();
        cadet->getUnit(i)->rangedAttack();
        cadet->getUnit(i)->meleeAttack();
    }

    std::cout << "==================== my test2 ====================" << std::endl;
    ISpaceMarine *kim = new AssaultTerminator;
    ISquad *piscine = new Squad(*(Squad *)cadet);

    piscine->push(kim);
    std::cout << ">> Squad's size is " << piscine->getCount() << std::endl;
    piscine->push(kim);
    std::cout << ">> Squad's size is " << piscine->getCount() << std::endl;

    for (int i = 0; i < piscine->getCount(); i++)
        piscine->getUnit(i)->battleCry();

    if (piscine->getUnit(2))
        std::cout << ">> index2 unit is exist." << std::endl;
    if (piscine->getUnit(3))
        std::cout << ">> is index3 unit exist?" << std::endl;

    std::cout << "==================== my test3 ====================" << std::endl;

    Squad test;
    test = *(Squad*)piscine;

    for (int i = 0; i < test.getCount(); i++)
        test.getUnit(i)->battleCry();
    
    std::cout << "==================== my test4 ====================" << std::endl;

    delete cadet;
    delete piscine;

    std::cout << "==================== my test5 ====================" << std::endl;
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
