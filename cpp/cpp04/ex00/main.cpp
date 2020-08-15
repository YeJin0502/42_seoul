/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 00:25:39 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/16 04:54:08 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

// int main()
// {
//     std::cout << "==============================" << std::endl;

//     Sorcerer a("robert", "ROB");
//     Sorcerer b(a);
//     Sorcerer c;

//     c = b;
//     std::cout << c;

//     std::cout << "==============================" << std::endl;

//     Victim aa("moongua");

//     std::cout << aa;

//     std::cout << "==============================" << std::endl;

//     Peon aaa("gmoon");
//     Peon bbb(aaa);
//     Peon ccc;

//     ccc = bbb;
//     std::cout << ccc;
// }

int main()
{
    Sorcerer robert("Robert", "the Magnificent");

    Victim jim("Jimmy");
    Peon joe("Joe");

    std::cout << robert << jim << joe;

    robert.polymorph(jim);
    robert.polymorph(joe);

    return 0;
}

// 아마 메인문을 강화해야 할 듯..?
// 잘 모르는 포인터들도 써보는게 좋을 듯.
