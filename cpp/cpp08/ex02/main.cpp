/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:52:10 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/29 14:24:14 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>
#include <list>

// subject 메인문
int main()
{
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::list<int> l(lst);

    std::cout << "=========================" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it2 = mstack.begin();
    MutantStack<int>::iterator ite2 = mstack.end();
    ++it2;
    --it2;
    while (it2 != ite2)
    {
    std::cout << *it2 << std::endl;
    ++it2;
    }
    std::stack<int> s(mstack);
}

/*
// 내 메인문
int main()
{
    std::cout << "=============== 기본생성자와 반복자" << std::endl;

    MutantStack<int> mst;
    mst.push(1);
    mst.push(2);
    mst.push(3);

    for (auto it = mst.begin(); it < mst.end(); it++)
    {
        std::cout << *it << std::endl;
        *it += 10;
    }

    std::cout << "=============== reverse 반복자" << std::endl;

    for (auto it = mst.rbegin(); it < mst.rend(); it++)
        std::cout << *it << std::endl;
    
    std::cout << "=============== const 반복자" << std::endl;

    auto it = mst.cbegin();
    std::cout << *it << std::endl;
    it++; // 변경 가능.
    std::cout << *it << std::endl;
    // *it += 10; // const 값이라서 포인터가 가르키는 값 변경 불가능(컴파일 에러).

    std::cout << "=============== 할당연산자" << std::endl;

    MutantStack<int> mst2;
    mst2.push(4);
    mst2.push(5);
    mst2.push(6);
    mst2.push(7);

    mst2 = mst;

    for (auto it = mst2.begin(); it < mst2.end(); it++)
        std::cout << *it << std::endl;
}
*/
