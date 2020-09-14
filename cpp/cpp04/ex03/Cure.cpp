/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 23:17:34 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/14 23:27:26 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
: AMateria("cure") // 이거도 헷갈림. _type("cure"), _xp(0) 하는 것이랑...
{}

Cure::Cure(const Cure& ref)
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
    AMateria::operator = (ref); // 이게 헷갈림. 바로 생각나는 답도 아니고, 서로 부모나 자식 함수들을 가져오는 것도 헷갈리고 그 기능의 차이가 모호해짐.
    return (*this);
}

Cure::~Cure()
{

}

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
