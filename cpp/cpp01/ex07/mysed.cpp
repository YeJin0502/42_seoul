/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 04:22:06 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/10 16:26:34 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mysed.hpp"

Mysed::Mysed(std::string filename, std::string s1, std::string s2)
: filename_(filename), s1_(s1), s2_(s2)
{
    // 레퍼런스와 const만 이런 식으로 초기화하는 건가? 검색 키워드가 뭐지?
    // 이런 식으로 하는 것이 낫나?
}

std::string Mysed::replace(std::string line)
{
    int index;

    while ((index = line.find(s1_)) != -1)
        line.replace(index, s1_.length(), s2_);
    return (line);
}

void Mysed::mysed()
{
    std::ifstream in(filename_);
    std::string line;

    if (filename_.length() == 0 || s1_.length() == 0 || s2_.length() == 0)
        throw "비어있는 인자가 있습니다.";
    if (!in.is_open())
        throw "파일을 열 수 없습니다.";

    std::ofstream out(filename_ + ".replace");

    if (!out.is_open())
        throw "replace 파일을 생성할 수 없습니다.";
    while (getline(in, line))
    {
        out << replace(line);
        if (!in.eof())
            out << std::endl;
    }
}

// 어짜피 목적 자체가 mysed를 실행하는 건데... 생성자에 넣어버리면 안되나? 오류 처리가 까다로워지는 걸까?