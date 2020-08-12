/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 03:27:35 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/13 04:46:50 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
    protected:
        int hp_;
        int max_hp_;
        int energy_;
        int max_energy_;
        int level_;
        std::string name_;
        int melee_attack_;
        int ranged_attack_;
        int armor_;

    public:
        ClapTrap(std::string name);
        // ClapTrap(int hp, const int max_hp, int energy, const int max_energy, int level,
        //         const std::string name, const int melee_attack, const int ranged_attack,
        //         const int armor);
        ~ClapTrap();

        void rangedAttack(std::string const& target);
        void meleeAttack(std::string const& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif

/*
* 일부 변수들을 const로 하고 싶었는데, 상속에서는 const로 하면 자식 변수들의 값을 바꿀 수 없어 사용이 불가능한건가?
    * 가령 scavtrap은 armor가 3인 것이 고정... 바뀌지 않는다고 한다면 이런 것을 const로 하는게 아닌가?
    * 일단 시도해볼 방법 중 하나는, ClapTrap(모든 멤버 변수...) 생성자를 만들어서, 자식 클래스에서 초기화할 때 사용하면 가능한 듯. 이는 https://github.com/Caceresenzo/42/blob/master/CPP%20Modules/03/ex02/FragTrap.cpp 의 FragTrap 생성자의 방법을 참고했음.
    * 하지만 const 변수는 생성자 이전에 초기화를 해주어야 하는데, 어떤 값으로 초기화할지 애매해다... 어쨌거나 더 복잡해져서 관둠.
    * 인스턴스들마다 각자 고유한, 한 번 정해지면 바꾸지 않는 값을 const로 하는 것이 아닌건가? const를 잘 못 생각하고 있는건가?

* 한편 위의 문제와 더불어, 멤버 변수를 어떤 식으로 초기화하는 것이 좋을지... 특히 상속까지 더해지니 더 모르겠다.

* 위 깃허브에서 주목할 점
    * 스킬 목록을 static const std::string attacks[] = { ... } 이런 식으로 선언.

* 공부할 점
    * std::ostream& 을 반환하는 함수?
    * virtual?
    * const int와 int const가 다른가?
*/
