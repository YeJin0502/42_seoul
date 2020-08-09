/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 04:16:06 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/10 07:00:06 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mysed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
        std::cout << "사용법: ./mysed <파일명> <s1> <s2>" << std::endl;

    Mysed mysed(argv[1], argv[2], argv[3]);
    // argv 자체를 넘기는게 나으려나? 모르겠음.
    // 그게 깔끔할 것 같긴 함. argc 오류도 아예 처리해버리고?

    mysed.mysed();
}

// `./mysed ./test/case1 hi hello`
