/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 02:40:02 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/30 23:45:33 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include "Victim.hpp"

class Peon : public Victim
{
    private:
        Peon();
    
    public:
        Peon(std::string name);
        Peon(const Peon& ref);
        Peon& operator = (const Peon& ref);
        virtual ~Peon();

        virtual void getPolymorphed() const;
};

#endif