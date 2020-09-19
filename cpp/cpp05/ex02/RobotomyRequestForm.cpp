/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 23:14:46 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/20 00:21:53 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
:   Form("RobotomyRequestForm", 72, 45, "")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
:   Form("RobotomyRequestForm", 72, 45, target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref)
:   Form(ref)
{
    Form::operator = (ref);
}

RobotomyRequestForm&
RobotomyRequestForm::operator = (const RobotomyRequestForm& ref)
{
    Form::operator = (ref);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void
RobotomyRequestForm::execute(Bureaucrat const & executor) const
    throw(NotSigned, GradeTooLowException)
{
    Form::execute(executor);

    srand(time(0));
    if (random() % 2 == 0)
    {
        std::cout << "drrrrr.....";
        std::cout << getTarget() << " has been robotomized." << std::endl;
    }
    else
        std::cout << getTarget() << " was not robotomized." << std::endl;
}