/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 05:25:17 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/16 05:57:24 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class AWeapon
{
    private:
        // std::string const & name_; // const를 잘 모름.
        std::string name_;
        int apcost_;
        int damage_;

    public:
        AWeapon();
        AWeapon(std::string const & name, int apcost, int damage);
        // const를 잘 모름. 참조 매개변수로 줄 때, 주로 const를 붙이던데...
        AWeapon(const AWeapon& ref);
        // const가 앞에 오는거랑 뒤에 오는거랑 차이가 있나?
        virtual ~AWeapon();
        AWeapon& operator = (const AWeapon& ref);

        // std::string getName() const;
        std::string const & getName() const;
        // 이걸 모르겠음 계속... 리턴을 그냥 하는 것과, const &를 하는 것과, &를 하는 것..?
        int getAPCost() const;
        int getDamage() const;
        virtual void attack() const = 0; // = 0 은 순수 가상 함수. 구현부에 구현하면 안됨.
};

#endif

// 450p
// 순수 가상 함수를 하나 이상 가지는 클래스는 추상 클래스.
// 추상 클래스는 인스턴스화 불가능. 상속을 위한 기본 클래스