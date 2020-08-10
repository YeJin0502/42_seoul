/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 04:16:06 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/10 16:36:07 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mysed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "사용법: ./mysed <파일명> <s1> <s2>" << std::endl;
        return (1);
    }

    Mysed mysed(argv[1], argv[2], argv[3]);
    // argv 자체를 넘기는게 나으려나? 모르겠음.
    // 그게 깔끔할 것 같긴 함. argc 오류도 아예 처리해버리고?

    // https://github.com/Glagan/42-CPP-Module/blob/master/01/ex07/main.cpp 이 분의 방법도 괜찮음.

    try
    {
        mysed.mysed();
    }
    // catch (std::string e)
    catch (char const *e)
    {
        std::cout << "error: " << e << std::endl;
    }
}

// `./mysed ./test/case1 hi hello`
// `./mysed test/case1 hi hello`
