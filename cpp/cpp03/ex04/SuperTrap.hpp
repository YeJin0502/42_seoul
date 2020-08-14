/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 19:13:38 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/14 20:11:32 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

// class SuperTrap : virtual public FragTrap, virtual public NinjaTrap
// 여기서만 해도 되나? 이렇게 하면 생성자에서 초기화할때 모호하다고 잘 안됨.
class SuperTrap : public FragTrap, public NinjaTrap
{
    public:
        SuperTrap(std::string name);
        ~SuperTrap();

        virtual void rangedAttack(std::string const& target);
        virtual void meleeAttack(std::string const& target);
};

#endif