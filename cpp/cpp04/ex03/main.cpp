/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 23:15:39 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/15 00:02:08 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// #include "IMateriaSource.hpp"
// #include "ICharacter.hpp"

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    // IMateriaSource* src = new MateriaSource();
    // src->learnMateria(new Ice());
    // src->learnMateria(new Cure());

    // ICharacter* me = new Character("me");

    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);

    // ICharacter* bob = new Character("bob");

    // me->use(0, *bob);
    // me->use(1, *bob);

    // delete bob;
    // delete me;
    // delete src;

    std::cout << "============ my test============" << std::endl;

    IMateriaSource* src = new MateriaSource;
    src->learnMateria(new Ice);
    src->learnMateria(new Cure);

    ICharacter* gmoon = new Character("gmoon");
    ICharacter* kim = new Character("kim");

    AMateria* tmp;
    // std::cout << "zz" << std::endl;
    tmp = src->createMateria("ice");
    gmoon->equip(tmp);
    tmp = src->createMateria("cure");
    gmoon->equip(tmp);

    AMateria* test = new Ice;
    gmoon->equip(test);

    gmoon->use(0, *kim);
    gmoon->use(1, *kim);
    gmoon->use(1, *kim);
    gmoon->use(2, *kim);
    gmoon->use(2, *kim);
    gmoon->use(2, *kim);

    std::cout << test->getXP() << std::endl;

    gmoon->unequip(2);
    gmoon->use(2, *kim);

    delete src;
    delete gmoon;
    delete kim;
    delete test;

    return 0;
}
