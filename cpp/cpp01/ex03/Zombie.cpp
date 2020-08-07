/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:29:52 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 21:25:57 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    // 꼭 이렇게 빈 칸이라도 만들어줘야 하나?
}

Zombie::Zombie(std::string name)
{
    name_ = name;
}

Zombie::Zombie(std::string name, std::string type)
{
    name_ = name;
    type_ = type;
}

void Zombie::announce()
{
    std::cout << "<" + name_ + " (" + type_ + ")> ";
    std::cout << "Braiiiiiiinnnssss..." << std::endl;
}

void Zombie::set_name(std::string name)
{
    name_ = name;
}

void Zombie::set_type(std::string type)
{
    type_ = type;
}
