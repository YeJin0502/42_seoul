/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 06:27:07 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/16 06:33:51 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy()
{}

Enemy::Enemy(int hp, std::string const & type)
: hp_(hp), type_(type)
{}

Enemy::Enemy(const Enemy& ref)
: hp_(ref.hp_), type_(ref.type_)
{
    // *this = ref;
}

Enemy::~Enemy()
{}

Enemy&
Enemy::operator = (const Enemy& ref)
{
    if (this != &ref)
    {
        hp_ = ref.hp_;
        type_ = ref.type_;
    }
    return (*this);
}

std::string const &
Enemy::getType() const
{
    return (type_);
}

int
Enemy::getHP() const
{
    return (hp_);
}

void
Enemy::takeDamage(int damage)
{
    if (damage <= 0)
        return ;
    hp_ -= damage;
}
