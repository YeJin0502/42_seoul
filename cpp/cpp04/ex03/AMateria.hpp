/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:47:48 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/14 18:13:54 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter; // 이렇게 안하면 오류나려나?

class AMateria
{
    private:
        // std::string const & _type;
        std::string _type; // 어떻게 하는 것이 적절하지?
        unsigned int _xp;

    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& ref);
        AMateria& operator = (const AMateria& ref);
        virtual ~AMateria();

        std::string const & getType() const;
        unsigned int getXP() const;

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

# include "ICharacter.hpp"

#endif