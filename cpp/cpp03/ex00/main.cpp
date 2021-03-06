/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 00:23:00 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/13 00:58:00 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
    srand(time(0));
    FragTrap fragtrap("David");
    
    fragtrap.rangedAttack("Athena");
    std::cout << std::endl;
    fragtrap.meleeAttack("Wilhelm");
    std::cout << std::endl;
    fragtrap.takeDamage(10);
    std::cout << std::endl;
    fragtrap.beRepaired(20);
    std::cout << std::endl;
    fragtrap.vaulthunter_dot_exe("gmoon");
}
