/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:08:45 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 00:08:07 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
    private:
        int                 index;
        std::string         fields[11];
        static std::string  fields_name[11];

        enum fields_name {
            first_name = 0, last_name, nickname, login,
            postal_address, email_address, phone_number, birthday_date,
            favorite_meal, underwear_color, darkest_secret
        };

    public:
        void init(int index);
        void display_summary();
        void display_fields();
};

#endif
