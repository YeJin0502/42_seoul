/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:44:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/14 23:33:28 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
: _type(nullptr), _xp(0) // 맞나? 문자열을 잘 모름.
{

}

AMateria::AMateria(std::string const & type)
: _type(type), _xp(0)
{

}

AMateria::AMateria(const AMateria& ref)
{
    *this = ref;
}

AMateria&
AMateria::operator = (const AMateria& ref)
{
    if (this != &ref)
    {
        _type = ref._type; // 임시
        _xp = ref._xp;
    }
    return (*this);
}

AMateria::~AMateria()
{
    
}

std::string const &
AMateria::getType() const
{
    return (_type); // &이나 const &를 잘 모르겠다.
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
