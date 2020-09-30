/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 00:09:44 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/30 23:34:10 by gmoon            ###   ########.fr       */
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
        Sorcerer& operator = (const Sorcerer& ref);
        virtual ~Sorcerer();

        // const std::string& get_name() const; // 혹시 이게 더 낫나?
        std::string get_name() const;
        std::string get_title() const;

        void polymorph(Victim const &ref);
};

std::ostream& operator << (std::ostream& out, const Sorcerer& ref);

#endif