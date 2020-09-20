/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 22:13:19 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/20 01:12:38 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
:   Form("shrubbery creation", 145, 137, "")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
:   Form("shrubbery creation", 145, 137, target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
:   Form(ref)
{
    Form::operator = (ref);
}

ShrubberyCreationForm&
ShrubberyCreationForm::operator = (const ShrubberyCreationForm& ref)
{
    Form::operator = (ref);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

const char *TREE =
{
    "\n"
    "    oxoxoo    ooxoo \n"
    "  ooxoxo oo  oxoxooo \n"
    " oooo xxoxoo ooo ooox \n" 
    " oxo o oxoxo  xoxxoxo \n"
    "  oxo xooxoooo o ooo \n"
    "    ooo\\oo\\  /o/o \n"
    "        \\  \\/ / \n"
    "         |   / \n"
    "         |  | \n"
    "         | D| \n"
    "         |  | \n"
    "         |  | \n"
    "  ______/____\\____ \n"
};

void
ShrubberyCreationForm::execute(Bureaucrat const & executor) const
    throw(NotSigned, GradeTooLowException)
{
    Form::execute(executor);

    std::ofstream fout;
    fout.open(getTarget() + "_shrubbery");
    if (!fout)
        throw std::exception();
    fout << TREE;
    fout.close();
}
