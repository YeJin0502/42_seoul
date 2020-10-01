/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:44:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 15:19:48 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
: _xp(0)
{}

AMateria::AMateria(std::string const & type)
: _type(type), _xp(0)
{}

AMateria::AMateria(const AMateria& ref)
{
    *this = ref;
}

AMateria&
AMateria::operator = (const AMateria& ref)
{
    if (this != &ref)
    {
        // _type = ref._type;
        _xp = ref._xp;
    }
    return (*this);
}

AMateria::~AMateria()
{}

std::string const &
AMateria::getType() const
{
    return (_type);
}

unsigned int
AMateria::getXP() const
{
    return (_xp);
}

void
AMateria::use(ICharacter& target)
{
    _xp += 10;
    (void) target;
}
