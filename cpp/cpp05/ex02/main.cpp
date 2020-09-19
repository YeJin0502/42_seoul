/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 02:35:05 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/20 00:37:18 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "========================================" << std::endl;

    Bureaucrat gmoon("gmoon", 146);
    ShrubberyCreationForm task1("gae-po");

    std::cout << gmoon << std::endl;
    std::cout << task1 << std::endl;

    gmoon.executeForm(task1);
    gmoon.signForm(task1);
    gmoon.upGrade();
    gmoon.signForm(task1);
    gmoon.executeForm(task1);

    for (int i = 0; i < 10; i++)
        gmoon.upGrade();
    
    std::cout << gmoon << std::endl;
    gmoon.executeForm(task1);

    std::cout << "========================================" << std::endl;

    gmoon = Bureaucrat("gmoon", 73);
    RobotomyRequestForm task2("wall-e");

    std::cout << gmoon << std::endl;
    std::cout << task2 << std::endl;

    gmoon.executeForm(task2);
    gmoon.signForm(task2);
    gmoon.upGrade();
    gmoon.signForm(task2);
    gmoon.executeForm(task2);
    for (int i = 0; i < 27; i++)
        gmoon.upGrade();
    std::cout << gmoon << std::endl;
    gmoon.executeForm(task2);

    std::cout << "========================================" << std::endl;

    Bureaucrat kim("kim", 25);
    gmoon = Bureaucrat(kim);
    std::cout << gmoon << std::endl;

    PresidentialPardonForm task3("Lee");
    task3 = PresidentialPardonForm("Han");
    std::cout << task3 << std::endl;
    gmoon.signForm(task3);
    std::cout << task3 << std::endl;
    for (int i = 0; i < 20; i++)
        gmoon.upGrade();
    std::cout << gmoon << std::endl;
    gmoon.executeForm(task3);

    std::cout << "========================================" << std::endl;

    try
    {
        for (int i = 0; i < 5; i++)
        {
            gmoon.upGrade();
            std::cout << gmoon << std::endl;
        }
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "========================================" << std::endl;
}
