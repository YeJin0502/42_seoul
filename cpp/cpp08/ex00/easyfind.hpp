/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 11:35:10 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/28 12:51:54 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <iostream>
# include <map>

class NotFoundValue : public std::exception
{
    public:
        virtual const char* what() const throw()
        {
            return ("No such value is found.");
        }
};

template <typename T>
typename T::iterator easyfind(T container, int value) // 여기에는 왜 typename?
{
    typename T::iterator ret = std::find(container.begin(), container.end(), value); // 여기에는 왜 typename?
    // typename T::iterator ret = container.find(container.begin(), container.end(), value);

    // if (ret == container.end())
    //     throw std::exception("No such value is found."); // 생성자로는 바로 못만드나?
    
    if (ret == container.end())
        throw NotFoundValue();

    return (ret);
}

std::map<int, int>::iterator easyfind(std::map<int, int> container, int value) // 중복 함수 작성
{
    std::map<int, int>::iterator ret = container.find(value);

    if (ret == container.end())
        throw NotFoundValue();

    return (ret);
}

#endif