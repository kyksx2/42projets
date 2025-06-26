/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:44:13 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/23 16:53:49 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <form.h>
#include <iostream>

class Zombie {
public:
  Zombie();
  ~Zombie();
  void announce(void);
  void setName(std::string name);

private:
  std::string name;
};

Zombie *zombieHorde(int n, std::string name);