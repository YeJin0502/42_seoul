/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 05:33:00 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/16 06:40:12 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon()
{}

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
: name_(name), apcost_(apcost), damage_(damage)
{}

AWeapon::AWeapon(const AWeapon& ref) // 복사연산자를 항상 모르겠음.
// : name_(ref.getName()), apcost_(ref.getAPCost()), damage_(ref.getDamage())
: name_(ref.name_), apcost_(ref.apcost_), damage_(ref.damage_) // 이렇게 해도 되나?
{
    // *this = ref;
    // 이런 방법도 있는데... 뭐가 더?
}

AWeapon::~AWeapon()
{}

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

std::string const &
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