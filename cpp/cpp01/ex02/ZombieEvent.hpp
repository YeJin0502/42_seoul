/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:31:38 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 19:20:44 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <iostream>
# include "Zombie.hpp"

class ZombieEvent
{
    std::string type_;

    public:
        void    setZombieType(std::string type);
        Zombie  *newZombie(std::string name);
        Zombie  *randomChump();
};

#endif