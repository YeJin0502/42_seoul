/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 01:36:37 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/30 23:45:35 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim
{
    protected:
        std::string name_;
        Victim();

    public:
        Victim(std::string name);
        Victim(const Victim& ref);
        Victim& operator = (const Victim& ref);
        virtual ~Victim();

        std::string get_name() const;

        virtual void getPolymorphed() const;
};

std::ostream& operator << (std::ostream& out, const Victim& ref); // const를 빼면 컴파일 안됨. 왜?

#endif