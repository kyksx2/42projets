/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:36:39 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/03 10:46:10 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap(std::string name);
  ~ScavTrap();

  void attack(const std::string &target);
  void guardGate();
};

#endif