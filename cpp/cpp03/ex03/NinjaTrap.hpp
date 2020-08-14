/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 05:04:08 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/14 21:59:26 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
{
    public:
        NinjaTrap();
        NinjaTrap(std::string name);
        NinjaTrap(const NinjaTrap& ref);
        ~NinjaTrap();
        NinjaTrap& operator = (const NinjaTrap& ref);

        virtual void rangedAttack(std::string const& target);
        virtual void meleeAttack(std::string const& target);

        void ninjaShoebox(ClapTrap& trap);
        void ninjaShoebox(FragTrap& trap);
        void ninjaShoebox(ScavTrap& trap);
        void ninjaShoebox(NinjaTrap& trap);
};

#endif