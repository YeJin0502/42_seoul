/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:31:07 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/23 15:49:17 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <string>
# include <iomanip>

class Conversion
{
    private:
        // char* str_;
        std::string str_;

    public:
        Conversion(char* str);
        Conversion(const Conversion& ref);
        Conversion& operator = (const Conversion& ref);
        ~Conversion();

        class convertError : public std::exception
        {
            private:
                std::string msg_;
            public:
                convertError(std::string msg);
                virtual const char* what() const throw();
        };

        char toChar() throw(convertError);
        int toInt() throw(convertError);
        float toFloat() throw(convertError);
        double toDouble() throw(convertError);

        void printAll();
};

#endif