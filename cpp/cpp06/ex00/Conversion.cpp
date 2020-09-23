/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:43:14 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/23 15:57:44 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

Conversion::Conversion(char* str)
: str_(static_cast<std::string>(str)) // 안해도 되긴 하는데... 배운거 써먹어보려고... 아직 잘 모르긴 함.
// : str_(str) // 이렇게 해도 똑같이 됨.
{}

Conversion::Conversion(const Conversion& ref)
:   str_(static_cast<std::string>(ref.str_))
{}

Conversion&
Conversion::operator = (const Conversion& ref)
{
    if (this != &ref)
    {
        str_ = static_cast<std::string>(ref.str_);
    }
    return (*this);
}

Conversion::~Conversion()
{}

Conversion::convertError::convertError(std::string msg)
: msg_(msg)
{}

const char*
Conversion::convertError::what() const throw()
{
    return (msg_.c_str());
}

char
Conversion::toChar() throw(convertError)
{
    char char_;

    try
    {
        char_ = std::stoi(str_);
    }
    catch (std::exception & e)
    {
        throw convertError("impossible");
    }
    
    if (!isprint(char_))
        throw convertError("Non displayable");
    
    return (char_);
}

int
Conversion::toInt() throw(convertError)
{
    int int_;

    try
    {
        int_ = std::stoi(str_);
    }
    catch (std::exception & e)
    {
        throw convertError("impossible");
    }

    return (int_);
}

float
Conversion::toFloat() throw(convertError)
{
    float float_;
    
    try
    {
        float_ = std::stof(str_);
    }
    catch (std::exception & e)
    {
        throw convertError("impossible");
    }

    return (float_);
}

double
Conversion::toDouble() throw(convertError)
{
    double double_;

    try
    {
        double_ = std::stod(str_);
    }
    catch (std::exception & e)
    {
        throw convertError("impossible");
    }

    return (double_);
}

void
Conversion::printAll()
{
    try
    {
        std::cout << "char: " << toChar() << std::endl;
    }
    catch (convertError & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "int: " << toInt() << std::endl;
    }
    catch (convertError & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << std::fixed;
        std::cout.precision(1);
        std::cout << "float: " << toFloat() << "f" << std::endl;
    }
    catch (convertError & e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "double: " << toDouble() << std::endl;
    }
    catch (convertError & e)
    {
        std::cout << e.what() << std::endl;
    }
}
