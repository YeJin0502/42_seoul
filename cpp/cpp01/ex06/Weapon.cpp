/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:08:08 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/08 18:26:35 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Weapon::Weapon()
// {

// }

Weapon::Weapon(std::string type)
{
    type_ = type;
}

void Weapon::setType(std::string type)
{
    type_ = type;
}

const std::string& Weapon::getType()
{
    std::string& ret = type_;
    return (ret);
}
