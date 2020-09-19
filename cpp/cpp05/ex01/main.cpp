/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 02:35:05 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/19 21:20:30 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Form cpp05 = Form("cpp05", 15, 50);

    std::cout << cpp05 << std::endl;

    try
    {
        Bureaucrat gmoon = Bureaucrat("gmoon", 20);
        gmoon.signForm(cpp05);
        std::cout << cpp05 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat gmoon = Bureaucrat("gmoon", 10);
        gmoon.signForm(cpp05);
        std::cout << cpp05 << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}
