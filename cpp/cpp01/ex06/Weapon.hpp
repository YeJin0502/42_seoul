/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:09:55 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/10 03:49:22 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CPP
# define WEAPON_CPP

# include <iostream>

class Weapon
{
    private:
        std::string type_;

    public:
        Weapon();
        Weapon(std::string type);

        void setType(std::string type);
        const std::string& getType();
        // 들여쓰기를 어떻게 해야 깔끔하지? 두 줄로 분리해야 하나?
        // const의 표기는 어디에 하는 것이?
};

#endif