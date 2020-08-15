/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 06:02:03 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/16 06:21:02 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle()
: AWeapon("Plasma Rifle", 21, 5)
{}

PlasmaRifle::PlasmaRifle(const PlasmaRifle& ref)
// : AWeapon("Plasma Rifle", 21, 5) // 해야 하나?
{
    *this = ref;
}

PlasmaRifle::~PlasmaRifle()
{}

PlasmaRifle&
PlasmaRifle::operator = (const PlasmaRifle& ref)
{
    if (this != &ref)
        AWeapon::operator=(ref);
        // 캐노니컬에 맞춰야 해서 만들지만, 안 만들어도 돌아가나? 된다면 왜? 함수 취급..?
    return (*this);
}

void
PlasmaRifle::attack() const
{
    std::cout <<  "* piouuu piouuu piouuu *" << std::endl;
}
