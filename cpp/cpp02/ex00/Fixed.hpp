/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:39:01 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/11 20:19:06 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int fixed_point_value_;
        const static int BITS_;

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& ref);
        Fixed &operator = (const Fixed& ref); // 연산자 오버로딩을 집가서 봐야. &는 왜 붙이는걸까?
        int getRawBits() const;
        void setRawBits(int const raw);
};

#endif