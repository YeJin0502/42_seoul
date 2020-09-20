/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 21:54:04 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/19 23:05:28 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"

# define GRADE_FOR_SIGN 145
# define GRADE_FOR_EXEC 137

class ShrubberyCreationForm : public Form
{
    private:
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& ref);
        ShrubberyCreationForm& operator = (const ShrubberyCreationForm& ref);
        virtual ~ShrubberyCreationForm();

        virtual void execute(Bureaucrat const & executor) const throw(NotSigned, GradeTooLowException);
};

#endif