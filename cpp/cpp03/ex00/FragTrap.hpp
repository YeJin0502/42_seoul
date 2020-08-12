/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:09:18 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/13 01:04:39 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>

class FragTrap
{
    private:
        int hp_;
        const int max_hp_; // const가 아닌가? 생각해보니 업그레이드하면 바뀔 수도 있는데.
        int energy_;
        const int max_energy_;
        int level_;
        const std::string name_;
        const int melee_attack_;
        const int ranged_attack_;
        const int armor_;

        void miniontrap(std::string const& target);
        void meat_unicycle(std::string const& target);
        void funzerker(std::string const& target);
        void mechmagician(std::string const& target);
        void shhhh_trap(std::string const& target);

    public:
        // FragTrap();
        FragTrap(std::string name);

        void rangedAttack(std::string const& target);
        void meleeAttack(std::string const& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void vaulthunter_dot_exe(std::string const& target);
};

#endif