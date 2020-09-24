/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:44:42 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/25 07:22:45 by gmoon            ###   ########.fr       */
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
    std::string alnum = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMOPQRSTUVXYZ0123456789";
    int len = alnum.length();

    /*
    // 원래 풀이.
    // 문제점1: rand의 범위가 양수만이라는 것. 즉, 실제 무작위 'int'가 아님.
    // 문제점2: c의 rand() 함수 자체의 문제. 성능이 떨어짐.

    srand(time(0)); // 여기에 하는건가?
    for (int i = 0; i < 8; i++)
    {
        raw[i] = alnum[rand() % len];
        raw[20 - i] = alnum[rand() % len];
    }
    raw[8] = rand();

    return (static_cast<void *>(raw));
    */

    std::random_device rd;
    std::mt19937 gen(rd());
    // std::uniform_int_distribution<int> dis(0, 1000); // 테스트용
    std::uniform_int_distribution<int>
        dis(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    for (int i = 0; i < 8; i++)
    {
        raw[i] = alnum[std::abs(dis(gen)) % len];
        raw[20 - i - 1] = alnum[std::abs(dis(gen)) % len];
    }

    // raw[8] = dis(gen); // 이렇게 하면, raw[8]의 한 바이트에만 숫자가 들어감. 헷갈리네.
    *reinterpret_cast<int*>(raw + 8) = dis(gen); // char 포인터에 int를 넣으려하면, 한 바이트에만 넣는 듯? 따라서 int 포인터로 변환.

   return (reinterpret_cast<void*>(raw));
}

Data*
Serialization::deserialize(void* raw)
{
    Data* ret = new Data;

    /*
    // 형변환의 개념 모르면 이런식으로 해야함.

    char* raw_str = reinterpret_cast<char*>(raw);
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
    */

    ret->s1 = std::string(reinterpret_cast<char *>(raw), 8);
    ret->n = *reinterpret_cast<int *>(static_cast<char*>(raw) + 8);
    // ret->n = *static_cast<int *>(static_cast<char*>(raw) + 8); // 스태틱 캐스트가 불가능하므로, 컴파일 시 오류.
    ret->s2 = std::string(reinterpret_cast<char *>(static_cast<char*>(raw) + 12), 8);

    return (ret);
}
