/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 07:04:21 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/16 07:45:55 by gmoon            ###   ########.fr       */
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

    public:
        // Character();
        Character(std::string const & name);
        Character(const Character& ref);
        virtual ~Character();
        Character& operator = (const Character& ref);

        void recoverAP();
        void equip(AWeapon*);
        void attack(Enemy*);

        std::string const & getName() const;
        AWeapon* getWeapon() const;
        int const & getAP() const; // int & 로 처음에 바꿨는데, int const & 로 해야 컴파일이 됨.
};

std::ostream& operator << (std::ostream& out, const Character& ref);

#endif