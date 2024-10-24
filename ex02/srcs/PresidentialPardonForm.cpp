/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):AForm::AForm("PresidentialPardonForm", 25, 5), _target("null")
{
	std::cout << "Default PresidentialPardonForm constructor called for " << this->getTarget() << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target):AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Default PresidentialPardonForm constructor called for " << this->getTarget() << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src):AForm(src), _target(src._target) 
{
	std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
	*this = src;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout <<"PresidentialPardonForm Destructor called for " << this->getTarget() << std::endl;
	return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src.getTarget();
	}
	return *this;
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

void	PresidentialPardonForm::executing(Bureaucrat const & executor) const
{
	(void)executor;
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream & operator<<(std::ostream &o, PresidentialPardonForm const &c)
{
	if (c.getIsSigned() == 0)
		o << c.getName() << ", PresidentialPardonForm, target: " << c.getTarget() << ", is NOT signed." << std::endl;
	else
		o << c.getName() << ", PresidentialPardonForm, target: " << c.getTarget() << ", is signed." << std::endl;
	return o;
}
