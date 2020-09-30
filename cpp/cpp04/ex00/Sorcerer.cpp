/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 00:15:48 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/30 17:17:55 by gmoon            ###   ########.fr       */
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
: name_(ref.name_), title_(ref.title_)
{
    std::cout << name_ + ", " + title_ + ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
    std::cout << name_ + ", " + title_ + ", is dead. Consequences will never be the same!" << std::endl;
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

void
Sorcerer::polymorph(Victim const &ref) // const Victim하고 다른가?
{
    ref.getPolymorphed();
}

const std::string& Sorcerer::get_name() const
// const std::string& Sorcerer::get_name() // 안됨.
// std::string& Sorcerer::get_name() const // 안됨.
{
    return (name_);
}

const std::string& Sorcerer::get_title() const
{
    return (title_);
}

std::ostream&
operator << (std::ostream& out, const Sorcerer& ref) // 출력 쪽을 잘 모름.
{
    out << "I am " << ref.get_name() << ", " << ref.get_title() << ", and I like ponies!" << std::endl;
    return (out); // 이렇게 하는건가?
}
