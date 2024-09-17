/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form
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
		Form(void);
		Form(std::string const name);
		Form(std::string const name, int gradeToSign, int gradeToExec);
		Form(Form const &src);
		~Form(void);

		Form & operator=(Form const &src);

		std::string getName(void) const; 
		int			getGradeToSign(void) const;
		int			getGradeToExec(void) const;
		bool		getIsSigned(void) const;

		void		beSigned(Bureaucrat &b);

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExec;

};

std::ostream & operator<<(std::ostream &o, Form const &c);

#endif