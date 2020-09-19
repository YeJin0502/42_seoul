/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:43:25 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/19 23:32:00 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name_;
        bool sign_ = false;
        const int grade_for_sign_;
        const int grade_for_exec_;
        std::string target_;

        int validGrade(int grade);

    public:
        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw();
        };
        class NotSigned : public std::exception
        {
            virtual const char* what() const throw();
        };

        Form();
        Form(std::string name, int grade_for_sign, int grade_for_exec, std::string target)
            throw(GradeTooHighException, GradeTooLowException);
        Form(const Form& ref)
            throw(GradeTooHighException, GradeTooLowException);
        Form& operator = (const Form& ref);
        virtual ~Form();

        std::string getName() const;
        bool getSign() const;
        int getGradeForSign() const;
        int getGradeForExec() const;
        std::string getTarget() const;

        void beSigned(Bureaucrat& bur) throw(GradeTooLowException);

        virtual void execute(Bureaucrat const & executor) const throw(NotSigned, GradeTooLowException);
};

std::ostream& operator << (std::ostream& out, const Form& ref);

#endif