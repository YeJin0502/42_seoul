/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:25:01 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 00:02:10 by gmoon            ###   ########.fr       */
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
        return ;
    }
    contacts[count].init(count);
    count++;
}

void Book::search()
{
    std::string buf;
    int         buf_len;

    if (count == 0)
    {
        std::cout << "저장된 연락처가 없습니다. SEARCH를 중단합니다." << std::endl;
        return ;
    }
    for (int i = 0; i < count; i++)
        contacts[i].display_summary();
    std::cout << "원하는 항목의 index를 입력하세요: ";
    getline(std::cin, buf, '\n');
    buf_len = buf.length();
    for (int i = 0; i < buf_len; i++)
    {
        if (isdigit(buf[i]) == 0)
        {
            std::cout << "입력값이 적절하지 않습니다. SEARCH를 중단합니다." << std::endl;
            return ;
        }
    }
    if (std::stoi(buf) < 0 || std::stoi(buf) >= count)
    {
        std::cout << "입력된 index가 적절하지 않습니다. SEARCH를 중단합니다." << std::endl;
        return ;
    }
    contacts[std::stoi(buf)].display_fields();
}
