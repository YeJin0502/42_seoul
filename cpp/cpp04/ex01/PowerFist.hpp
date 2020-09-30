/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 06:16:19 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 00:24:13 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
    public:
        PowerFist();
        PowerFist(const PowerFist& ref);
        PowerFist& operator = (const PowerFist& ref);
        virtual ~PowerFist();

        virtual void attack() const;
};

#endif