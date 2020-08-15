/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 07:08:58 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/16 07:59:01 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Character::Character()
// {} // 있어야하나? 그게 기본 형식인가? 그렇다면 어떻게 구현해야?

Character::Character(std::string const & name)
: name_(name), ap_(40), weapon_(NULL)
{}

Character::Character(const Character& ref)
{
    *this = ref; // 이건 얕은 복사라 문제가 되지 않을까? 그럼 어떻게 해야?
    // 어떤 경우에 문제가 생기는지를 main 문으로 테스트해서 봐야.
}

Character::~Character()
{
    // 무기 delete 해줘야하나? 모르겠는데.
}

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
    if (!weapon_ || !enemy) // 맞나?
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

std::string const &
Character::getName() const
{
    return (name_);
}

AWeapon*
Character::getWeapon() const
{
    return (weapon_);
}

int const &
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
