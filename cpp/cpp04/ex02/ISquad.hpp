/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:43:19 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/28 14:00:23 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

# include "ISpaceMarine.hpp"

class ISquad // 추상 클래스
{
    public:
        virtual ~ISquad() {}
        virtual int getCount() const = 0;
        virtual ISpaceMarine* getUnit(int) const = 0; // 순수 가상함수
        virtual int push(ISpaceMarine*) = 0;
};

#endif