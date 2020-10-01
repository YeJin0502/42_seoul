/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:51:56 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 16:14:35 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    _inven = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        _inven[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& ref)
{
    _inven = new AMateria*[4];
    for (int i = 0; i < 4; i++)
        _inven[i] = nullptr;
    *this = ref;
}

MateriaSource&
MateriaSource::operator = (const MateriaSource& ref)
{
    if (this != &ref)
    {
        if (_inven)
            delInven();
        _inven = new AMateria*[4];
        for (int i = 0; i < 4; i++)
            if (ref._inven[i])
                _inven[i] = ref._inven[i];
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    if (_inven)
        delInven();
}

void
MateriaSource::learnMateria(AMateria* mate)
{
    if (!mate)
        return ; // 맞나?
    for (int i = 0; i < 4; i++)
    {
        if (!_inven[i])
        {
            _inven[i] = mate;
            return ;
        }
    }
}

AMateria*
MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (_inven[i]->getType() == type)
        {
            return (_inven[i]->clone());
        }
    }
    // return (0);
    return (nullptr);
}

void
MateriaSource::delInven()
{
    for (int i = 0; i < 4; i++)
    {
        if (_inven[i])
            delete _inven[i];
    }
    delete[] _inven;
}
