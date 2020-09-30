/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 06:02:03 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 00:36:58 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle()
:   AWeapon("Plasma Rifle", 5, 21)
{}


PlasmaRifle::PlasmaRifle(const PlasmaRifle& ref)
:   AWeapon(ref.getName(), ref.getDamage(), ref.getAPCost())
{} // 기본생성자가 private이면 이런 식으로.

/*
PlasmaRifle::PlasmaRifle(const PlasmaRifle& ref)
{
    *this = ref;
} // 기본생성자가 public이면 이런 식으로.
*/

PlasmaRifle&
PlasmaRifle::operator = (const PlasmaRifle& ref)
{
    // if (this != &ref)
        // AWeapon::operator = (ref);
    AWeapon::operator = (ref); // 어짜피 함수 내에 조건문이 있으므로.
    return (*this);
}

PlasmaRifle::~PlasmaRifle()
{}

void
PlasmaRifle::attack() const
{
    std::cout <<  "* piouuu piouuu piouuu *" << std::endl;
}
