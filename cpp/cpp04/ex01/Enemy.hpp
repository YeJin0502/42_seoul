/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 06:23:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 00:31:12 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy
{
    private:
        int hp_;
        std::string type_;
        Enemy();

    public:
        Enemy(int hp, std::string const & type);
        Enemy(const Enemy& ref);
        Enemy& operator = (const Enemy& ref);
        virtual ~Enemy();

        std::string getType() const;
        int getHP() const;

        virtual void takeDamage(int damage);
};

#endif