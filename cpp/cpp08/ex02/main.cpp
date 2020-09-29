/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:52:10 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/29 13:50:38 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>

int main()
{
    std::cout << "=========================" << std::endl;

    MutantStack<int> mst;
    mst.push(1);
    mst.push(2);
    mst.push(3);

    for (auto it = mst.begin(); it < mst.end(); it++)
    {
        std::cout << *it << std::endl;
        *it += 10;
    }

    std::cout << "=========================" << std::endl;

    for (auto it = mst.rbegin(); it < mst.rend(); it++)
        std::cout << *it << std::endl;
    
    std::cout << "=========================" << std::endl;

    auto it = mst.cbegin();
    std::cout << *it << std::endl;
    it++;
    std::cout << *it << std::endl;
    // *it += 10; // const 값이라서 포인터가 가르키는 값 변경 불가능(컴파일 불가능). (포인터를 변경 불가능 한 것이 아님.)

    std::cout << "=========================" << std::endl;

    MutantStack<int> mst2;
    mst2.push(4);
    mst2.push(5);
    mst2.push(6);
    mst2.push(7);

    mst2 = mst;

    for (auto it = mst2.begin(); it < mst2.end(); it++)
        std::cout << *it << std::endl;
        
    std::cout << "=========================" << std::endl;
}
