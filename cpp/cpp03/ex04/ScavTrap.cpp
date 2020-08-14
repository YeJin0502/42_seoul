/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 02:45:59 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/14 20:18:47 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name)
{
    hp_ = 100;
    max_hp_ = 100;
    energy_ = 50;
    max_energy_ = 50;
    level_ = 1;
    melee_attack_ = 20;
    ranged_attack_ = 15;
    armor_ = 3;

    std::cout << "ScavTrap " + name_ + "이(가) 생성되었습니다." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " + name_ + "이(가) 소멸합니다." << std::endl;
}

void
ScavTrap::challengeNewcomer()
{
    std::string newcomers[3] = {"athena", "nisha", "jack"};

    int index = rand() % 3;

    std::cout << newcomers[index] << "에게 도전합니다!" << std::endl;
}

void
ScavTrap::rangedAttack(std::string const& target)
{
    std::cout << "<ScavTrap> ";
    ClapTrap::rangedAttack(target);
}

void
ScavTrap::meleeAttack(std::string const& target)
{
    std::cout << "<ScavTrap> ";
    ClapTrap::meleeAttack(target);
}
