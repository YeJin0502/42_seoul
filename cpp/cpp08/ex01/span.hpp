/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:45:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/28 15:58:46 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

// # include <array>
# include <vector>
# include <algorithm>
# include <iostream>
# include <random>

class Span
{
    private:
        std::vector<int> arr_;
        // unsigned int size_;
        unsigned int saved_;
        Span();

    public:
        Span(unsigned int n);
        Span(const Span& ref);
        Span& operator = (const Span& ref);
        ~Span();

        class SpanError : public std::exception
        {
            private:
                std::string msg_;
                SpanError();
            public:
                SpanError(std::string msg);
                SpanError(const SpanError& ref);
                SpanError& operator = (const SpanError& ref);
                virtual ~SpanError();
                virtual const char* what() const throw();
        };

        void addNumber(int num) throw(SpanError);
        unsigned int shortestSpan() throw(SpanError);
        unsigned int longestSpan() throw(SpanError);
        
        void fillRandom();
        void test_print() const;
};

#endif