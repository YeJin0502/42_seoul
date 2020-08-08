/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 15:28:31 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/08 15:38:16 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

Human::Human()
{
    
}

std::string Human::identify() const
{
    return (brain_.identify());
}

const Brain& Human::getBrain() const
{
    return (brain_);
}
