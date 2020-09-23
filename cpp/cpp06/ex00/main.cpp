/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:35:59 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/23 15:58:05 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"

int main(int argc, char** argv)
{
    if (!argv)
        return (1);

    if (argc != 2)
    {
        std::cout << "argc must be 2." << std::endl;
        return (1);
    }

    Conversion conv(argv[1]);

    conv.printAll();
}
