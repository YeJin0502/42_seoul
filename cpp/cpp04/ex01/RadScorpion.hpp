/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 06:58:32 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 01:13:35 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

# include "Enemy.hpp"

class RadScorpion : public Enemy
{
    public:
        RadScorpion();
        RadScorpion(const RadScorpion& ref);
        RadScorpion& operator = (const RadScorpion& ref);
        virtual ~RadScorpion();
};

#endif