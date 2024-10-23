/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "error: Bureaucrat: grade too high.\n";
}

const char* Bureaucrat::GradeTooLooException::what() const throw()
{
	return "error: Bureaucrat: grade too low.\n";
}

Bureaucrat::Bureaucrat(void):_name("Default"),_grade(150)
{
	std::cout << "Default constructor called for " << this->getName() << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string const name):_name(name),_grade(150)
{
	std::cout << "Default constructor called for " << this->getName() << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string const name, int grade):_name(name),_grade(grade)
{
	try
	{
		if (this->_grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (this->_grade > 150)
			throw Bureaucrat::GradeTooLooException();
		std::cout << "Default constructor called for " << this->getName() << std::endl;
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cout << this->getName() << ": " << e.what();
	}
	catch(const Bureaucrat::GradeTooLooException& e)
	{
		std::cout << this->getName() << ": " << e.what();
	}
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src):_name(src.getName())
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout <<"Destructor called for " << this->getName() << std::endl;
	return ;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_grade = src.getGrade();
	}
	return *this;
}

std::string Bureaucrat::getName(void) const
{
	return this->_name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void Bureaucrat::increaseGrade(void)
{
	if (this->_grade > 0 && this->_grade < 151)
	{
		try
		{
			if (this->_grade == 1)  
				throw Bureaucrat::GradeTooHighException();
			else
				this->_grade--;
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cout << this->getName() << ": " << e.what();
		}
	}
}

void Bureaucrat::decreaseGrade(void)
{
	if (this->_grade > 0 && this->_grade < 151)
	{
		try
		{
			if (this->_grade == 150)
				throw Bureaucrat::GradeTooLooException();
			else
				this->_grade++;
		}
		catch (Bureaucrat::GradeTooLooException& e)
		{
			std::cout << this->getName() << ": " << e.what();
		}
	}
}

void		Bureaucrat::signForm(AForm &f)
{
	if (this->_grade > 0 && this->_grade < 151)
	{
		try
		{
			f.beSigned(*this);
			std::cout << this->getName() << " signed " << f.getName() << std::endl;
		}
		catch(const AForm::GradeTooLowException& e)
		{
			std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what();
		}
	}
}

void		Bureaucrat::executeForm(AForm const & form)
{
	if (this->_grade > 0 && this->_grade < 151)
	{
		try
		{
			form.execute(*this);
			std::cout << this->getName() << " executed " << form.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what();
		}
	}	
}

std::ostream & operator<<(std::ostream &o, Bureaucrat const &c)
{
	o << c.getName() << ", bureaucrat grade " << c.getGrade() << std::endl;
	return o;
}
