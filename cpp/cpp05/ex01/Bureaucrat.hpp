/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 22:54:21 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/17 02:46:49 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    private:
        const std::string name_; // const의 위치를 잘 모르겠음.
        unsigned int grade_;
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

        Bureaucrat(std::string const name, signed int grade) throw(GradeTooHighException, GradeTooLowException); // 매개변수 모르겠음! & 붙였다가 보고 수정함.
        Bureaucrat(const Bureaucrat& ref); // 레퍼런스에서의 const도 헷갈림.
        Bureaucrat& operator = (const Bureaucrat& ref) throw(GradeTooHighException, GradeTooLowException);
        virtual ~Bureaucrat();

        const std::string& getName() const; // 반환값 모르겠음. & 없었다가 보고 수정함.
        unsigned int getGrade() const;

        void upGrade() throw(GradeTooHighException);
        void downGrade() throw(GradeTooLowException);
};

std::ostream& operator << (std::ostream& out, const Bureaucrat& ref);

#endif