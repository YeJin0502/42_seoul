/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:52:49 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/14 11:42:10 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad()
{
    size_ = 0; // 이런 값 대입은 {} 위에 하는 것이 나은 듯.
    squad_ = 0;
}

Squad::Squad(const Squad& ref)
{
    // 파괴하는 내용 추가해야 하나? 할당 연산자에서만 하면 되지않나?

    // operator = (ref);
    // 이거 이해 잘 안됨. 리턴도 아니고.. 이건 결국 왼쪽에 this 객체가 들어가는 함수로 보면 되는건가?
    // 아래랑 같은 내용이겠지?
    *this = ref;
}

Squad&
Squad::operator = (const Squad& ref)
{
    if (this != &ref)
    {
        if (squad_)
            deleteSquad();
        size_ = ref.size_; // getCount() 써야할 때랑 헷갈린다.
        squad_ = new ISpaceMarine*[size_];
        for (int i = 0; i < size_; i++)
            squad_[i] = ref.getUnit(i)->clone();
    }
    return (*this);
}

Squad::~Squad()
{
    if (squad_)
        deleteSquad();
}

int
Squad::getCount() const
{
    return (size_);  
}

ISpaceMarine*
Squad::getUnit(int i) const
{
    if (size_ <= i || i < 0)
        return (nullptr);
    return (squad_[i]);
}

int
Squad::push(ISpaceMarine* unit)
{
    if (!unit)
        return (size_);
    for (int i = 0; i < size_; i++)
        if (squad_[i] == unit)
            return (size_);
    
    size_ += 1;
    ISpaceMarine** tmp = new ISpaceMarine*[size_];
    for (int i = 0; i < size_ - 1; i++)
        tmp[i] = squad_[i];
    tmp[size_ - 1] = unit;
    delete[] squad_; // 배열을 가르키는 포인터만 해제한다는 건가?
    squad_ = tmp;

    return (size_);
}

void
Squad::deleteSquad()
{
    for (int i = 0; i < size_; i++)
        delete squad_[i];
    // delete squad_;
    delete[] squad_;
}
