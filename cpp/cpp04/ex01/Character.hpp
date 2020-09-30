/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 07:04:21 by gmoon             #+#    #+#             */
/*   Updated: 2020/10/01 01:16:07 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
    private:
        std::string name_;
        int ap_;
        AWeapon* weapon_;
        Character();

    public:
        Character(std::string const & name);
        Character(const Character& ref);
        Character& operator = (const Character& ref);
        virtual ~Character();

        void recoverAP();
        void equip(AWeapon*);
        void attack(Enemy*);

        std::string getName() const;
        AWeapon* getWeapon() const;
        int getAP() const;
};

std::ostream& operator << (std::ostream& out, const Character& ref);

#endif