/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 19:21:43 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 21:02:24 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"

#define COUNT 5

int main()
{
    ZombieEvent at_cluster;
    Zombie *gmoon;
    Zombie *cadets[COUNT];
    Zombie *pisciners[COUNT];

    srand(time(0));

    gmoon = at_cluster.newZombie("gmoon");
    gmoon->announce();
    delete gmoon;

    at_cluster.setZombieType("cadet");
    for (int i = 0; i < COUNT; i++)
    {
        cadets[i] = at_cluster.randomChump();
        delete cadets[i];
    }

    at_cluster.setZombieType("pisciner");
    for (int i = 0; i < COUNT; i++)
    {
        pisciners[i] = at_cluster.randomChump();
        delete pisciners[i];
    }
}

// 아직 힙에 할당하는 것 말고는 잘 모른다. 함수 자체가 포인터를 반환하면 이 경우 어떻게 스택에 할당하지?
