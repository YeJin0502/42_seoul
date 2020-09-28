/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:56:11 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/28 12:55:08 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>

int main()
{
    std::cout << "========================================" << std::endl;

    std::vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);

    std::cout << *easyfind(v, 2) << std::endl;
    try
    {
        std::cout << *easyfind(v, 3) << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "========================================" << std::endl;

    std::deque<int> d = {0,1,2};

    std::cout << *easyfind(d, 2) << std::endl;
    try
    {
        std::cout << *easyfind(d, 3) << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "========================================" << std::endl;

    std::list<int> l = {0,1,2};

    std::cout << *easyfind(l, 2) << std::endl;
    try
    {
        std::cout << *easyfind(l, 3) << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "========================================" << std::endl;

    std::set<int> s = {0,1,2};

    std::cout << *easyfind(s, 2) << std::endl;
    try
    {
        std::cout << *easyfind(s, 3) << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "========================================" << std::endl;

    std::map<int, int> m = {{1, 11}, {2, 22}}; // int의 컨테이너라고 보기 어려우므로 굳이 구현 안해도 될듯. 다만 중복함수의 개념을 연습하고자 추가함.

    std::cout << easyfind(m, 1)->first << std::endl;
    std::cout << easyfind(m, 1)->second << std::endl;
    try
    {
        std::cout << easyfind(m, 11)->first << std::endl;
        std::cout << easyfind(m, 11)->second << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "========================================" << std::endl;

    // std::stack<int> st; // 스택, 큐는 다른 객체를 사용하나봄. 공부 필요.
    // st.push(0);
    // st.push(1);
    // st.push(2);

    // std::cout << *easyfind(st, 2) << std::endl;
    // try
    // {
    //     std::cout << *easyfind(st, 3) << std::endl;
    // }
    // catch (std::exception & e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
}

