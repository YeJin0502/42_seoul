/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 06:23:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/16 06:54:07 by gmoon            ###   ########.fr       */
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

    public:
        Enemy();
        Enemy(int hp, std::string const & type);
        Enemy(const Enemy& ref);
        virtual ~Enemy();
        Enemy& operator = (const Enemy& ref);

        std::string const & getType() const;
        int getHP() const;

        virtual void takeDamage(int damage);
};

#endif