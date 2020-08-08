/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:59:34 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/08 15:22:49 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

std::string Brain::identify() const
{
    std::stringstream ss; // stringstream에 대한 공부 더 필요.

    // ss << std::showbase << std::hex;
    // ss << std::uppercase << (long)this; // 이게 아래 한 줄과 같은 내용이라는 것 공부 필요.

    // ss << std::showbase << std::hex << std::uppercase << (long)this;
    
    ss << "Ox" << std::uppercase << std::hex << (unsigned long)this;
    // std::cout << ss.str();

    return (ss.str());
}
