/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:38:57 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/12 21:11:12 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::BITS_ = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;

    fixed_point_value_ = 0;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;

    fixed_point_value_ = value << BITS_;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;

    fixed_point_value_ = roundf(value * (1 << BITS_));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& ref)
{
    std::cout << "Copy constructor called" << std::endl;

    *this = ref;
}

Fixed& Fixed::operator = (const Fixed& ref)
{
    std::cout << "Assignation operator called" << std::endl;

    fixed_point_value_ = ref.getRawBits();
    return (*this);
}

int Fixed::getRawBits() const
{
    return (fixed_point_value_);
}

void Fixed::setRawBits(int const raw)
{
    fixed_point_value_ = raw;
}

float Fixed::toFloat() const
{
    return ((float)fixed_point_value_ / (1 << BITS_));
}

int Fixed::toInt() const
{
    return (fixed_point_value_ >> BITS_);
}

std::ostream& operator << (std::ostream& os, const Fixed& ref)
{
    os << ref.toFloat();
    return (os);
}
