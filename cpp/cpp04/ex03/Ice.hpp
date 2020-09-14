/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:18:01 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/14 18:33:43 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        // Ice(std::string const & type);
        Ice(const Ice& ref);
        Ice& operator = (const Ice& ref);
        virtual ~Ice();

        virtual Ice* clone() const;
        virtual void use(ICharacter& target);
}; // 맞나?

#endif