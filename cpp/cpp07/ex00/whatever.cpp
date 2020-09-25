/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 09:55:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/25 10:29:20 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T min(T a, T b)
{
    if (a < b)
        return a;
    else
        return b;
}

template <typename T>
T max(T a, T b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    std::cout << "==============================" << std::endl;

    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    std::cout << "==============================" << std::endl;
    
    int i1 = 1, i2 = 2;
    swap<int>(i1, i2);
    std::cout << i1 << " " << i2 << std::endl;
    ::swap(i1, i2);
    std::cout << i1 << " " << i2 << std::endl;

    std::cout << "==============================" << std::endl;

    // double a = 1.5, b = 1.8; // a, b 이름을 다시 쓰면 `error: redefinition of 'a' with a different type: 'double' vs 'int'` 오류.
    double aa = 1.5, bb = 1.8;
    swap<double>(aa, bb);
    std::cout << aa << " " << bb << std::endl;
    ::swap(aa, bb);
    std::cout << aa << " " << bb << std::endl;

    std::cout << "==============================" << std::endl;

    std::string s1 = "he", s2 = "llo";
    // swap<std::string>(s1, s2); // 이건 `error: call to 'swap' is ambiguous` 오류. 왜?
    swap(s1, s2);
    std::cout << s1 << " " << s2 << std::endl;

    std::cout << "==============================" << std::endl;
   
    std::cout << min<int>(1, 2) << std::endl;
    std::cout << ::min(1.1, 1.2) << std::endl;
    std::cout << min("aa", "ab") << std::endl;

    std::cout << "==============================" << std::endl;

    std::cout << ::max(1, 2) << std::endl;
    std::cout << ::max(1.1, 1.2) << std::endl;
    std::cout << ::max("aa", "ab") << std::endl;

    std::cout << "==============================" << std::endl;
}
