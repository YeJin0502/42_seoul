/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 02:35:05 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/21 01:19:30 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "OfficeBlock.hpp"

int main()
{
    Intern idiotOne;
    Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
    Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
    OfficeBlock ob;

    ob.setIntern(idiotOne);
    ob.setSigner(bob);
    ob.setExecutor(hermes);

    std::cout << "==============================" << std::endl;

    try
    {
        ob.doBureaucracy("mutant pig termination", "Pigley");
    }
    catch (OfficeBlock::WorkerError & e)
    {
        std::cout << "Error in OfficeBlock: " << e.what() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "==============================" << std::endl;

    try
    {
        ob.doBureaucracy("shrubbery creation", "Pigley");
    }
    catch (OfficeBlock::WorkerError & e)
    {
        std::cout << "Error in OfficeBlock: " << e.what() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "==============================" << std::endl;

    OfficeBlock ob2;

    try
    {
        ob2.doBureaucracy("shrubbery creation", "home");
    }
    catch (OfficeBlock::WorkerError & e)
    {
        std::cout << "Error in OfficeBlock: " << e.what() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "==============================" << std::endl;

    ob2.setIntern(idiotOne);
    ob2.setSigner(bob);
    ob2.setExecutor(hermes);

    try
    {
        ob2.doBureaucracy("robotomy request", "wall-e");
    }
    catch (OfficeBlock::WorkerError & e)
    {
        std::cout << "Error in OfficeBlock: " << e.what() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "==============================" << std::endl;
}