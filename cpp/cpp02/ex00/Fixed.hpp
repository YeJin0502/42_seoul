/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:39:01 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/11 17:16:52 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int fixed_point_value_; // 작명을 바꿔야할텐데 아직은...
        const static int bits_; // 이렇게 하라는건가?

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed& ref);
        Fixed operator = (Fixed& f);
        int getRawBits() const;
        void setRawBits(int const raw);
};

#endif