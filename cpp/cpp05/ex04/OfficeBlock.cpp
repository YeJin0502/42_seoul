/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoon <gmoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 23:56:09 by gmoon             #+#    #+#             */
/*   Updated: 2020/09/21 01:18:21 by gmoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock()
:   intern_(nullptr),
    signer_(nullptr),
    executor_(nullptr)
{}

OfficeBlock::OfficeBlock(Intern& intern, Bureaucrat& signer, Bureaucrat& executor)
:   intern_(&intern),
    signer_(&signer),
    executor_(&executor)
{}

OfficeBlock::OfficeBlock(const OfficeBlock& ref)
{
    (void) ref;
}

OfficeBlock&
OfficeBlock::operator = (const OfficeBlock& ref)
{
    (void) ref;
    return (*this);
}

OfficeBlock::~OfficeBlock()
{}

void
OfficeBlock::setIntern(Intern& intern)
{
    intern_ = &intern;
}

void
OfficeBlock::setSigner(Bureaucrat& signer)
{
    signer_ = &signer;
}

void
OfficeBlock::setExecutor(Bureaucrat& executor)
{
    executor_ = &executor;
}

void
OfficeBlock::doBureaucracy(std::string form_name, std::string target)
{
    // if (!intern_ || !signer_ || !executor_)
        // throw WorkerError(); // break 안해도 바로 넘어가나?

    if (!intern_)
        throw WorkerError("Error in intern.");
    else if (!signer_)
        throw WorkerError("Error in signer.");
    else if (!executor_)
        throw WorkerError("Error in executor.");

    Form* form;

    try
    {
            form = intern_->makeForm(form_name, target);
    }
    catch (std::exception & e)
    {
        throw ; // 에러를 또 함수 밖으로 던지는 것?
    }

    try
    {
        signer_->signForm(*form);
        executor_->executeForm(*form);

        delete form;
    }
    catch (std::exception & e)
    {
        delete form;

        throw ;
    }
}

OfficeBlock::WorkerError::WorkerError(std::string msg)
:   msg_(msg)
{}

OfficeBlock::WorkerError::WorkerError(const WorkerError& ref)
:   msg_(ref.msg_)
{}

OfficeBlock::WorkerError&
OfficeBlock::WorkerError::operator = (const WorkerError& ref)
{
    if (this != &ref)
    {
        msg_ = ref.msg_;
    }
    return (*this);
}

OfficeBlock::WorkerError::~WorkerError()
{}

const char*
OfficeBlock::WorkerError::what() const throw()
{
    return (msg_.c_str());
}