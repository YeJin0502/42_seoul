/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 21:06:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 21:40:28 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include <iostream>
# include "Zombie.hpp"

class ZombieHorde
{
    int         n_;
    // std::string type_;
    Zombie      *zombies_; // 왜 일중포인터?

    public:
        ZombieHorde(int n);
        ZombieHorde(int n, std::string type);
        ~ZombieHorde();
        void    announce();
};

#endif