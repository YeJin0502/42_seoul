/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex01.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 18:00:01 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 18:04:26 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void memoryLeak()
{
    std::string *panther = new std::string("String panther");
    std::cout << *panther << std::endl;

    delete panther;
}

// int main()
// {
//     memoryLeak();
// }

// valgrind --leak-check=full ./a.out
