/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 02:45:59 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/13 03:15:45 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
: max_hp_(100), max_energy_(50), name_(name), melee_attack_(20), ranged_attack_(15), armor_(3)
{
    hp_ = 100;
    energy_ = 50;
    level_ = 1;

    std::cout << "ScavTrap " + name_ + "이(가) 생성되었습니다." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " + name_ + "이(가) 소멸합니다." << std::endl;
}

void
ScavTrap::rangedAttack(std::string const& target)
{
    std::cout << "ScavTrap " + name_ + "이(가) ";
    std::cout << target + "을(를) 범위 공격합니다." << std::endl;
    std::cout << ranged_attack_ << "의 데미지를 입혔습니다." << std::endl;
}

void
ScavTrap::meleeAttack(std::string const& target)
{
    std::cout << "ScavTrap " + name_ + "이(가) ";
    std::cout << target + "을(를) melee 공격합니다." << std::endl;
    std::cout << melee_attack_ << "의 데미지를 입혔습니다." << std::endl;
}

void
ScavTrap::takeDamage(unsigned int amount)
{
    int damage = amount - armor_;
    if (damage < 0) damage = 0;

    hp_ -= damage;
    if (hp_ < 0) hp_ = 0;

    std::cout << "ScavTrap " + name_ + "이(가) ";
    std::cout << damage << "의 데미지를 입었습니다." << std::endl;
    std::cout << "남은 hp는 " << hp_ << "입니다." << std::endl;
}

void
ScavTrap::beRepaired(unsigned int amount)
{
    hp_ += amount;
    if (hp_ > max_hp_) hp_ = max_hp_;

    energy_ += amount;
    if (energy_ > max_energy_) energy_ = max_energy_;

    std::cout << "ScavTrap " + name_ + "이(가) ";
    std::cout << amount << "만큼 회복합니다." << std::endl;
    std::cout << "남은 hp는 " << hp_ << "입니다." << std::endl;
    std::cout << "남은 energy는 " << energy_ << "입니다." << std::endl;
}

void
ScavTrap::challengeNewcomer()
{
    std::string newcomers[3] = {"athena", "nisha", "jack"};

    int index = rand() % 3;

    std::cout << newcomers[index] << "에게 도전합니다!" << std::endl;
}
