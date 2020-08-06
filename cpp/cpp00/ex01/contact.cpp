/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 16:30:38 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 00:07:35 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

std::string Contact::fields_name[11] =
{
    "first_name", "last_name", "nickname", "login",
    "postal_address", "email_address", "phone_number", "birthday_date",
    "favorite_meal", "underwear_color", "darkest_secret"
};

void Contact::init(int index)
{
    this->index = index;
    for (int i = 0; i < 11; i++)
    {
        std::cout << fields_name[i] << "를 입력하세요: ";
        getline(std::cin, fields[i], '\n');
    }
}

void Contact::display_summary()
{
    std::cout << "|" << std::setw(10) << index << "|";
    for (int i = first_name; i <= nickname; i++)
    {
        if (fields[i].length() > 10)
            std::cout << fields[i].substr(0, 9) + "." << "|";
        else
            std::cout << std::setw(10) << fields[i] << "|";
    }
    std::cout << std::endl;
}

void Contact::display_fields()
{
    for (int i = 0; i < 11; i++)
        std::cout << fields_name[i] + ": " + fields[i] << std::endl;
}
