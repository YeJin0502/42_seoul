/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 12:02:54 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/25 12:39:52 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cpp 파일을 따로 만들어서 멤버 함수를 구현하면, 컴파일 오류 발생.

/*
#include "Array.hpp"

template <class T>
Array<T>::Array()
{
    if (array_)
        delete[] array_; // 맞나?
    size_ = 0;
    // array_ = new T[0]; // 되나? 빈 배열이 뭐지?
    array_ = nullptr;
}

template <class T>
Array<T>::Array(unsigned int n)
{
    if (array_)
        delete[] array_;
    size_ = n;
    array_ = new T[size_];
}

template <class T>
Array<T>::Array(const Array& ref)
{
    // if (array_)
    //     delete[] array_;

    // size_ = ref.size_; // 매개변수로 전달되면 private에 접근 가능한가?

    // array_ = new T[size_];
    // for (unsigned int i = 0; i < size_; i++)
    //     array_[i] = ref[i];

    *this = ref;
}

template <class T>
Array<T>&
Array<T>::operator=(const Array& ref)
{
    if (this != &ref)
    {
        if (array_)
            delete[] array_;

        size_ = ref.size_; // 매개변수로 전달되면 private에 접근 가능한가?
        array_ = new T[size_];
        for (unsigned int i = 0; i < size_; i++)
            array_[i] = ref[i];
    }
    return (this);
}

template <class T>
Array<T>::~Array()
{
    if (array_) // 없는 경우가 있나?
        delete[] array_;
}

template <class T>
T&
Array<T>::operator[](unsigned int n) throw (std::exception)
{
    if (n >= size_)
        throw std::exception();
    return (array_[n]);
}

template <class T>
unsigned int
Array<T>::size() const
{
    return (size_);
}
*/