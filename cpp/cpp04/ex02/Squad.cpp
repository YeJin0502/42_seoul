/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:52:49 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/28 14:55:29 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad()
{
    size_ = 0;
    squad_ = 0;
}

Squad::Squad(const Squad& ref)
{
    // operator = (ref); // 이거 이해 잘 안됨. 리턴도 아니고.. 이건 결국 왼쪽에 this 객체가 들어가는 함수로 보면 되는건가?
}

Squad&
Squad::operator = (const Squad& ref)
{
    // if (this != &ref)
    // {
        
    // }
    // return (*this);
}

int
Squad::getCount() const
{
    return (size_);  
}

ISpaceMarine*
Squad::getUnit(int i) const
{
    return (squad_[i]); // 이렇게 하면 되나?
}

int
Squad::push(ISpaceMarine* unit)
{
    // size_ += 1;

    // ISpaceMarine **ret = new ISpaceMarine*[size_]; // 이게 헷갈림. 클래스의 배열도 헷갈리고, cpp의 동적할당 자체도 헷갈림.

    // for (int i = 0; i < size_; i++)
    //     ret[i] = unit;
    // return (size_);
} // 되나?

