/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:35:27 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/10 04:00:35 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
    private:
        std::string name_;
        Weapon &weapon_; // 레퍼런스로 할 경우
        // Weapon *weapon_; // 포인터로 할 경우

    public:
        HumanA(std::string name, Weapon &weapon); // 레퍼런스로 할 경우
        // HumanA(std::string name, Weapon *weapon); // 포인터로 할 경우

        void attack();
};

#endif