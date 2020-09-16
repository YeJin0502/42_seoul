/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 02:35:05 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/17 02:55:19 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    int i = 1;

    std::cout << "==========" << i++ << "==========" << std::endl;
    try
    {
        Bureaucrat gmoon = Bureaucrat("gmoon", 1);
        std::cout << gmoon << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "==========" << i++ << "==========" << std::endl;
    try
    {
        Bureaucrat error = Bureaucrat("error", 0);
        std::cout << error << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "==========" << i++ << "==========" << std::endl;
    try
    {
        Bureaucrat gmoon = Bureaucrat("gmoon", 149);
        std::cout << gmoon << std::endl;

        gmoon.downGrade();
        std::cout << gmoon << std::endl;

        gmoon.downGrade();
        std::cout << gmoon << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}
