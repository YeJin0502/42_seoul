/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 21:31:01 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/07 21:53:26 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"

int main()
{
    srand(time(0));

    ZombieHorde first_horde(5);
    ZombieHorde second_horde(5, "cadet");

    first_horde.announce();
    second_horde.announce();
}
