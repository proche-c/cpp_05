/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP
#include <fstream>
#include "AForm.hpp"
#define TREE  "        @\n       @@@\n      @@@@@\n     @@@@@@@\n    @@@@@@@@@\n   @@@@@@@@@@@\n  @@@@@@@@@@@@@\n       |||\n       |||\n       |||\n"

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm & operator=(ShrubberyCreationForm const &src);

		std::string		getTarget(void) const;

		virtual void	executing(Bureaucrat const & executor) const;

		static AForm	*makeForm(AForm *form, std::string const &type, std::string const &target);

	private:
		std::string	_target;

};

std::ostream & operator<<(std::ostream &o, ShrubberyCreationForm const &c);

#endif