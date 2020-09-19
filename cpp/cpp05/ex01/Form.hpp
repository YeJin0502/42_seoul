/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 17:43:25 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/19 18:45:09 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name_; // const가 앞에?
        bool sign_ = false;
        const int grade_for_sign_; // const는 다시 내손으로 정리해봐야.
        const int grade_for_exec_;

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

        Form();
        Form(std::string name, int grade_for_sign, int grade_for_exec) throw(GradeTooHighException, GradeTooLowException);
        Form(const Form& ref) throw(GradeTooHighException, GradeTooLowException); // 엄밀히는 위에서 다 걸러져서 여기서는 할 필요 없지 않나?
        Form& operator = (const Form& ref);
        virtual ~Form();

        std::string getName() const;
        bool getSign() const;
        int getGradeForSign() const;
        int getGradeForExec() const;

        void beSigned(Bureaucrat& bur) throw(GradeTooLowException); // 매개변수로 뭘 받지?
};

std::ostream& operator << (std::ostream& out, const Form& ref);

#endif