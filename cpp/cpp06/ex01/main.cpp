/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:22:44 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/25 07:13:09 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
    Serialization ser;
    void *ret1;
    Data *ret2;

    ret1 = ser.serialize();
    ret2 = ser.deserialize(ret1);

    std::cout << ret2->s1 << std::endl;
    std::cout << ret2->n << std::endl;
    std::cout << ret2->s2 << std::endl;

    delete[] reinterpret_cast<char*>(ret1);
    delete ret2;
}
