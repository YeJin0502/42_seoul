/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 05:04:08 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/14 19:53:44 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap
// class NinjaTrap : public ClapTrap
{
    public:
        NinjaTrap(std::string name);
        ~NinjaTrap();

        void ninjaShoebox(ClapTrap& trap);
        void ninjaShoebox(FragTrap& trap);
        void ninjaShoebox(ScavTrap& trap);
        void ninjaShoebox(NinjaTrap& trap);
};

#endif