/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:51:49 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 16:16:45 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    _inven = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        _inven[i] = nullptr; // 초기화 해줘야.
}

Character::Character(std::string const & name)
:   _name(name)
{
    _inven = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        _inven[i] = nullptr;
}

Character::Character(const Character& ref)
{
    _inven = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        _inven[i] = nullptr;
    *this = ref;
}

Character&
Character::operator = (const Character& ref)
{
    if (this != &ref)
    {
        if (_inven)
            delInven();
        _inven = new AMateria*[4];
        for (int i = 0; i < 4; i++)
        {
            if (ref._inven[i])
                _inven[i] = ref._inven[i];
        }
        _name = ref._name;
    }
    return (*this);
}

Character::~Character()
{
    if (_inven)
        delInven();
}

std::string const &
Character::getName() const
{
    return (_name);
}

void
Character::equip(AMateria* m)
{
    if (!m)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (!_inven[i])
        {
            _inven[i] = m;
            return ;
        }
    }
}

void
Character::unequip(int idx)
{
    _inven[idx] = nullptr;
}

void
Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3 || !_inven[idx])
        return ;
    _inven[idx]->use(target);
}

void
Character::delInven()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inven[i])
            delete _inven[i];
    }
    delete[] _inven;
}
