/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return "error: AForm: grade too high.\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "error: AForm: grade too low.\n";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "error: AForm: form not signed.\n";
}

AForm::AForm(void):_name("Default"), _isSigned(0), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "Default AForm constructor called for " << this->getName() << std::endl;
	return ;
}

AForm::AForm(std::string const name):_name(name), _isSigned(0), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "Default AForm constructor called for " << this->getName() << std::endl;
	return ;
}

AForm::AForm(std::string const name, int gradeToSign, int gradeToExec):_name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	try
	{
		if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
			throw AForm::GradeTooHighException();
		else if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
			throw AForm::GradeTooLowException();
		std::cout << "Default AForm constructor called for " << this->getName() << std::endl;
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cout << this->getName() << ": " << e.what();
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cout << this->getName() << ": " << e.what();
	}
	return ;
}

AForm::AForm(AForm const &src):_name(src.getName()), _isSigned(src.getIsSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec())
{
	std::cout << "AForm Copy constructor called" << std::endl;
	*this = src;
	return ;
}

AForm::~AForm(void)
{
	std::cout <<"AForm Destructor called for " << this->getName() << std::endl;
	return ;
}

AForm & AForm::operator=(AForm const &src)
{
	std::cout << "AForm Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_isSigned = src.getIsSigned();
	}
	return *this;
}

std::string AForm::getName(void) const
{
	return this->_name;
}

int	AForm::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int	AForm::getGradeToExec(void) const
{
	return this->_gradeToExec;
}

bool	AForm::getIsSigned(void) const
{
	return this->_isSigned;
}

void	AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > this->getGradeToSign())
	{
		throw AForm::GradeTooLowException();
	}
	this->_isSigned = 1;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExec())
		throw AForm::GradeTooLowException();
	this->executing(executor);
}

std::ostream & operator<<(std::ostream &o, AForm const &c)
{
	if (c.getIsSigned() == 0)
		o << c.getName() << ", AForm grade to signed: " << c.getGradeToSign() << ", grade to execute: " << c.getGradeToExec() << ", is NOT signed." << std::endl;
	else
		o << c.getName() << ", AForm grade to signed: " << c.getGradeToSign() << ", grade to execute: " << c.getGradeToExec() << ", is signed." << std::endl;
	return o;
}
