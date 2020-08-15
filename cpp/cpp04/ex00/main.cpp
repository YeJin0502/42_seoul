/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 00:25:39 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/16 01:51:02 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"

int main()
{
    Sorcerer a("robert", "ROB");
    Sorcerer b("gmoon", "MOON");
    Sorcerer c(a);
    Sorcerer d;

    d = b;
    std::cout << d;

    Victim aa("moongua");

    std::cout << aa;
}
