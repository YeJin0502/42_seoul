/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 00:15:48 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/30 23:34:31 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
{}

Sorcerer::Sorcerer(std::string name, std::string title)
:   name_(name),
    title_(title)
{
    std::cout << name_ + ", " + title_ + ", is born!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &ref)
{
    *this = ref;
    std::cout << name_ + ", " + title_ + ", is born!" << std::endl;
}

Sorcerer&
Sorcerer::operator = (const Sorcerer& ref)
{
    if (this != &ref)
    {
        name_ = ref.name_;
        title_ = ref.title_;
    }
    return (*this);
}

Sorcerer::~Sorcerer()
{
    std::cout << name_ + ", " + title_ + ", is dead. Consequences will never be the same!" << std::endl;
}

std::string Sorcerer::get_name() const
// const std::string& Sorcerer::get_name() const
{
    return (name_);
}

std::string Sorcerer::get_title() const
{
    return (title_);
}

void
Sorcerer::polymorph(Victim const &ref)
{
    ref.getPolymorphed();
}

std::ostream&
operator << (std::ostream& out, const Sorcerer& ref)
{
    out << "I am " << ref.get_name() << ", " << ref.get_title() << ", and I like ponies!" << std::endl;
    return (out);
}
