/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 16:49:31 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 17:33:04 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

Pony::Pony(std::string name)
{
    this->name = name;
    std::cout << name + "이(가) 생성되었습니다!" << std::endl;
}

Pony::~Pony()
{
    std::cout << name + "이(가) 야생으로 돌아갔습니다. 잘가~" << std::endl;
}

void Pony::say_hello()
{
    std::cout << "(ฅ^._.^)ฅ 안녕! 나는 " + name + "라고 해." << std::endl;
}

void Pony::turn_music()
{
    std::cout << "포니가 리듬을 탑니다..." << std::endl;
    std::cout << "ㄱ(ㅇ_ㅇ)ㄴ ㄴ(ㅇ_ㅇ)ㄱ" << std::endl;
}
