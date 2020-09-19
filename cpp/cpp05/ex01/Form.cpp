/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:11:01 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/19 21:15:40 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int
Form::validGrade(int grade)
{
    if (grade < 0)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    return (grade);
}

const char*
Form::GradeTooHighException::what() const throw()
{
    return ("Form's grade for sign is too high.");
}

const char*
Form::GradeTooLowException::what() const throw()
{
    return ("Form's grade for sign is too low.");
}

Form::Form()
:   name_(""),
    grade_for_sign_(150),
    grade_for_exec_(150)
{}

Form::Form(std::string name, int grade_for_sign, int grade_for_exec)
throw(GradeTooHighException, GradeTooLowException)
:   name_(name),
    grade_for_sign_(validGrade(grade_for_sign)),
    grade_for_exec_(validGrade(grade_for_exec))
{}

Form::Form(const Form& ref)
throw(GradeTooHighException, GradeTooLowException)
:   name_(ref.name_),
    grade_for_sign_(validGrade(ref.grade_for_sign_)),
    grade_for_exec_(validGrade(ref.grade_for_exec_))
{
    *this = ref;
}

Form&
Form::operator = (const Form& ref)
{
    if (this != &ref)
    {
        sign_ = ref.sign_;
    }
    return (*this);
}

Form::~Form()
{}

std::string
Form::getName() const
{
    return (name_);
}

bool
Form::getSign() const
{
    return (sign_);
}

int
Form::getGradeForSign() const
{
    return (grade_for_sign_);
}

int
Form::getGradeForExec() const
{
    return (grade_for_exec_);
}

void
Form::beSigned(Bureaucrat& bur) throw(GradeTooLowException)
{
    if (bur.getGrade() > grade_for_sign_)
        throw GradeTooLowException();
    sign_ = true;
}

std::ostream& operator << (std::ostream& out, const Form& ref)
{
    out << ref.getName() << "\'s sign is " << ref.getSign() << ". ";
    out << "Grade for sign is " << ref.getGradeForSign() << ". ";
    out << "Grade for execute is " << ref.getGradeForExec() << ".";
    return (out);
}
