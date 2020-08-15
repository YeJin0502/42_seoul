/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 06:54:14 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/16 06:58:02 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
: Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant& ref)
{
    *this = ref; // 어느 방법이 낫나? 둘 중 하나만 해도 되나? 그럴 것 같은데...
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}

SuperMutant&
SuperMutant::operator = (const SuperMutant& ref)
{
    if (this != &ref)
        Enemy::operator = (ref);
    return (*this);
}

void
SuperMutant::takeDamage(int damage)
{
    Enemy::takeDamage(damage - 3); // 더 좋은 방법 있나?
}
