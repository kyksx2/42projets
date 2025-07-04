/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:15:56 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/03 10:44:16 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  std::cout << "FragTrap constructor called" << std::endl;
  this->hit = 100;
  this->energy = 100;
  this->attack_damage = 30;
}

FragTrap::~FragTrap() { std::cout << "FragTrap is destroy" << std::endl; }

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << name << " want to give a high five" << std::endl;
}
