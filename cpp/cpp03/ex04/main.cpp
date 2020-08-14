/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:23:00 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/14 20:26:10 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main()
{
    srand(time(0));

    std::cout << "=======================" << std::endl;

    FragTrap fragtrap("Frag");
    
    std::cout << std::endl;
    fragtrap.rangedAttack("Athena");
    std::cout << std::endl;
    fragtrap.meleeAttack("Wilhelm");
    std::cout << std::endl;
    fragtrap.takeDamage(10);
    std::cout << std::endl;
    fragtrap.beRepaired(20);
    std::cout << std::endl;
    fragtrap.vaulthunter_dot_exe("gmoon");

    std::cout << "=======================" << std::endl;

    ScavTrap scavtrap("Scav");

    std::cout << std::endl;
    scavtrap.rangedAttack("Athena");
    std::cout << std::endl;
    scavtrap.meleeAttack("Wilhelm");
    std::cout << std::endl;
    scavtrap.takeDamage(90);
    std::cout << std::endl;
    scavtrap.beRepaired(50);
    std::cout << std::endl;
    scavtrap.challengeNewcomer();

    std::cout << "=======================" << std::endl;

    NinjaTrap ninja("Ninja");

    std::cout << std::endl;
    ninja.ninjaShoebox(scavtrap);
    std::cout << std::endl;
    ninja.ninjaShoebox(fragtrap);

    std::cout << "=======================" << std::endl;

    SuperTrap super("Super");
    
    std::cout << std::endl;
    super.rangedAttack("Athena");
    std::cout << std::endl;
    super.meleeAttack("Wilhelm");

    std::cout << "=======================" << std::endl;

    // std::cout << std::endl;
}
