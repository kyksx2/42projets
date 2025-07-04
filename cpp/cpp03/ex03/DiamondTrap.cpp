/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:54:33 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/03 10:43:17 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name),
      name(name) {
  std::cout << "DiamondTrap constructor called" << std::endl;
  hit = FragTrap::hit;
  energy = ScavTrap::energy;
  attack_damage = FragTrap::attack_damage;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap is destroy" << std::endl;
}

void DiamondTrap::whoAmI(void) {
  std::cout << "claptrap name: " << ClapTrap::name << " "
            << "\ndiamondtrap name: " << name << std::endl;
}
