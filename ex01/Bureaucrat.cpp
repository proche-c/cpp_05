/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/25 12:11:31 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called for " << this->getName() << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout <<"Destructor called for " << this->getName() << std::endl;
	return ;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_name = src.getName();
		this->_hitPoints = src.getHitPoints();
		this->_energyPoints = src.getEnergyPoints();
		this->_attackDamage = src.getAttackDamage();
	}
	return *this;
}

std::string	ClapTrap::getName(void) const
{
	return this->_name;
}

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
	return ;
}

int	ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

void	ClapTrap::setHitPoints(int hitPoints)
{
	this->_hitPoints = hitPoints;
	return ;
}

int	ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

void	ClapTrap::setEnergyPoints(int energyPoints)
{
	this->_energyPoints = energyPoints;
	return ;
}

int	ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}

void	ClapTrap::setAttackDamage(int attackDamage)
{
	this->_attackDamage = attackDamage;
	return ;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		std:: cout << this->getName() << " attacks " << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else
	{
		std::cout << this->getName() << " can't attack because he has " << this->getHitPoints() << " and " << this->getEnergyPoints() << " energy points." << std::endl;
	}
	return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints = this->_hitPoints - amount;
	return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0)
	{
		this->_energyPoints--;
		this->_hitPoints = this->_hitPoints + amount;
	}
	else
	{
		std::cout << this->getName() << " can't be repaired because he has " << this->getEnergyPoints() << " energy points." << std::endl;
	}
	return ;
}

std::ostream & operator<<(std::ostream &o, ClapTrap const &c)
{
	o << c.getName() << " has " << c.getHitPoints() << " hit points, " << c.getEnergyPoints() << " energy points and " << c.getAttackDamage() << " attack damage." << std::endl;
	return o;
}
