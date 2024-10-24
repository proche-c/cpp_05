/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
{
	public:
		class GradeTooHighException: public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
		class FormNotSignedException: public std::exception
		{
			public:
			virtual const char* what() const throw();			
		};
		AForm(void);
		AForm(std::string const name);
		AForm(std::string const name, int gradeToSign, int gradeToExec);
		AForm(AForm const &src);
		~AForm(void);

		AForm & operator=(AForm const &src);

		std::string getName(void) const; 
		int			getGradeToSign(void) const;
		int			getGradeToExec(void) const;
		bool		getIsSigned(void) const;

		void		beSigned(Bureaucrat &b);
		void		execute(Bureaucrat const & executor) const;
		virtual void	executing(Bureaucrat const & executor) const = 0;

	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_gradeToSign;
		int const			_gradeToExec;

};

std::ostream & operator<<(std::ostream &o, AForm const &c);

#endif