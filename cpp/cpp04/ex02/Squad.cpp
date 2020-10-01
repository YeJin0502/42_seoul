/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:52:49 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 16:04:16 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad()
:   size_(0),
    squad_(nullptr)
{}

Squad::Squad(const Squad& ref)
:   size_(0),
    squad_(nullptr) // 초기화 안해주면 할당연산자의 if (squad_) 문에 들어가버림.
{
    *this = ref;
}

Squad&
Squad::operator = (const Squad& ref)
{
    if (this != &ref)
    {
        if (squad_)
            deleteSquad();
        size_ = ref.size_;
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
    delete[] squad_;
    squad_ = tmp;

    return (size_);
}

void
Squad::deleteSquad()
{
    for (int i = 0; i < size_; i++)
        delete squad_[i];
    delete[] squad_;
}
