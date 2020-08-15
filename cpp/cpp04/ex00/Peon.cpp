/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:57:33 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/16 04:44:15 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon()
{

}

Peon::Peon(std::string name)
: Victim(name)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon& ref)
: Victim(ref)
// : Victim(ref.name_)
{
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

// Peon&
// Peon::operator = (const Peon& ref)
// {
//     if (this != &ref)
//     {
//         name_ = ref.name_;
//     }
//     return (*this);
// }

void
Peon::getPolymorphed() const
{
    std::cout << name_ + " has been turned into a pink pony!" << std::endl;
}