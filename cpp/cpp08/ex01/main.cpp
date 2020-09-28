/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:16:33 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/28 16:03:13 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "span.hpp"

int main()
{
    std::cout << "==============================" << std::endl;

    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(-3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    sp.test_print();

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "==============================" << std::endl;

    Span sp2 = Span(7);
    sp2.addNumber(1);
    sp2.addNumber(2);
    sp2.addNumber(3);
    sp2 = sp;

    sp2.test_print();

    std::cout << "==============================" << std::endl;

    Span sp3(5);

    sp3.fillRandom();
    sp3.test_print();

    std::cout << sp3.shortestSpan() << std::endl;
    std::cout << sp3.longestSpan() << std::endl;
    
    std::cout << "==============================" << std::endl;
}
