/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:01:22 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/08 15:32:24 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main()
{
    Human bob;

    std::cout << bob.identify() << std::endl;
    std::cout << bob.getBrain().identify() << std::endl;
}
