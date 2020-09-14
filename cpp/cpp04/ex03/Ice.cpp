/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:20:40 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/14 23:27:44 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
: AMateria("ice")
{

}

Ice::Ice(const Ice& ref)
{
    *this = ref;
}

Ice&
Ice::operator = (const Ice& ref)
{
    // if (this != &ref)
    // {
    //     _type = ref._type;
    //     _xp = ref_xp;
    // }
    AMateria::operator = (ref);
    return (*this);
}

Ice::~Ice()
{
    
}

Ice*
Ice::clone() const
{
    return (new Ice(*this));
}

void
Ice::use(ICharacter& target)
{
    AMateria::use(target);
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
