/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:22:59 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/08 15:39:09 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class Human
{
    const Brain brain_;

    public:
        Human();
        std::string     identify() const;
        const Brain&    getBrain() const; // 레퍼런스를 반환 안하면 주소가 다름.
};

#endif