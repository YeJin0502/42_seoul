/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 01:36:37 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/16 01:52:49 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim
{
    private:
        std::string name_;

    public:
        Victim();
        Victim(std::string name);
        Victim(Victim& ref);
        virtual ~Victim();
        Victim& operator = (Victim& ref);

        const std::string& get_name() const;
};

std::ostream& operator << (std::ostream& out, const Victim& ref); // const를 빼면 컴파일 안됨. 왜?

#endif