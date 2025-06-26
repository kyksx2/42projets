/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:23:45 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/24 18:54:56 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H
#include "Weapon.hpp"
#include <iostream>

class HumanB {
public:
  HumanB(std::string name);
  ~HumanB();
  void attacks(void);
  void setWeapon(Weapon *weapon);

private:
  std::string name;
  Weapon *weapon;
};

#endif