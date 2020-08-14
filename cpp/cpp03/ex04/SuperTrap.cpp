/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:15:45 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/14 20:14:32 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name)
: ClapTrap(name), FragTrap(name), NinjaTrap(name) // 이렇게 하면 되나?
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

SuperTrap::~SuperTrap()
{
    std::cout << "SuperTrap " + name_ + "이(가) 소멸합니다." << std::endl;
}

void
SuperTrap::rangedAttack(std::string const& target)
{
    // std::cout << "<NinjaTrap> ";
    FragTrap::rangedAttack(target);
}

void
SuperTrap::meleeAttack(std::string const& target)
{
    // std::cout << "<NinjaTrap> ";
    NinjaTrap::meleeAttack(target);
}
