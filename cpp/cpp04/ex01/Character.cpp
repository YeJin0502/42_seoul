/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 07:08:58 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 01:26:00 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{}

Character::Character(std::string const & name)
: name_(name), ap_(40), weapon_(NULL)
{}

Character::Character(const Character& ref)
{
    *this = ref;
}

Character::~Character()
{}

Character&
Character::operator = (const Character& ref)
{
    if (this != &ref)
    {
        name_ = ref.name_;
        ap_ = ref.ap_;
        weapon_ = ref.weapon_;
    }
    return (*this);
}

void
Character::recoverAP()
{
    ap_ += 10;
    if (ap_ > 40) ap_ = 40;
}

void
Character::equip(AWeapon* weapon)
{
    weapon_ = weapon;
}

void
Character::attack(Enemy* enemy)
{
    if (!weapon_ || !enemy)
        return ;
    else if (ap_ - weapon_->getAPCost() < 0)
        return ;
    ap_ -= weapon_->getAPCost();
    std::cout << name_ + " attacks " + enemy->getType() + " with a " + weapon_->getName() << std::endl;
    weapon_->attack();
    enemy->takeDamage(weapon_->getDamage());
    if (enemy->getHP() <= 0)
        delete enemy;
}

std::string
Character::getName() const
{
    return (name_);
}

AWeapon*
Character::getWeapon() const
{
    return (weapon_);
}

int
Character::getAP() const
{
    return (ap_);
}

std::ostream&
operator << (std::ostream& out, const Character& ref)
{
    if (!ref.getWeapon())
        out << ref.getName() + " has " << ref.getAP() << " AP and is unarmed" << std::endl;
    else
        out << ref.getName() + " has " << ref.getAP() << " AP and wields a " + ref.getWeapon()->getName() << std::endl;
    return (out);
}
