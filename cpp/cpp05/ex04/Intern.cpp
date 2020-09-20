/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 01:13:36 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/20 01:34:57 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char*
Intern::InvalidName::what() const throw()
{
    return ("Name is invalid.");
}

Intern::Intern()
{}

Intern::Intern(const Intern& ref)
{
    *this = ref;
}

Intern&
Intern::operator = (const Intern& ref)
{
    (void) ref;
    return (*this);
}

Intern::~Intern()
{}

Form*
Intern::makeForm(std::string name, std::string target)
    throw(InvalidName)
{
    Form* ret = 0;
    if (name == "presidential pardon")
        ret = new PresidentialPardonForm(target);
    else if (name == "robotomy request")
        ret = new RobotomyRequestForm(target);
    else if (name == "shrubbery creation")
        ret = new ShrubberyCreationForm(target);
    else
        throw InvalidName();
    std::cout << "Intern creates " << ret->getName() << std::endl;
    return (ret);
}
