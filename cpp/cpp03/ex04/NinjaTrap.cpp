/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 18:46:00 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/14 22:01:05 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap()
: ClapTrap()
{
    hp_ = 60;
    max_hp_ = 60;
    energy_ = 120;
    max_energy_ = 120;
    level_ = 1;
    melee_attack_ = 60;
    ranged_attack_ = 5;
    armor_ = 0;

    std::cout << "NinjaTrap(이름 없음)이 생성되었습니다." << std::endl;
}

NinjaTrap::NinjaTrap(std::string name)
: ClapTrap(name)
{
    hp_ = 60;
    max_hp_ = 60;
    energy_ = 120;
    max_energy_ = 120;
    level_ = 1;
    melee_attack_ = 60;
    ranged_attack_ = 5;
    armor_ = 0;

    std::cout << "NinjaTrap " + name_ + "이(가) 생성되었습니다." << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap& ref)
{
    *this = ref;
}

NinjaTrap&
NinjaTrap::operator = (const NinjaTrap& ref)
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

NinjaTrap::~NinjaTrap()
{
    std::cout << "NinjaTrap " + name_ + "이(가) 소멸합니다." << std::endl;
}

void
NinjaTrap::ninjaShoebox(ClapTrap& trap)
{
    std::cout << "받아라 ClapTrap!" << std::endl;
    std::cout << name_ << "이 " << trap.get_name() << "에게 ninjaShoebox를 사용했습니다." << std::endl;
}

void
NinjaTrap::ninjaShoebox(FragTrap& trap)
{
    std::cout << "받아라 FragTrap!" << std::endl;
    std::cout << name_ << "이 " << trap.get_name() << "에게 ninjaShoebox를 사용했습니다." << std::endl;
}

void
NinjaTrap::ninjaShoebox(ScavTrap& trap)
{
    std::cout << "받아라 ScavTrap!" << std::endl;
    std::cout << name_ << "이 " << trap.get_name() << "에게 ninjaShoebox를 사용했습니다." << std::endl;
}

void
NinjaTrap::ninjaShoebox(NinjaTrap& trap)
{
    std::cout << "받아라 NinjaTrap!" << std::endl;
    std::cout << name_ << "이 " << trap.get_name() << "에게 ninjaShoebox를 사용했습니다." << std::endl;
}

void
NinjaTrap::rangedAttack(std::string const& target)
{
    std::cout << "<NinjaTrap> ";
    ClapTrap::rangedAttack(target);
}

void
NinjaTrap::meleeAttack(std::string const& target)
{
    std::cout << "<NinjaTrap> ";
    ClapTrap::meleeAttack(target);
}
