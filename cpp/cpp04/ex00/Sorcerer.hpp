/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 00:09:44 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/30 17:00:59 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
    private:
        std::string name_;
        std::string title_;
        Sorcerer();

    public:
        Sorcerer(std::string name, std::string title);
        Sorcerer(const Sorcerer& ref);
        virtual ~Sorcerer();
        Sorcerer& operator = (const Sorcerer& ref);

        const std::string& get_name() const;
        // const std::string& get_name(); // 안됨.
        // std::string& get_name() const; // 안됨.
        const std::string& get_title() const;

        void polymorph(Victim const &ref);
};

std::ostream& operator << (std::ostream& out, const Sorcerer& ref);

#endif