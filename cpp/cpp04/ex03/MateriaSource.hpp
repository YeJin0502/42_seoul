/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 22:30:58 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/14 22:55:28 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria** _inven; // 맞나?
        void delInven();

    public:
        MateriaSource();
        MateriaSource(const MateriaSource& ref);
        MateriaSource& operator = (const MateriaSource& ref);
        virtual ~MateriaSource();

        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};

#endif