/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:50:02 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/29 13:22:53 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"

// template <typename T>
// typename std::stack<T>::container_type::iterator
// MutantStack<T>::begin()
// {
//     return (this->c.begin());
// }

// template <typename T>
// typename std::stack<T>::container_type::iterator
// MutantStack<T>::end()
// {
//     return (this->c.end());
// }

// 템플릿 클래스 멤버 함수는 class 내부에서 선언해야. 그렇지 않으면 다음과 같은 에러 발생.
/*
/mnt/c/Users/koom6/Desktop/42_seoul/cpp/cpp08/ex02/main.cpp:18: undefined reference to `MutantStack<int>::MutantStack()'
/mnt/c/Users/koom6/Desktop/42_seoul/cpp/cpp08/ex02/main.cpp:24: undefined reference to `MutantStack<int>::begin()'
/mnt/c/Users/koom6/Desktop/42_seoul/cpp/cpp08/ex02/main.cpp:24: undefined reference to `MutantStack<int>::end()'
/mnt/c/Users/koom6/Desktop/42_seoul/cpp/cpp08/ex02/main.cpp:26: undefined reference to `MutantStack<int>::~MutantStack()'
/mnt/c/Users/koom6/Desktop/42_seoul/cpp/cpp08/ex02/main.cpp:26: undefined reference to `MutantStack<int>::~MutantStack()'
clang: error: linker command failed with exit code 1 (use -v to see invocation)
*/