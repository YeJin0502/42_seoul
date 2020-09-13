/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:39:09 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/13 22:56:01 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad : public ISquad
{
    private:
        int size_;
        ISpaceMarine** squad_;

        void deleteSquad();

    public:
        Squad();
        Squad(const Squad& ref);
        Squad& operator = (const Squad& ref);

        virtual ~Squad();
        virtual int getCount() const; // 추상클래스의 함수를 오버로딩하도록 다시 선언해야.
        virtual ISpaceMarine* getUnit(int) const;
        virtual int push(ISpaceMarine*);
};

#endif