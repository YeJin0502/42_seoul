/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 15:42:35 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/21 01:46:31 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** 캐노니컬 폼
*/

Bureaucrat::Bureaucrat()
: name_("") // 어떻게 하는 것이 적절하지?
{}

Bureaucrat::Bureaucrat(std::string const name, int grade) throw(GradeTooHighException, GradeTooLowException)
: name_(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    grade_ = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref)
{
    *this = ref;
}

Bureaucrat&
Bureaucrat::operator = (const Bureaucrat& ref) throw(GradeTooHighException, GradeTooLowException)
{
    if (this != &ref)
    {
        // name_ = ref.getName(); // const라 바뀔 수가 없음.
        if (ref.grade_ < 1)
            throw GradeTooHighException();
        else if (ref.grade_ > 150)
            throw GradeTooLowException();
        grade_ = ref.grade_;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat()
{}

/*
** 멤버 함수
*/

const std::string&
Bureaucrat::getName() const
{
    return (name_);
}

int
Bureaucrat::getGrade() const
{
    return (grade_);
}

void
Bureaucrat::upGrade() throw(GradeTooHighException)
{
    int tmp = grade_ - 1;

    if (tmp < 1)
        throw GradeTooHighException();
    grade_ = tmp;
}

void
Bureaucrat::downGrade() throw(GradeTooLowException)
{
    int tmp = grade_ + 1;

    if (tmp > 150)
        throw GradeTooLowException();
    grade_ = tmp;
}

void
Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name_;
        std::cout << " (" << grade_ << ")";
        std::cout << " signs " << form.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << name_ << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void
Bureaucrat::executeForm(Form const & form)
{
    try
    {
        form.execute(*this);
        std::cout << name_;
        std::cout << " (" << grade_ << ")";
        std::cout << " executes " << form.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << name_ << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

/*
** 예외 객체: GradeTooHighException
*/

Bureaucrat::GradeTooHighException::GradeTooHighException()
{}

Bureaucrat::GradeTooHighException::GradeTooHighException(const GradeTooHighException& ref)
{
    *this = ref;
}

Bureaucrat::GradeTooHighException&
Bureaucrat::GradeTooHighException::operator = (const GradeTooHighException& ref)
{
    (void) ref;
    return (*this);
}

Bureaucrat::GradeTooHighException::~GradeTooHighException()
{}

const char*
Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high.");
}

/*
** 예외 객체: GradeTooLowException
*/

Bureaucrat::GradeTooLowException::GradeTooLowException()
{}

Bureaucrat::GradeTooLowException::GradeTooLowException(const GradeTooLowException& ref)
{
    *this = ref;
}

Bureaucrat::GradeTooLowException&
Bureaucrat::GradeTooLowException::operator = (const GradeTooLowException& ref)
{
    (void) ref;
    return (*this);
}

Bureaucrat::GradeTooLowException::~GradeTooLowException()
{}

const char*
Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low.");
}

/*
** 전역 함수
*/

std::ostream& operator << (std::ostream& out, const Bureaucrat& ref)
{
    out << ref.getName() << ", bureaucrat grade " << ref.getGrade();
    return (out);
}
