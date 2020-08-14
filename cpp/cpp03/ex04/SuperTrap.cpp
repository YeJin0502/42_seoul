/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:15:45 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/14 22:41:19 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap()
{
    hp_ = FragTrap::hp_;
    max_hp_ = FragTrap::hp_;
    energy_ = NinjaTrap::energy_;
    max_energy_ = NinjaTrap::max_energy_;
    level_ = 1;
    melee_attack_ = NinjaTrap::melee_attack_;
    ranged_attack_ = FragTrap::ranged_attack_;
    armor_ = FragTrap::armor_;

    std::cout << "SuperTrap(이름 없음)이 생성되었습니다." << std::endl;
}

SuperTrap::SuperTrap(std::string name)
: FragTrap(name), NinjaTrap(name)
{
    hp_ = FragTrap::hp_;
    max_hp_ = FragTrap::hp_;
    energy_ = NinjaTrap::energy_;
    max_energy_ = NinjaTrap::max_energy_;
    level_ = 1;
    melee_attack_ = NinjaTrap::melee_attack_;
    ranged_attack_ = FragTrap::ranged_attack_;
    armor_ = FragTrap::armor_;

    std::cout << "SuperTrap " + name_ + "이(가) 생성되었습니다." << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap& ref)
{
    *this = ref;
}

SuperTrap::~SuperTrap()
{
    std::cout << "SuperTrap " + name_ + "이(가) 소멸합니다." << std::endl;
}

SuperTrap&
SuperTrap::operator = (const SuperTrap& ref)
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
SuperTrap::rangedAttack(std::string const& target)
{
    FragTrap::rangedAttack(target);
}

void
SuperTrap::meleeAttack(std::string const& target)
{
    NinjaTrap::meleeAttack(target);
}
