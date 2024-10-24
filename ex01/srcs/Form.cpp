/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return "error: Form: grade too high.\n";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "error: Form: grade too low.\n";
}

Form::Form(void):_name("Default"), _isSigned(0), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "Default constructor called for " << this->getName() << std::endl;
	return ;
}

Form::Form(std::string const name):_name(name), _isSigned(0), _gradeToSign(1), _gradeToExec(1)
{
	std::cout << "Default constructor called for " << this->getName() << std::endl;
	return ;
}

Form::Form(std::string const name, int gradeToSign, int gradeToExec):_name(name), _isSigned(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	try
	{
		if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
			throw Form::GradeTooHighException();
		else if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
			throw Form::GradeTooLowException();
		std::cout << "Default constructor called for " << this->getName() << std::endl;
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cout << this->getName() << ": " << e.what();
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << this->getName() << ": " << e.what();
	}
	return ;
}

Form::Form(Form const &src):_name(src.getName()), _isSigned(src.getIsSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec())
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Form::~Form(void)
{
	std::cout <<"Destructor called for " << this->getName() << std::endl;
	return ;
}

Form & Form::operator=(Form const &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_isSigned = src.getIsSigned();
	}
	return *this;
}

std::string Form::getName(void) const
{
	return this->_name;
}

int	Form::getGradeToSign(void) const
{
	return this->_gradeToSign;
}

int	Form::getGradeToExec(void) const
{
	return this->_gradeToExec;
}

bool	Form::getIsSigned(void) const
{
	return this->_isSigned;
}

void	Form::beSigned(Bureaucrat &b)
{

	if (b.getGrade() > this->getGradeToSign())
	{
		throw Form::GradeTooLowException();
	}
	this->_isSigned = 1;
	
}

std::ostream & operator<<(std::ostream &o, Form const &c)
{
	if (c.getIsSigned() == 0)
		o << c.getName() << ", Form grade to signed: " << c.getGradeToSign() << ", grade to execute: " << c.getGradeToExec() << ", is NOT signed." << std::endl;
	else
		o << c.getName() << ", Form grade to signed: " << c.getGradeToSign() << ", grade to execute: " << c.getGradeToExec() << ", is signed." << std::endl;
	return o;
}
