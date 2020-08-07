/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 22:05:02 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 22:11:12 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    
    std::string *pointer; // 포인터는 바로 초기화하지 않아도 된다.
    // *pointer = str;
    pointer = &str; // 위 문장과 헷갈리지 말 것. 주소가 있을 때, 가리키는 곳을 수정하겠다는 뜻.

    std::string &reference = str; // 레퍼런스는 바로 초기화가 필요하다.

    std::cout << "포인터를 이용해 출력합니다: ";
    std::cout << *pointer << std::endl;

    std::cout << "레퍼런스를 이용해 출력합니다: ";
    std::cout << reference << std::endl;
}
