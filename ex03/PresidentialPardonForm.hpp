/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		~PresidentialPardonForm(void);

		PresidentialPardonForm & operator=(PresidentialPardonForm const &src);

		std::string	getTarget(void) const;

		virtual void	executing(Bureaucrat const & executor) const;

		static AForm	*makeForm(AForm *form, std::string const &type, std::string const &target);

	private:
		std::string	_target;

};

std::ostream & operator<<(std::ostream &o, PresidentialPardonForm const &c);

#endif