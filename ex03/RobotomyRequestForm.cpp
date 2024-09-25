/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):AForm::AForm("RobotomyRequestForm", 72, 45), _target("null")
{
	std::cout << "Default RobotomyRequestForm constructor called for " << this->getTarget() << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target):AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Default RobotomyRequestForm constructor called for " << this->getTarget() << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src):AForm(src), _target(src._target) 
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
	*this = src;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout <<"RobotomyRequestForm Destructor called for " << this->getTarget() << std::endl;
	return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &src) 
{
	std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src.getTarget();
	}
	return *this;
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

void	RobotomyRequestForm::executing(Bureaucrat const & executor) const
{
	(void)executor;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(1, 100);
	int rn = distrib(gen);
	if (rn % 2 == 1)
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->getTarget() << " robotomy failed." << std::endl;
}

AForm	*RobotomyRequestForm::makeForm(AForm *form, std::string const &type, std::string const &target)
{
	if (form == NULL && type == "robotomy request")
		return (new RobotomyRequestForm(target));
	return(form);
}

std::ostream & operator<<(std::ostream &o, RobotomyRequestForm const &c)
{
	if (c.getIsSigned() == 0)
		o << c.getName() << ", RobotomyRequestForm, target: " << c.getTarget() << ", is NOT signed." << std::endl;
	else
		o << c.getName() << ", RobotomyRequestForm, target: " << c.getTarget() << ", is signed." << std::endl;
	return o;
}
