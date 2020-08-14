/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 23:59:51 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/14 21:42:21 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    hp_ = 100;
    max_hp_ = 100;
    energy_ = 100;
    max_energy_ = 100;
    level_ = 1;
    melee_attack_ = 30;
    ranged_attack_ = 20;
    armor_ = 5;

    std::cout << "FR4G-TP(이름 없음)이(가) 생성되었습니다." << std::endl;
}

FragTrap::FragTrap(std::string name)
: name_(name)
{
    hp_ = 100;
    max_hp_ = 100;
    energy_ = 100;
    max_energy_ = 100;
    level_ = 1;
    melee_attack_ = 30;
    ranged_attack_ = 20;
    armor_ = 5;

    std::cout << "FR4G-TP " + name_ + "이(가) 생성되었습니다." << std::endl;
}

FragTrap::FragTrap(const FragTrap& ref)
{
    *this = ref; // 헷갈림.
}

FragTrap::~FragTrap()
{
    std::cout << "FR4G-TP " + name_ + "이(가) 소멸합니다." << std::endl;
}

FragTrap&
FragTrap::operator = (const FragTrap& ref)
{
    if (this != &ref) // &ref 의 의미를 잘 모르겠고, 이 조건문이 필요한 것도 아직 모르겠음.
    {
        hp_ = ref.hp_;
        max_hp_ = ref.max_hp_;
        energy_ = ref.energy_;
        max_energy_ = ref.max_energy_;
        level_ = ref.level_;
        melee_attack_ = ref.melee_attack_;
        ranged_attack_ = ref.ranged_attack_;
        armor_ = ref.armor_;
    }
    return (*this); // 헷갈림.
}

void
FragTrap::rangedAttack(std::string const& target)
{
    std::cout << "FR4G-TP " << name_ << "이(가) 타겟 " << target << "을(를) 범위 공격하였습니다. " << std::endl;
    std::cout << ranged_attack_ << " 데미지를 입혔습니다." << std::endl;
}

void
FragTrap::meleeAttack(std::string const& target)
{
    std::cout << "FR4G-TP " << name_ << "이(가) 타겟 " << target << "을(를) 밀리 공격하였습니다. " << std::endl;
    std::cout << melee_attack_ << " 데미지를 입혔습니다." << std::endl;
}

void
FragTrap::takeDamage(unsigned int amount)
{
    int damage = amount - armor_;

    if (damage < 0) damage = 0;
    hp_ -= damage;
    if (hp_ < 0) hp_ = 0;

    std::cout << "FR4G-TP " << name_ << "이(가) ";
    std::cout << amount - armor_ << "만큼 데미지를 입었습니다. " << std::endl;
    std::cout << "HP가 " << hp_ << "가 되었습니다." << std::endl;
}

void
FragTrap::beRepaired(unsigned int amount)
{
    hp_ += amount;
    if (hp_ > max_hp_) hp_ = max_hp_;
    energy_ += amount;
    if (energy_ > max_energy_) energy_ = max_energy_;

    std::cout << "FR4G-TP " << name_ << "이(가) ";
    std::cout << amount << "만큼 회복하였습니다. " << std::endl;
    std::cout << "HP가 " << hp_ << "이(가) 되었습니다." << std::endl;
    std::cout << "ENERGY가 " << energy_ << "이(가) 되었습니다." << std::endl;
}

void
FragTrap::vaulthunter_dot_exe(std::string const& target)
{
    if (energy_ - 25 < 0)
    {
        std::cout << "에너지가 부족합니다." << std::endl;
        return ;
    }
    energy_ -= 25;

    int index = rand() % 5;

    switch (index)
    {
        case 0: miniontrap(target); break ;
        case 1: meat_unicycle(target); break ;
        case 2: funzerker(target); break ;
        case 3: mechmagician(target); break ;
        case 4: shhhh_trap(target); break ;
    }
}

void
FragTrap::miniontrap(std::string const& target)
{
    std::cout << "FR4G-TP " << name_ << "이(가) 타겟 " << target << "에게 Miniontrap 스킬을 사용합니다. " << std::endl;
    std::cout << "\"미니언 대령이요!\"" << std::endl;
    std::cout << "30 데미지를 입혔습니다." << std::endl;
}

void
FragTrap::meat_unicycle(std::string const& target)
{
    std::cout << "FR4G-TP " << name_ << "이(가) 타겟 " << target << "에게 Meat unicycle 스킬을 사용합니다. " << std::endl;
    std::cout << "\"총쏘지마! 휘둘러! 휘둘러! 휘둘러!\"" << std::endl;
    std::cout << "15 데미지를 입혔습니다." << std::endl;
}

void
FragTrap::funzerker(std::string const& target)
{
    std::cout << "FR4G-TP " << name_ << "이(가) 타겟 " << target << "에게 Funzerker 스킬을 사용합니다. " << std::endl;
    std::cout << "\"쏘는걸! 멈출수가! 없어!\"" << std::endl;
    std::cout << "50 데미지를 입혔습니다." << std::endl;
}

void
FragTrap::mechmagician(std::string const& target)
{
    std::cout << "FR4G-TP " << name_ << "이(가) 타겟 " << target << "에게 Mechomagician 스킬을 사용합니다. " << std::endl;
    std::cout << "\"예측불허! 포풍간지!\"" << std::endl;
    std::cout << "20 데미지를 입혔습니다." << std::endl;
}

void
FragTrap::shhhh_trap(std::string const& target)
{
    std::cout << "FR4G-TP " << name_ << "이(가) 타겟 " << target << "에게 Shhhh....trap 스킬을 사용합니다. " << std::endl;
    std::cout << "\"홀로그램 가동\"" << std::endl;
    std::cout << "0 데미지를 입혔습니다." << std::endl;
}
