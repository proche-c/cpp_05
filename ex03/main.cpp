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

#include <iostream>
#include "ClapTrap.hpp"

int main( void )
{
  ClapTrap  robot("Terminator");
  ClapTrap  hero("Sarah Connor");

  std::cout << robot;
  std::cout << hero;

  robot.setAttackDamage(4);
  hero.setAttackDamage(5);
  robot.attack("Sarah Connor");
  hero.takeDamage(4);
  hero.attack("Terminator");
  robot.takeDamage(5);

  std::cout << robot;
  std::cout << hero;

  hero.beRepaired(2);
  hero.attack("Terminator");
  robot.takeDamage(5);
  robot.attack("Sarah Connor");

  std::cout << robot;
  std::cout << hero;

  return 0;
}