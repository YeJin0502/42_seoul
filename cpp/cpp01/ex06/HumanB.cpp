/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 03:36:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/10 03:47:06 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    name_ = name;
    weapon_ = 0;
}

void HumanB::setWeapon(Weapon &weapon)
{
    weapon_ = &weapon;
}

void HumanB::attack()
{
    if (weapon_)
        std::cout << name_ + " attacks with his " + weapon_->getType() << std::endl;
    else
        std::cout << name_ + " has no weapon" << std::endl;
}
