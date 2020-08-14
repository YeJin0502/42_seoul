/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 02:45:57 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/14 21:46:45 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>

class ScavTrap
{
    private:
        int hp_;
        int max_hp_;
        int energy_;
        int max_energy_;
        int level_;
        std::string name_;
        int melee_attack_;
        int ranged_attack_;
        int armor_;

    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& ref);
        ~ScavTrap();
        ScavTrap& operator = (const ScavTrap& ref);

        void rangedAttack(std::string const& target);
        void meleeAttack(std::string const& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void challengeNewcomer();
};

#endif