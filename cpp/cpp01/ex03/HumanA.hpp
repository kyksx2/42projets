/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:23:38 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/24 17:27:07 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H
#include "Weapon.hpp"
#include <iostream>

class HumanA {
public:
  HumanA(std::string name, Weapon &weapon);
  ~HumanA();
  void attacks(void);

private:
  std::string name;
  Weapon &weapon;
};

#endif