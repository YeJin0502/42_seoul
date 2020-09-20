/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 01:09:56 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/20 01:33:59 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

// # include <iostream>
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        class InvalidName : public std::exception
        {
            virtual const char* what() const throw();
        };

        Intern();
        Intern(const Intern& ref);
        Intern& operator = (const Intern& ref);
        ~Intern();

        Form* makeForm(std::string name, std::string target)
            throw(InvalidName);
};

#endif