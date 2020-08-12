/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:23:00 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/13 03:14:40 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    srand(time(0));

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
    std::cout << std::endl;

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
    std::cout << std::endl;
}
