/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 03:27:35 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/14 21:55:40 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
    protected:
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
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& ref);
        virtual ~ClapTrap();
        ClapTrap& operator = (const ClapTrap& ref);

        virtual void rangedAttack(std::string const& target);
        virtual void meleeAttack(std::string const& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string get_name();
};

#endif