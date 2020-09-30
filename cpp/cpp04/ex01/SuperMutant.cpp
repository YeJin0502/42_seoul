/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 06:54:14 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 01:13:42 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant()
:   Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant& ref)
:   Enemy(ref.getHP(), ref.getType())
{
    // *this = ref;
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant&
SuperMutant::operator = (const SuperMutant& ref)
{
    Enemy::operator = (ref);
    return (*this);
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}

void
SuperMutant::takeDamage(int damage)
{
    Enemy::takeDamage(damage - 3);
}
