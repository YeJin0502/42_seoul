/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 07:01:28 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 01:14:51 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion()
:   Enemy(80, "RadScorpion")
{
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion& ref)
:   Enemy(ref.getHP(), ref.getType())
{
    // *this = ref;
    std::cout << "* click click click *" << std::endl;
}

RadScorpion&
RadScorpion::operator = (const RadScorpion& ref)
{
    Enemy::operator = (ref);
    return (*this);
}

RadScorpion::~RadScorpion()
{
    std::cout << "* SPROTCH *" << std::endl;
}
