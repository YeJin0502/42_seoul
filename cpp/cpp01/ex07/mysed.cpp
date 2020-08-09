/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 04:22:06 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/10 06:55:28 by gmoon            ###   ########.fr       */
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
    {
        line.replace(index, s1_.length(), s2_);
    }
    return (line);
}

void Mysed::mysed()
{
    std::ifstream in(filename_);
    std::string line;
    std::ofstream out(filename_ + ".replace");

    if (!in.is_open())
    {
        std::cout << "파일을 찾을 수 없습니다." << std::endl;
        return ;
        // 오류 처리를 공부해야 할 듯? 예를 들어 throw.
    }
    while (getline(in, line))
    {
        out << replace(line);
        if (!in.eof())
            out << std::endl;
    }
}

// 어짜피 목적 자체가 mysed를 실행하는 건데... 생성자에 넣어버리면 안되나? 오류 처리가 까다로워지는 걸까?

// std::ifstream in(argv[1]);
// std::string line;
// std::string content;

// // while (in.peek() != EOF) // 원래는 while (in) 이었는데 이건 한줄을 더 출력함... 정확한 공부 필요.
// while (getline(in, line)) // getline이 정확히 뭘 반환하지?
// {
//     content.append(line);
//     if (!in.eof())
//         content.append("\n");
// }
// in.close();
// std::cout << content << std::endl;

// content를 모두 저장한 뒤 바꾸는 것. - 이 방법이 직관적으로 떠오르긴 함.
// 한 라인 씩 단어 교체를 진행하고 파일에 쓰는 것. - 더 효율적일까?