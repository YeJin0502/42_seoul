/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 12:22:19 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/25 13:53:59 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    std::cout << "==============================" << std::endl;

    Array<int> arr1(3);
    for (unsigned int i = 0; i < arr1.size(); i++)
        std::cout << i << ": " << arr1[i] << std::endl;

    Array<int> arr2(5);
    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = i;
    std::cout << "make arr2... and copy arr2 to arr1." << std::endl;
    arr1 = arr2;

    for (unsigned int i = 0; i < arr1.size(); i++)
        std::cout << i << ": " << arr1[i] << std::endl;
        
    std::cout << "==============================" << std::endl;

    Array<char> arr_char(3);
    for (unsigned int i = 0; i < arr_char.size(); i++)
        std::cout << i << ": " << (int) arr_char[i] << std::endl;

    std::cout << "==============================" << std::endl;

    try
    {
        Array<double> arr_double;
        std::cout << arr_double[0] << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "==============================" << std::endl;
}
