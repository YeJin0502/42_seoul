/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:17:26 by gmoon             #+#    #+#             */
/*   Updated: 2020/08/06 22:45:04 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOK_HPP
# define BOOK_HPP

# include <iostream>
# include "contact.hpp"

class Book
{
    private:
        Contact contacts[8];
        int     count;

    public:
        Book();
        void add();
        void search();
};

#endif