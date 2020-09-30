/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 05:33:00 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 00:10:03 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon()
{}

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
:   name_(name),
    apcost_(apcost),
    damage_(damage)
{}

AWeapon::AWeapon(const AWeapon& ref)
{
    *this = ref;
}

AWeapon&
AWeapon::operator = (const AWeapon& ref)
{
    if (this != &ref)
    {
        name_ = ref.getName();
        apcost_ = ref.getAPCost();
        damage_ = ref.getDamage();
    }
    return (*this);
}

AWeapon::~AWeapon()
{}

std::string
AWeapon::getName() const
{
    return (name_);
}

int
AWeapon::getAPCost() const
{
    return (apcost_);
}

int
AWeapon::getDamage() const
{
    return (damage_);
}
