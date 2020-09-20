/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 06:43:55 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/21 01:07:32 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

# include "Intern.hpp"
# include "Bureaucrat.hpp"

class OfficeBlock
{
    private:
        Intern* intern_;
        Bureaucrat* signer_;
        Bureaucrat* executor_;
        // 여기서 포인터, 레퍼런스 중 뭐가 낫나?
        // 그리고 기본생성자가 있는데 레퍼런스가 가능하기는 한가?

        OfficeBlock(const OfficeBlock& ref);
        OfficeBlock& operator = (const OfficeBlock& ref);
    
    public:
        OfficeBlock();
        OfficeBlock(Intern& intern, Bureaucrat& signer, Bureaucrat& executor);
        ~OfficeBlock();

        void setIntern(Intern& intern);
        void setSigner(Bureaucrat& signer);
        void setExecutor(Bureaucrat& executor);

        void doBureaucracy(std::string form_name, std::string target);

        class WorkerError : std::exception
        {
            private:
                std::string msg_;

            public:
                WorkerError(std::string msg);
                WorkerError(const WorkerError& ref);
                WorkerError& operator = (const WorkerError& ref);
                virtual ~WorkerError();
                
                virtual const char* what() const throw();
        };
};

#endif