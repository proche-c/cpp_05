/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Default Intern constructor called" << std::endl;
	return ;
}

Intern::Intern(Intern const &src)
{
	std::cout << "Intern Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Intern::~Intern(void)
{
	std::cout <<"Intern Destructor called" << std::endl;
	return ;
}

Intern & Intern::operator=(Intern const &src)
{
	(void)src;
	std::cout << "Intern Copy assignment operator called" << std::endl;
	return *this;
}

AForm	*Intern::makeForm(std::string const &type, std::string const &target)
{
	AForm	*form;
	form = AForm::makeForm(type, target);
	try
	{
		if (!form)
			throw AForm::InvalidFormTypeException();
		std::cout << "Intern creates " << form->getName() << " with target " << form->getTarget() << std::endl;
	}
	catch(const AForm::InvalidFormTypeException& e)
	{
		std::cout << e.what();
	}
	return form;
}

std::ostream & operator<<(std::ostream &o, Intern const &c)
{
	(void)c;
	o << "An Intern" << std::endl;
	return o;
}
