/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:40:02 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/16 03:37:15 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon : public Victim
{
    public:
        Peon();
        Peon(std::string name);
        Peon(const Peon& ref);
        virtual ~Peon();
        // Peon& operator = (const Peon& ref); // 안해도 되나? 왜? 상속을 정확히 모르겠다.
};

#endif