/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:09:18 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/14 21:50:18 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:
        void miniontrap(std::string const& target);
        void meat_unicycle(std::string const& target);
        void funzerker(std::string const& target);
        void mechmagician(std::string const& target);
        void shhhh_trap(std::string const& target);

    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& ref); // const 안 붙이면 안되나? // 앞에 붙이는거랑 뒤에 붙이는게 다른가?
        ~FragTrap();
        FragTrap& operator = (const FragTrap& ref);

        void rangedAttack(std::string const& target);
        void meleeAttack(std::string const& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void vaulthunter_dot_exe(std::string const& target);
};

#endif