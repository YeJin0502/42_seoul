/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:53:07 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 21:03:00 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

void ZombieEvent::setZombieType(std::string type)
{
    type_ = type;
}

Zombie *ZombieEvent::newZombie(std::string name)
{
    return (new Zombie(name, type_));
}

Zombie *ZombieEvent::randomChump()
{
    std::string name;
    Zombie  *ret;

    name = "aaaaa"; // 이런 방법 말고 좋은 방법이 있을텐데... append 같은거 안되나?
    for (int i = 0; i < 5; i++)
        name[i] = 'a' + rand() % 26;
    ret = new Zombie(name, type_);
    ret->announce();
    return (ret);
}
