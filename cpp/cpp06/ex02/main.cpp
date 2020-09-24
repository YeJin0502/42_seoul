/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 07:55:59 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/25 08:09:11 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <random>

Base* generate(void)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 3);
    
    int ran = dis(gen);
    if (ran == 1)
        return (static_cast<Base*>(new A));
    else if (ran == 2)
        return (static_cast<Base*>(new B));
    else
        return (static_cast<Base*>(new C));
}

void identify_from_pointer(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify_from_reference(Base& p)
{
    if (dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;

    // identify_from_pointer(&p); // 이렇게도 되네.
}

int main()
{
    Base* gen1 = generate();
    Base& ref = *gen1;

    identify_from_pointer(gen1);
    identify_from_reference(ref);

    delete gen1;
}
