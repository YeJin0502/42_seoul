/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 01:37:50 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/16 03:36:31 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim()
{

}

Victim::Victim(std::string name)
: name_(name)
{
    std::cout << "Some random victim called " + name_ + " just appeared!" << std::endl;
}

Victim::Victim(const Victim& ref)
: name_(ref.name_)
{
    std::cout << "Some random victim called " + name_ + " just appeared!" << std::endl;
}

Victim::~Victim()
{
    std::cout << "Victim " + name_ + " just died for no apparent reason!" << std::endl;
}

Victim&
Victim::operator = (const Victim& ref)
{
    if (this != &ref) // this랑 *this 헷갈림. // &ref 대신 ref 하면 안되나?
    {
        name_ = ref.name_;
    }
    return (*this);
}

const std::string&
Victim::get_name() const
{
    return (name_);
}

void
Victim::getPolymorphed() const
{
    std::cout << name_ + " has been turned into a cute little sheep!" << std::endl;
}

std::ostream&
operator << (std::ostream& out, const Victim& ref)
{
    out << "I'm " + ref.get_name() + " and I like otters!" << std::endl;
    return (out);
}
