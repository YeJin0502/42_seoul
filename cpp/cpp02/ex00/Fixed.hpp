/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:39:01 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/12 21:06:03 by gmoon            ###   ########.fr       */
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
        Fixed& operator = (const Fixed& ref);
        int getRawBits() const;
        void setRawBits(int const raw);
};

#endif