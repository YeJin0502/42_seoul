/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:11:01 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/21 00:59:06 by gmoon            ###   ########.fr       */
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

Form::GradeTooHighException::GradeTooHighException()
{}

Form::GradeTooHighException::GradeTooHighException(const GradeTooHighException& ref)
{
    *this = ref;
}

Form::GradeTooHighException&
Form::GradeTooHighException::operator = (const GradeTooHighException& ref)
{
    (void) ref;
    return (*this);
}

Form::GradeTooHighException::~GradeTooHighException()
{}

const char*
Form::GradeTooHighException::what() const throw()
{
    return ("Form's grade is too high.");
}

Form::GradeTooLowException::GradeTooLowException()
{}

Form::GradeTooLowException::GradeTooLowException(const GradeTooLowException& ref)
{
    *this = ref;
}

Form::GradeTooLowException&
Form::GradeTooLowException::operator = (const GradeTooLowException& ref)
{
    (void) ref;
    return (*this);
}

Form::GradeTooLowException::~GradeTooLowException()
{}

const char*
Form::GradeTooLowException::what() const throw()
{
    return ("Form's grade is too low.");
}

Form::NotSigned::NotSigned()
{}

Form::NotSigned::NotSigned(const NotSigned& ref)
{
    *this = ref;
}

Form::NotSigned&
Form::NotSigned::operator = (const NotSigned& ref)
{
    (void) ref;
    return (*this);
}

Form::NotSigned::~NotSigned()
{}

const char*
Form::NotSigned::what() const throw()
{
    return ("Form is not signed.");
}

Form::Form()
:   name_(""),
    grade_for_sign_(150),
    grade_for_exec_(150),
    target_("")
{}

Form::Form(std::string name, int grade_for_sign, int grade_for_exec, std::string target)
    throw(GradeTooHighException, GradeTooLowException)
:   name_(name),
    grade_for_sign_(validGrade(grade_for_sign)),
    grade_for_exec_(validGrade(grade_for_exec)),
    target_(target)
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
        target_ = ref.target_;
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

std::string
Form::getTarget() const
{
    return (target_);
}

void
Form::beSigned(Bureaucrat& bur) throw(GradeTooLowException)
{
    if (bur.getGrade() > grade_for_sign_)
        throw GradeTooLowException();
    sign_ = true;
}

void
Form::execute(Bureaucrat const & executor) const throw(NotSigned, GradeTooLowException)
{
    if (sign_ == false)
        throw NotSigned();
    else if (executor.getGrade() > grade_for_exec_)
        throw GradeTooLowException();
}

std::ostream& operator << (std::ostream& out, const Form& ref)
{
    out << ref.getName() << "\'s sign is " << ref.getSign() << ". ";
    out << "Grade for sign is " << ref.getGradeForSign() << ". ";
    out << "Grade for execute is " << ref.getGradeForExec() << ". ";
    out << "Target is " << ref.getTarget() << ".";
    return (out);
}
