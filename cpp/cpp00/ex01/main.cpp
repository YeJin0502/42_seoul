/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:01:54 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 00:07:31 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "book.hpp"

int main()
{
    Book book;

    while (1)
    {
        std::string cmd;

        std::cout << "[gmoon] >> ";
        getline(std::cin, cmd, '\n');
        if (cmd == "EXIT")
            exit(0);
        else if (cmd == "ADD")
            book.add();
        else if (cmd == "SEARCH")
            book.search();
        else
            std::cout << "올바르지 않은 명령입니다." << std::endl;
    }
}
