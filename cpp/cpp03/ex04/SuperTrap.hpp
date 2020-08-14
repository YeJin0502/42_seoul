/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:13:38 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/14 22:39:37 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
    public:
        SuperTrap();
        SuperTrap(std::string name);
        SuperTrap(const SuperTrap &ref);
        ~SuperTrap();
        SuperTrap& operator = (const SuperTrap& ref);

        virtual void rangedAttack(std::string const& target);
        virtual void meleeAttack(std::string const& target);
};

#endif