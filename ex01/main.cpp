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

int main( void )
{
	Form	f0("Invalid", 0, 7);
	std::cout << "****************************" << std::endl;
	Bureaucrat	b1("Annoying", 1);
	std::cout << b1;
	Form	f1("form_1", 2, 2);
	std::cout << f1;
	b1.signForm(f1);
	std::cout << f1;
	f1.beSigned(b1);
	std::cout << f1;
	std::cout << "****************************" << std::endl;
	Bureaucrat	b2("Looser", 145);
	std::cout << b2;
	Form	f2("form_2", 2, 2);
	std::cout << f2;
	b2.signForm(f2);
	std::cout << f2;
	f2.beSigned(b2);
	std::cout << f2;
	// std::cout << "****************************" << std::endl;
	// Bureaucrat	b3("Epsilon", 151);
	// std::cout << b3;
	// std::cout << "****************************" << std::endl;
	// Bureaucrat	b4("Looser", 150);
	// std::cout << b4;
	// std::cout << "****************************" << std::endl;
	// b1.increaseGrade();
	// std::cout << b1;
	// std::cout << "****************************" << std::endl;
	// b1.decreaseGrade();
	// std::cout << b1;
	// std::cout << "****************************" << std::endl;
	// Bureaucrat	b5;
	// b5 = b4;
	// std::cout << b5;

  return 0;
}