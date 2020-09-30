/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 05:25:17 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 00:35:29 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class AWeapon
{
    private:
        std::string name_;
        int apcost_;
        int damage_;
        AWeapon();

    public:
        AWeapon(const std::string& name, int apcost, int damage);
        AWeapon(const AWeapon& ref);
        AWeapon& operator = (const AWeapon& ref);
        virtual ~AWeapon();

        std::string getName() const;
        int getAPCost() const;
        int getDamage() const;
        
        virtual void attack() const = 0; // = 0 은 순수 가상 함수. 구현부에 구현하면 안됨.
};

#endif