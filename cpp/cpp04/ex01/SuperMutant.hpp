/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 06:51:27 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 01:11:03 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public Enemy
{
    public:
        SuperMutant();
        SuperMutant(const SuperMutant& ref);
        SuperMutant& operator = (const SuperMutant& ref);
        virtual ~SuperMutant();

        virtual void takeDamage(int damage);
};

#endif