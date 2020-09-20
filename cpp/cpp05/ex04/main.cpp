/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 02:35:05 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/20 01:37:09 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern noname;
    Form *form;

    form = noname.makeForm("presidential pardon", "gmoon");
    std::cout << *form << std::endl;

    try
    {
        form = noname.makeForm("presidential pardon!", "gmoon");
        std::cout << *form << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat gmoon("gmoon", 10);

    gmoon.signForm(*form);
    std::cout << *form << std::endl;

    gmoon.executeForm(*form);
    for (int i = 0; i < 5; i++)
        gmoon.upGrade();
    gmoon.executeForm(*form);
}
