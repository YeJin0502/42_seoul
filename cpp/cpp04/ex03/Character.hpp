/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:40:10 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 16:17:24 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
        std::string _name;
        AMateria** _inven;
        // AMateria*[4] _inven; // 이런 식으로 하고, ` _inven = new AMateria*[4];`을 생략할 수 있음.

        Character();
        void delInven();

    public:
        Character(std::string const & name);
        Character(const Character& ref);
        Character& operator = (const Character& ref);
        virtual ~Character();

        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

# endif