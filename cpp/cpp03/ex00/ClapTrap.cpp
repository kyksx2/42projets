/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:42:19 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/01 18:52:47 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
    : name(name), hit(10), energy(10), attack_damage(0) {
  std::cout << "ClapTrap construction\n";
}

ClapTrap::~ClapTrap() { std::cout << "ClapTrap is destroy\n"; }

void ClapTrap::attack(const std::string &target) {
  if (energy == 0) {
    std::cout << "you can't attack, you have no energy\n";
    return;
  }
  else if (hit == 0) {
    std::cout << "you can't attack, you have no hit\n";
    return;
  }
  else {
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
              << attack_damage << " points of damage !\n";
  }
  energy--;
  std::cout << "energy after attack " << energy << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (hit == 0) {
    std::cout << "ClapTrap " << name << "have no hit point\n";
    return;
  }
  std::cout << "ClapTrap " << name << " take " << amount
            << " point of damage\n";
  if (amount > static_cast<unsigned int>(hit))
    hit = 0;
  else
    hit -= amount;
  std::cout << "hit after damage " << hit << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (energy == 0) {
    std::cout << "you can't repaired, you have no energy\n";
    return;
  } else {
    std::cout << "ClapTrap " << name << " repaired " << amount
              << " hit point\n";
  }
  hit += amount;
  energy--;
  std::cout << "energy after repaired " << energy << std::endl;
  std::cout << "hit after repaired " << hit << std::endl;
}
