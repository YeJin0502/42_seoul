/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:26:10 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 21:28:46 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    std::string name_;
    std::string type_;
    
    public:
        Zombie();
        Zombie(std::string name);
        Zombie(std::string name, std::string type);

        void    announce();
        void    set_name(std::string name);
        void    set_type(std::string type);
};

#endif