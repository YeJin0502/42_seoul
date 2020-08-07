/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 16:43:17 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 17:31:38 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_HPP
# define PONY_HPP

# include <iostream>

class Pony
{
    private:
        std::string name; // 아직 const 초기화하는 법 잘 모름.

    public:
        Pony(std::string name);
        ~Pony();
        void say_hello();
        void turn_music();
};

#endif