/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <string>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"


class Bureaucrat
{
	public:
		class GradeTooHighException: public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
		class GradeTooLooException: public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
		Bureaucrat(void);
		Bureaucrat(std::string const name);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);

		Bureaucrat & operator=(Bureaucrat const &src);

		std::string getName(void) const;
		int			getGrade(void) const;
		void 		increaseGrade(void);
		void 		decreaseGrade(void);

		void		signForm(AForm& f);
		void		executeForm(AForm const & form);

	private:
		std::string const	_name;
		int					_grade;

};

std::ostream & operator<<(std::ostream &o, Bureaucrat const &c);

#endif