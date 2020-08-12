/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 02:45:57 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/13 03:04:16 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class ScavTrap
{
    private:
        int hp_;
        const int max_hp_;
        int energy_;
        const int max_energy_;
        int level_;
        const std::string name_;
        const int melee_attack_;
        const int ranged_attack_;
        const int armor_;

    public:
        // FragTrap();
        ScavTrap(std::string name);
        ~ScavTrap();

        void rangedAttack(std::string const& target);
        void meleeAttack(std::string const& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void challengeNewcomer();
};

#endif