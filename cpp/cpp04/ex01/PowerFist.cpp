/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 06:18:09 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 00:31:55 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist()
:   AWeapon("Power Fist", 8, 50)
{}

PowerFist::PowerFist(const PowerFist& ref)
:   AWeapon(ref.getName(), ref.getDamage(), ref.getAPCost())
{}

PowerFist&
PowerFist::operator = (const PowerFist& ref)
{
    AWeapon::operator = (ref);
    return (*this);
}

PowerFist::~PowerFist()
{}

void
PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}
