/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 06:18:09 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/16 06:20:26 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist()
: AWeapon("Power Fist", 50, 8)
{}

PowerFist::PowerFist(const PowerFist& ref)
{
    *this = ref;
}

PowerFist::~PowerFist()
{}

PowerFist&
PowerFist::operator = (const PowerFist& ref)
{
    if (this != &ref)
        AWeapon::operator=(ref);
    return (*this);
}

void
PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}
