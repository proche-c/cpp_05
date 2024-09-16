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
	Bureaucrat	b1("Annoying", 1);
	std::cout << b1;
	std::cout << "****************************" << std::endl;
	Bureaucrat	b2("Alpha", 0);
	std::cout << b2;
	std::cout << "****************************" << std::endl;
	Bureaucrat	b3("Epsilon", 151);
	std::cout << b3;
	std::cout << "****************************" << std::endl;
	Bureaucrat	b4("Looser", 150);
	std::cout << b4;
	std::cout << "****************************" << std::endl;
	b1.increaseGrade();
	std::cout << b1;
	std::cout << "****************************" << std::endl;
	b1.decreaseGrade();
	std::cout << b1;
	std::cout << "****************************" << std::endl;
	Bureaucrat	b5;
	b5 = b4;
	std::cout << b5;

  return 0;
}