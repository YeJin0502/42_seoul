/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 02:45:57 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/14 22:01:53 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap& ref);
        ~ScavTrap();
        ScavTrap& operator = (const ScavTrap& ref);

        void rangedAttack(std::string const& target);
        // 가상 함수, 가상 상속을 안해도... 포인터가 아니니까 다 되네.
        // 아직은 잘 모르겠음. 일단은 넘어가자.
        void meleeAttack(std::string const& target);

        void challengeNewcomer();
};

#endif