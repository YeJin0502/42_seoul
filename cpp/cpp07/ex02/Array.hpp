/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:57:47 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/25 13:37:14 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <class T> // typename하고 차이가 없나?
class Array
{
    private:
        // T* array_ = nullptr;
        T* array_;
        unsigned int size_;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array& ref);
        Array& operator=(const Array& ref);
        ~Array();

        T& operator[](unsigned int n) throw (std::exception);
        unsigned int size() const;
};

template <class T>
Array<T>::Array()
{
    // if (array_)
        // delete[] array_; // 안전하다면 왜 delete[]하면 seg fault가 뜨지?

    size_ = 0;
    array_ = new T[0]; // 빈 배열이 뭐지?
    // array_ = nullptr; // 위하고 차이가 뭐지?
}

template <class T>
Array<T>::Array(unsigned int n)
{
    // if (array_)
    // {
    //     std::cout << "array_: " << array_ << std::endl; // 배열이 할당되기 전에도 array_는 있다.
    //     delete[] array_; // 그러면 어떻게 배열이 할당되었을 때만 delete를 하게 검사하지?
    // }

    size_ = n;
    array_ = new T[size_];
}

template <class T>
Array<T>::Array(const Array& ref)
{
    *this = ref;
}

template <class T>
Array<T>&
Array<T>::operator=(const Array& ref)
{
    if (this != &ref)
    {
        if (array_)
            delete[] array_; // 잘 검사가 되는걸까?

        size_ = ref.size_; // 매개변수로 전달되면 private에 접근 가능한건가? private의 정의가 헷갈림.
        array_ = new T[size_];
        for (unsigned int i = 0; i < size_; i++)
            array_[i] = ref.array_[i];
    }
    return (*this);
}

template <class T>
Array<T>::~Array()
{
    // if (array_)
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

#endif