/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 10:34:44 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/25 11:11:56 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T1, typename T2, typename T3> // 내 풀이. 이게 맞는건가? 되긴 하는데.
void iter(T1* arr, T2 len, T3 func)
// template <typename T1, typename T2>
// void iter(T1* arr, T2 len, void (*func)(T1 &elem)) // 다른 풀이들. 하지만 완전한 일반화가 아니라, 레퍼런스를 매개변수로 취하지 않는 함수를 전달하면 오류가 뜸.
{
    for (T2 i = 0; i < len; i++)
        func(arr[i]);
}

template <typename T>
void print(T t) // 다른 풀이는 매개변수가 레퍼런스가 아니라서 여기서 오류가 뜬다.
{
    std::cout << t;
}

template <typename T>
void up(T& t)
{
    t += 1;
}

int main()
{
    int int_arr[5] = {0,1,2,3,4};
    iter(int_arr, 5, print<int>);
    std::cout << std::endl;
    iter(int_arr, 5, up<int>);
    iter(int_arr, 5, print<int>);
    // iter(int_arr, 5, printf);
    std::cout << std::endl;

    char char_arr[5] = {'a', 'b', 'c', 'd', 'e'};
    iter(char_arr, (size_t)5, &print<char>); // 함수포인터의 특징. 함수의 주소 혹은 값이 둘 다 같은 기능을 함. (정확하게는 참조나 역참조해도 항상 같은 기능이라 *이 여러개 붙어도 같음.)
    std::cout << std::endl;
    iter(char_arr, (size_t)5, &up<char>);
    iter(char_arr, (size_t)5, &print<char>);
    std::cout << std::endl;
}
