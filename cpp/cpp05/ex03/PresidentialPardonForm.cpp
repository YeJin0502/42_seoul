/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 00:23:48 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/20 01:12:05 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
:   Form("presidential pardon", 25, 5, "")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
:    Form("presidential pardon", 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref)
:    Form(ref)
{
    *this = ref;
}

PresidentialPardonForm&
PresidentialPardonForm::operator = (const PresidentialPardonForm& ref)
{
    Form::operator = (ref);
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

void
PresidentialPardonForm::execute(Bureaucrat const & executor) const
    throw(NotSigned, GradeTooLowException)
{
    Form::execute(executor);
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
