/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:08:08 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/08 20:49:47 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{

}

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
} // 그냥 레퍼런스와 const 레퍼런스는 무슨 차이가 있지? 무슨 용도이지?
