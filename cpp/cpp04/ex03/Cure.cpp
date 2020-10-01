/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 23:17:34 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 15:18:08 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
:    AMateria("cure")
{}

Cure::Cure(const Cure& ref)
:    AMateria("cure")
{
    *this = ref;
}

Cure&
Cure::operator = (const Cure& ref)
{
    // if (this != &ref)
    // {
    //     _type = ref.getType();
    //     _xp = ref.getXP();
    // }
    AMateria::operator = (ref);
    return (*this);
}

Cure::~Cure()
{}

AMateria*
Cure::clone() const
{
    return (new Cure(*this));
}

void
Cure::use(ICharacter& target)
{
    AMateria::use(target);
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
