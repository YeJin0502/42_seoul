/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:44:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/23 17:44:25 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization()
{}

Serialization::Serialization(const Serialization& ref)
{
    *this = ref;
}

Serialization&
Serialization::operator = (const Serialization& ref)
{
    (void) ref;
    return (*this);
}

Serialization::~Serialization()
{}

void*
Serialization::serialize(void)
{
    char *raw = new char[20];

    /*
    // 원래 풀이.
    // 문제점1: rand의 범위가 양수만이라는 것.
    // 문제점2: c의 rand() 함수 자체의 문제. 성능이 떨어진다고 함.
    std::string alnum = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMOPQRSTUVXYZ0123456789";

    int len = alnum.length();

    srand(time(0)); // 여기에 하는건가?
    for (int i = 0; i < 8; i++)
    {
        raw[i] = alnum[rand() % len];
        raw[20 - i] = alnum[rand() % len];
    }
    raw[8] = rand(); // rand가 원래 음수도 반환하나?

    return (static_cast<void *>(raw));
    */
}

Data*
Serialization::deserialize(void* raw)
{
    Data* ret = new Data;
    char* raw_str = static_cast<char*>(raw);

    for (int i = 0; i < 8; i++)
    {
        ret->s1 += raw_str[i];
    }
    ret->n = *reinterpret_cast<int*>(raw_str + 8);
    for (int i = 0; i < 8; i++)
    {
        ret->s2 += raw_str[12 + i];
    }
    return (ret);
}
