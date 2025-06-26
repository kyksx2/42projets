/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:21:59 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/24 16:53:02 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>

class Weapon {
public:
  Weapon(std::string type);
  ~Weapon();
  const std::string &getType() const;
  void setType(const std::string &newType);

private:
  std::string type;
};

#endif