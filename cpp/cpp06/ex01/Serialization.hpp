/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:41:58 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/25 06:50:51 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <random>
# include <limits>

typedef struct s_Data {std::string s1; int n; std::string s2;} Data;

class Serialization
{
    public:
        Serialization();
        Serialization(const Serialization& ref);
        Serialization& operator = (const Serialization& ref);
        ~Serialization();

        void* serialize(void);
        Data* deserialize(void* raw);
};

#endif