/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:35:27 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/08 21:57:03 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
    private:
        std::string name_;
        Weapon      &weapon_; // 레퍼런스가 아니면 안되나?

    public:
        HumanA(std::string name, Weapon &weapon);
        void        attack();
};

#endif