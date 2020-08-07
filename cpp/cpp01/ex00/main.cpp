/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 16:49:19 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 17:33:08 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

void ponyOnTheHeap()
{
    Pony *pony_inheap;

    pony_inheap = new Pony("moon");
    pony_inheap->say_hello();
    pony_inheap->turn_music();
    delete pony_inheap;
}

void ponyOnTheStack()
{
    Pony pony_instack("gua");

    pony_instack.say_hello();
    pony_instack.turn_music();
}

int main()
{
    std::cout << std::endl;
    std::cout << "=======================================" << std::endl;
    ponyOnTheHeap();
    std::cout << "=======================================" << std::endl;
    ponyOnTheStack();
    std::cout << "=======================================" << std::endl;
    std::cout << std::endl;
}
