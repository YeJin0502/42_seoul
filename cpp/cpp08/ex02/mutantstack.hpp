/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:32:16 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/29 14:19:51 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {}
        MutantStack(const MutantStack& ref)
        {
            std::stack<T>::operator = (ref); // 연산자 함수 쓰는 것이 어색함.
        }
        MutantStack& operator = (const MutantStack& ref)
        {
            std::stack<T>::operator = (ref);
            return (*this); // 복사 생성자랑 할당 연산자 맞게 했나?
        }
        virtual ~MutantStack() {}

        // auto begin(); // 반환 타입을 auto로 하는 것은 C++ 14부터.
        // {
        //     return (this->c.begin());
        // }
        // auto end()
        // {
        //     return (this->c.end());
        // }

        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        typename std::stack<T>::container_type::iterator begin() // iterator로 바꾸는게 낫지만, 형식 어색하니 연습삼아 다 적음.
        {
            return (this->c.begin());
        }
        typename std::stack<T>::container_type::const_iterator cbegin() const noexcept
        {
            return (this->c.cbegin());
        }

        typename std::stack<T>::container_type::iterator end()
        {
            return (this->c.end());
        }
        typename std::stack<T>::container_type::const_iterator cend() const noexcept
        {
            return (this->c.cend());
        }

        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

        typename std::stack<T>::container_type::reverse_iterator rbegin()
        {
            return (this->c.rbegin());
        }
        typename std::stack<T>::container_type::const_reverse_iterator crbegin() const noexcept
        {
            return (this->c.crbegin());
        }

        typename std::stack<T>::container_type::reverse_iterator rend()
        {
            return (this->c.rend());
        }
        typename std::stack<T>::container_type::const_reverse_iterator crend() const noexcept
        {
            return (this->c.crend());
        }
};

#endif