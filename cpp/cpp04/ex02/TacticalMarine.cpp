/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 19:35:04 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/14 11:42:28 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine()
{
    std::cout << "Tactical Marine ready for battle!" << std::endl;
}

TacticalMarine::TacticalMarine(const TacticalMarine& ref)
{
    std::cout << "Tactical Marine ready for battle!" << std::endl;

    // operator = (ref); // 작동 원리 잘 모름.
    *this = ref;
}

TacticalMarine&
TacticalMarine::operator = (const TacticalMarine& ref)
{
    (void) ref;
    return (*this);
}

TacticalMarine::~TacticalMarine()
{
    std::cout << "Aaargh..." << std::endl;
}

TacticalMarine*
TacticalMarine::clone() const
{
    TacticalMarine *ret = new TacticalMarine(*this);
    return (ret);
}

void
TacticalMarine::battleCry() const
{
    std::cout << "For the holy PLOT!" << std::endl;
}

void
TacticalMarine::rangedAttack() const
{
    std::cout << "* attacks with a bolter *" << std::endl;
}

void
TacticalMarine::meleeAttack() const
{
    std::cout << "* attacks with a chainsword *" << std::endl;
}
