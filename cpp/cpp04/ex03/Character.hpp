/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:40:10 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/14 21:59:25 by gmoon            ###   ########.fr       */
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
        // AMateria*[4] _inven; // 이런 식으로는?

        void delInven();

    public:
        Character();
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