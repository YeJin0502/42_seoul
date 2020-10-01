/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:47:48 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 15:19:42 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria
{
    private:
        std::string _type;
        unsigned int _xp;
        AMateria();

    public:
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