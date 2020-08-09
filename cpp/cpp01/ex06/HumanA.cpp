/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:40:22 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/08 21:56:15 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon_(weapon)
{
    name_ = name;
    // weapon_ = weapon;
}

void HumanA::attack()
{
    std::cout << name_ + "attacks with his " + weapon_.getType() << std::endl;
}
