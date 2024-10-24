/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void):AForm::AForm("ShrubberyCreationForm", 145, 137), _target("null")
{
	std::cout << "Default ShrubberyCreationForm constructor called for " << this->getTarget() << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Default ShrubberyCreationForm constructor called for " << this->getTarget() << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src):AForm(src), _target(src._target) 
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
	*this = src;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout <<"ShrubberyCreationForm Destructor called for " << this->getTarget() << std::endl;
	return ;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		AForm::operator=(src);
		this->_target = src.getTarget();
	}
	return *this;
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

void	ShrubberyCreationForm::executing(Bureaucrat const & executor) const
{
	(void)executor;
	std::cout << "executing ShrubberyCreationForm..." << std::endl;
	std::string	fileName = this->getTarget() + "_shrubbery";
	std::ofstream	ofs(fileName.c_str());
	ofs << TREE;
	if (ofs.fail())
	{
		std::cout << "Error creating Tree File " << fileName << std::endl;
		return;
	}	
	ofs.close();
}

AForm	*ShrubberyCreationForm::makeForm(AForm *form, std::string const &type, std::string const &target)
{
	if (form == NULL && type == "shrubbery creation")
		return (new ShrubberyCreationForm(target));
	return(form);
}

std::ostream & operator<<(std::ostream &o, ShrubberyCreationForm const &c)
{
	if (c.getIsSigned() == 0)
		o << c.getName() << ", ShrubberyCreationForm, target: " << c.getTarget() << ", is NOT signed." << std::endl;
	else
		o << c.getName() << ", ShrubberyCreationForm, target: " << c.getTarget() << ", is signed." << std::endl;
	return o;
}
