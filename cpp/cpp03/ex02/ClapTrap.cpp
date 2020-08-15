/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 03:29:36 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/14 21:55:17 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    hp_ = 100;
    max_hp_ = 100;
    energy_ = 100;
    max_energy_ = 100;
    level_ = 1;
    melee_attack_ = 30;
    ranged_attack_ = 20;
    armor_ = 5;

    std::cout << "ClapTrap(이름 없음)이 생성되었습니다." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: name_(name)
{
    hp_ = 100;
    max_hp_ = 100;
    energy_ = 100;
    max_energy_ = 100;
    level_ = 1;
    melee_attack_ = 30;
    ranged_attack_ = 20;
    armor_ = 5;

    std::cout << "ClapTrap " + name_ + "이(가) 생성되었습니다." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref)
{
    *this = ref;

    std::cout << "ClapTrap " + name_ + "이(가) 생성되었습니다." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " + name_ + "이(가) 소멸합니다." << std::endl;
}

ClapTrap&
ClapTrap::operator = (const ClapTrap& ref)
{
    if (this != &ref)
    {
        hp_ = ref.hp_;
        max_hp_ = ref.max_hp_;
        energy_ = ref.energy_;
        max_energy_ = ref.max_energy_;
        level_ = ref.level_;
        melee_attack_ = ref.melee_attack_;
        ranged_attack_ = ref.ranged_attack_;
        armor_ = ref.armor_;
    }
    return (*this);
}

void
ClapTrap::rangedAttack(std::string const& target)
{
    std::cout << name_ + "이(가) " + target + "에게 범위 공격합니다." << std::endl;
    std::cout << ranged_attack_ << "의 데미지를 입혔습니다." << std::endl;
}

void
ClapTrap::meleeAttack(std::string const& target)
{
    std::cout << name_ + "이(가) " + target + "에게 melee 공격합니다." << std::endl;
    std::cout << melee_attack_ << "의 데미지를 입혔습니다." << std::endl;
}

void
ClapTrap::takeDamage(unsigned int amount)
{
    int damage = amount - armor_;
    if (damage < 0) damage = 0;

    hp_ -= damage;
    if (hp_ < 0) hp_ = 0;

    std::cout << name_ + "이(가) " << damage << "의 데미지를 입었습니다." << std::endl;
    std::cout << "남은 hp는 " << hp_ << "입니다." << std::endl;
}

void
ClapTrap::beRepaired(unsigned int amount)
{
    hp_ += amount;
    if (hp_ > max_hp_) hp_ = max_hp_;

    energy_ += amount;
    if (energy_ > max_energy_) energy_ = max_energy_;

    std::cout << name_ + "이(가) " << amount << "만큼 회복합니다." << std::endl;
    std::cout << "남은 hp는 " << hp_ << "입니다." << std::endl;
    std::cout << "남은 energy는 " << energy_ << "입니다." << std::endl;
}

std::string
ClapTrap::get_name()
{
    return (name_);
}
