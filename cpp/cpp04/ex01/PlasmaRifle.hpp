/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 06:01:03 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 00:11:00 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
    public:
        PlasmaRifle();
        PlasmaRifle(const PlasmaRifle& ref);
        PlasmaRifle& operator = (const PlasmaRifle& ref);
        virtual ~PlasmaRifle();

        virtual void attack() const;
};

#endif