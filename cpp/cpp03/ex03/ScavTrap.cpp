/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:36:43 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/03 10:44:21 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "ScavTrap constructor called\n";
  this->hit = 100;
  this->energy = 2;
  this->attack_damage = 20;
}

ScavTrap::~ScavTrap() { std::cout << "ScavTrap is destroy\n"; }

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  if (energy == 0) {
    std::cout << "you can't attack, you have no energy\n";
    return;
  }
  else if (hit == 0) {
    std::cout << "you can't attack, you have no hit\n";
    return;
  }
  else {
    std::cout << "ScavTrap " << name << " attacks " << target << ", causing "
              << attack_damage << " points of damage !\n";
  }
  energy--;
  std::cout << "energy after attack " << energy << std::endl;
}
