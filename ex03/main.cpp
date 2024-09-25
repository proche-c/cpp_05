/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main( void )
{
	Intern 	nerd;
	Bureaucrat	b("Boss", 3);
	AForm	*form;

	form = nerd.makeForm("shrubbery creation", "park");
	std::cout << *form;
	b.signForm(*form);
	std::cout << *form;
	b.executeForm(*form);
	delete form;

	AForm	*f_rr;
	f_rr = nerd.makeForm("robotomy request", "lucas");
	std::cout << *f_rr;
	delete f_rr;

	AForm	*f_pp;
	f_pp = nerd.makeForm("presidential pardon", "Cercei");
	std::cout << *f_pp;
	delete f_pp;

	AForm	*f_other = NULL;
	f_other = nerd.makeForm("other", "nobody");
	delete f_other;
  return 0;
}