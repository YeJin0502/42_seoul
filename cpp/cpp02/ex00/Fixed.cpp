/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:38:57 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/11 20:30:04 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::BITS_ = 8;

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;

    fixed_point_value_ = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
    std::cout << "Copy constructor called" << std::endl;

    *this = ref;
}

Fixed &Fixed::operator=(const Fixed &ref) // 이렇게 쓰는거 맞나?
{
    std::cout << "Assignation operator called" << std::endl;

    fixed_point_value_ = ref.getRawBits();
    return (*this);
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;

    return (fixed_point_value_); // 로우 비트가 뭔지를 모르겠음. 고정 소수점을 몰라서 ㅠㅠ
}

void Fixed::setRawBits(int const raw)
{
    fixed_point_value_ = raw;
}
