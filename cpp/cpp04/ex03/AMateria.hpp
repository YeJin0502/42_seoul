/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 11:47:48 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/14 12:14:06 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class AMateria
{
    private:
        std::string const & _type;
        unsigned int _xp;

    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& ref);
        AMateria& operator = (const AMateria& ref);
        virtual ~AMateria();

        std::string const & getType() const; //Returns the materia type
        unsigned int getXP() const; //Returns the Materia's XP

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif