/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:59:47 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/28 16:05:49 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span()
// :   arr_(std::vector<int>(0)), size_(0), saved_(0)
:   arr_(std::vector<int>(0)), saved_(0)
{}

Span::Span(unsigned int n)
// :   arr_(std::vector<int>(n)), size_(n), saved_(0)
:   arr_(std::vector<int>(n)), saved_(0)
{}

Span::Span(const Span& ref)
{
    *this = ref;
}

Span&
Span::operator = (const Span& ref)
{
    if (this != &ref)
    {
        arr_ = ref.arr_;
        // size_ = ref.size_;
        saved_ = ref.saved_;
    }
    return (*this);
}

Span::~Span()
{}

void
Span::addNumber(int num) throw(SpanError)
{
    if (saved_ == arr_.size())
        throw SpanError("Can't add number.");

    arr_[saved_] = num;
    saved_ += 1;
    // std::cout << arr_.size() << std::endl;
}

unsigned int
Span::shortestSpan() throw(SpanError)
{
    if (saved_ == 0 || saved_ == 1)
        throw SpanError("No numbers stored, or only one.");

    std::sort(arr_.begin(), arr_.end()); // arr_ 내부에서 sort되는 것 같은데, 내부는 그대로고 sort된 컨테이너를 반환하는 법은 없나?

    std::vector<int> diffs;

    for (unsigned int i = 0; i < arr_.size() - 1; i++)
        diffs.push_back(arr_[i + 1] - arr_[i]);
    std::sort(diffs.begin(), diffs.end());

    return (diffs.front());
}

unsigned int
Span::longestSpan() throw(SpanError)
{
    if (saved_ == 0 || saved_ == 1)
        throw SpanError("No numbers stored, or only one.");

    std::sort(arr_.begin(), arr_.end());

    return (arr_.back() - arr_.front());
}

Span::SpanError::SpanError()
{}

Span::SpanError::SpanError(const SpanError& ref)
{
    *this = ref;
}

Span::SpanError&
Span::SpanError::operator = (const SpanError& ref)
{
    if (this != &ref)
        msg_ = ref.msg_;
    return (*this);
}

Span::SpanError::SpanError(std::string msg)
:   msg_(msg)
{}

Span::SpanError::~SpanError()
{}

const char*
Span::SpanError::what() const throw()
{
    return (msg_.c_str());
}

void
Span::test_print() const
{
    for (unsigned int i = 0; i < arr_.size(); i++)
    {
        std::cout << "test: " << arr_[i] << std::endl;
        if (i > 10)
            break ;
    }
}

void
Span::fillRandom()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    // std::uniform_int_distribution<int> dis(INT32_MIN, INT32_MAX);
    std::uniform_int_distribution<int> dis(-100, 100);

    for (unsigned int i = 0; i < arr_.size(); i++)
        arr_[i] = dis(gen);
    
    saved_ = arr_.size();
}
