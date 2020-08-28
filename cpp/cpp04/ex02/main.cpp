/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 08:16:28 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/28 13:36:28 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main()
{
    ISpaceMarine *bob = new TacticalMarine;
    ISpaceMarine *jim = new AssaultTerminator;

    ISquad *vlc = new Squad;
    vlc->push(bob);
    vlc->push(jim);
    for (int i = 0; i < vlc->getCount(); ++i)
    {
        ISpaceMarine *cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }
    delete vlc;

    return 0;
}

/*
Tactical Marine ready for battle!$
* teleports from space *$
For the holy PLOT!$
* attacks with a bolter *$
* attacks with a chainsword *$
This code is unclean. PURIFY IT!$
* does nothing *$
* attacks with chainfists *$
Aaargh...$
I'll be back...$
*/
