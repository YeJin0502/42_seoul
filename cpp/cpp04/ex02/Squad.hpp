/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:39:09 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/28 14:58:53 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISquad.hpp"

class Squad : public ISquad
{
    private:
        int size_;
        ISpaceMarine** squad_; // 이중 포인터인 이유가 뭐지? 일중 포인터는 안될까? 수정을 위해?

    public:
        Squad();
        Squad(const Squad& ref);
        Squad& operator = (const Squad& ref);

        virtual ~Squad() {}
        virtual int getCount() const; // 추상클래스의 함수를 오버로딩하도록 다시 선언해야.
        virtual ISpaceMarine* getUnit(int) const;
        virtual int push(ISpaceMarine*);
};

#endif