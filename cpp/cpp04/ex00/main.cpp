/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 00:25:39 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/30 23:59:08 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int main()
{
    std::cout << "==============================" << std::endl;

    Sorcerer robert("Robert", "the Magnificent");

    Victim jim("Jimmy");
    Peon joe("Joe");

    std::cout << robert << jim << joe;

    robert.polymorph(jim);
    robert.polymorph(joe);

    std::cout << "==============================" << std::endl;

    Victim* pP = new Peon("pP");
    Victim* pV = new Victim("pV");

    pP->getPolymorphed();
    pV->getPolymorphed();

    delete pP;
    delete pV;

    std::cout << "==============================" << std::endl;

    Victim* test1 = new Peon("test1");
    Peon test2(*(Peon*)test1);

    std::cout << test2;

    std::cout << "==============================" << std::endl;
}
