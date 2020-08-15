/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 07:40:58 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/16 08:00:34 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "RadScorpion.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main()
{
    Character* me = new Character("me");

    std::cout << *me;
    std::cout << "==============" << std::endl;

    Enemy* b = new RadScorpion();

    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();

    me->equip(pr);
    std::cout << *me;
    me->equip(pf);
    std::cout << "==============" << std::endl;

    me->attack(b);
    std::cout << *me;
    std::cout << "==============" << std::endl;

    me->equip(pr);
    std::cout << *me;
    std::cout << "==============" << std::endl;

    me->attack(b);
    std::cout << *me;
    std::cout << "==============" << std::endl;

    me->attack(b);
    std::cout << *me;
    std::cout << "==============" << std::endl;

    return 0;
}

// 기본은 되게 했는데, 추가는 나중에 하자. 공부하면서...