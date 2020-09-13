/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 20:12:29 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/13 22:46:20 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
    std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator& ref)
{
    std::cout << "* teleports from space *" << std::endl;
    *this = ref;
}

AssaultTerminator&
AssaultTerminator::operator = (const AssaultTerminator& ref)
{
    (void) ref;
    return (*this);
}

AssaultTerminator::~AssaultTerminator()
{
    std::cout << "I'll be back..." << std::endl;
}

AssaultTerminator*
AssaultTerminator::clone() const
{
    AssaultTerminator* ret = new AssaultTerminator(*this);
    return (ret);
}

void
AssaultTerminator::battleCry() const
{
    std::cout << "This code is unclean. PURIFY IT!" << std::endl;
}

void
AssaultTerminator::rangedAttack() const
{
    std::cout << "* does nothing *" << std::endl;
}

void
AssaultTerminator::meleeAttack() const
{
    std::cout << "* attacks with chainfists *" << std::endl;
}
