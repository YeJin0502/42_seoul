/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:09:18 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/14 21:56:18 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
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
        FragTrap(const FragTrap& ref);
        ~FragTrap();
        FragTrap& operator = (const FragTrap& ref);

        virtual void rangedAttack(std::string const& target);
        virtual void meleeAttack(std::string const& target);

        void vaulthunter_dot_exe(std::string const& target);
};

#endif