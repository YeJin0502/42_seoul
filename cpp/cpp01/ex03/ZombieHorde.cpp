/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 21:17:31 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 21:49:04 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
    std::string name;

    if (n < 0)
    {
        std::cout << "음수가 입력되었습니다." << std::endl;
        return ;
    }
    n_ = n;
    zombies_ = new Zombie[n];
    // 이게 제일 헷갈림. 배열을 만든다?
    // subject의 단일 할당이라는게 여기서 한번에 만드는 것을 의미하나?
    // 그리고 할당할 때, 이름이나 타입을 지정할 순 없나?
    for (int i = 0; i < n; i++)
    {
        name = "aaaaa";
        for (int j = 0; j < 5; j++)
            name[j] = 'a' + rand() % 26;
        zombies_[i].set_name(name);
    }
}

ZombieHorde::ZombieHorde(int n, std::string type)
{
    std::string name;

    if (n < 0)
    {
        std::cout << "음수가 입력되었습니다." << std::endl;
        return ;
    }
    n_ = n;
    zombies_ = new Zombie[n];
    for (int i = 0; i < n; i++)
    {
        name = "aaaaa";
        for (int j = 0; j < 5; j++)
            name[j] = 'a' + rand() % 26;
        zombies_[i].set_name(name);
        zombies_[i].set_type(type);
    }
} // 위의 함수와 마지막 줄 빼고 동일한데, 효율적인 방법 없을까?

ZombieHorde::~ZombieHorde()
{
    std::cout << "좀비들이 파괴됩니다." << std::endl;
    // delete zombies_; // 배열은 delete 방법이 다르다.
    delete[] zombies_;
}

void ZombieHorde::announce()
{
    for (int i = 0; i < n_; i++)
        zombies_[i].announce();
}
