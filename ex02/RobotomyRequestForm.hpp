/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP
#include "AForm.hpp"
#include <random>

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		~RobotomyRequestForm(void);

		RobotomyRequestForm & operator=(RobotomyRequestForm const &src);

		std::string	getTarget(void) const;

		virtual void	executing(Bureaucrat const & executor) const;

	private:
		std::string	_target;

};

std::ostream & operator<<(std::ostream &o, RobotomyRequestForm const &c);

#endif