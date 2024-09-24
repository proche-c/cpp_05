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

int main( void )
{
	std::cout << "***********SHRUBBERY_CREATION_FORM**********" << std::endl;
	Bureaucrat	b1("Annoying", 2);
	Bureaucrat	b2("Looser", 149);
	ShrubberyCreationForm	s1("home");
	std::cout << s1;
	b2.signForm(s1);
	b1.signForm(s1);
	std::cout << s1;
	s1.beSigned(b1);
	std::cout << s1;
	b2.executeForm(s1);
	b1.executeForm(s1);
	s1.execute(b1);
	std::cout << "**********ROBOTOMY_REQUEST_FORM*********" << std::endl;
	RobotomyRequestForm r1("paco");
	RobotomyRequestForm r2("pepe");
	RobotomyRequestForm r3("manolo");
	b1.executeForm(r1);
	b1.signForm(r1);
	b1.signForm(r2);
	b1.signForm(r3);
	r1.beSigned(b1);
	r2.beSigned(b1);
	r3.beSigned(b1);
	b1.executeForm(r1);
	b1.executeForm(r2);
	b1.executeForm(r3);
	r1.execute(b1);
	r2.execute(b1);
	r3.execute(b1);
	std::cout << "**********PRESIDENTIAL_PARDON_FORM*********" << std::endl;
	PresidentialPardonForm p1("Hannibal Leckter");
	b1.signForm(p1);
	p1.beSigned(b1);
	b1.executeForm(p1);
	p1.execute(b1);
  return 0;
}