/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 04:15:18 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/10 16:08:50 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSED_HPP
# define MYSED_HPP

# include <iostream>
# include <fstream>
// # include <sstream> // stringstream

class Mysed
{
    private:
        const std::string filename_;
        const std::string s1_;
        const std::string s2_;
        // 바뀌지 않는데 const로 하는 것이 나을까?

        std::string replace(std::string line);
        // 여기에 할바엔 그냥 c처럼 static 함수로 하는게 낫나? 근데 그러면 파일 분리가 피곤할 듯.

    public:
        Mysed(std::string filename, std::string s1, std::string s2);

        void mysed();
};

#endif