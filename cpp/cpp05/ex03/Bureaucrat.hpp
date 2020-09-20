/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 22:54:21 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/19 22:51:10 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Form;

class Bureaucrat
{
    private:
        const std::string name_;
        int grade_;
        Bureaucrat();

    public:
        class GradeTooHighException : public std::exception
        {
            public:
                GradeTooHighException();
                GradeTooHighException(const GradeTooHighException& ref);
                GradeTooHighException& operator = (const GradeTooHighException& ref);
                virtual ~GradeTooHighException();
                virtual const char* what() const throw();

        };
        class GradeTooLowException : public std::exception
        {
            public:
                GradeTooLowException();
                GradeTooLowException(const GradeTooLowException& ref);
                GradeTooLowException& operator = (const GradeTooLowException& ref);
                virtual ~GradeTooLowException();
                virtual const char* what() const throw();
        };

        Bureaucrat(std::string const name, signed int grade) throw(GradeTooHighException, GradeTooLowException);
        Bureaucrat(const Bureaucrat& ref);
        Bureaucrat& operator = (const Bureaucrat& ref) throw(GradeTooHighException, GradeTooLowException);
        virtual ~Bureaucrat();

        const std::string& getName() const;
        int getGrade() const;

        void upGrade() throw(GradeTooHighException);
        void downGrade() throw(GradeTooLowException);

        void signForm(Form& form);
        void executeForm(Form const & form);
};

std::ostream& operator << (std::ostream& out, const Bureaucrat& ref);

# include "Form.hpp"

#endif