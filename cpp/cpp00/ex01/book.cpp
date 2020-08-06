/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:25:01 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/06 22:46:29 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "book.hpp"

Book::Book()
{
    count = 0;
}

void Book::add()
{
    if (count == 8)
    {
        std::cout << "더 이상 연락처를 추가할 수 없습니다." << std::endl;
        // std::cout << "No more contacts can be added." << std::endl;
        return ;
    }
    contacts[count].init(count);
    count++;
}

void Book::search()
{
    int index;

    if (count == 0)
    {
        std::cout << "저장된 연락처가 없습니다. SEARCH를 중단합니다." << std::endl;
        // std::cout << "There is no saved contacts. SEARCH stopped." << std::endl;
        return ;
    }
    for (int i = 0; i < count; i++)
        this->contacts[i].display_summary();
    std::cout << "원하는 항목의 index를 입력하세요: ";
    // std::cout << "Enter the number of the desired contact: ";
    if (!(std::cin >> index) || index < 0 || index >= count)
    {
        std::cout << "올바른 index가 아닙니다. SEARCH를 중단합니다." << std::endl;
        // std::cout << "Not a valid index. SEARCH stopped." << std::endl;
        std::cin.clear();
        std::cin.ignore(256, '\n');
        return ;
    }
    contacts[index].display_fields();
}
