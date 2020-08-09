/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:40:22 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/10 04:01:12 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

/* 레퍼런스로 할 경우 */

HumanA::HumanA(std::string name, Weapon &weapon) : weapon_(weapon)
{
    name_ = name;
    // weapon_ = weapon; // 레퍼런스는 나중에 초기화를 할 수 없다.
}

void HumanA::attack()
{
    std::cout << name_ + " attacks with his " + weapon_.getType() << std::endl;
}

/* 포인터로 할 경우 */

// HumanA::HumanA(std::string name, Weapon *weapon)
// {
//     name_ = name;
//     weapon_ = weapon;
// }

// void HumanA::attack()
// {
//     if (weapon_)
//         std::cout << name_ + " attacks with his " + weapon_->getType() << std::endl;
//     else
//         std::cout << name_ + " has no weapon" << std::endl;
// }
