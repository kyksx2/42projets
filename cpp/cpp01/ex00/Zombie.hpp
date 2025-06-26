/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:10:00 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/23 13:57:23 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#include <form.h>

class Zombie {
public:
  Zombie(std::string name);
  ~Zombie();
  void announce(void);

private:
  std::string name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif