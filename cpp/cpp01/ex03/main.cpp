/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:21:37 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/24 19:02:00 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {
  {
    Weapon club("ak47");
    HumanA bob("Booba", club);
    bob.attacks();
    club.setType("glock 17");
    bob.attacks();
  }
  {
    Weapon club("m16");
    HumanB jim("Jimmy");
    jim.setWeapon(NULL);
    jim.attacks();
    jim.setWeapon(&club);
    club.setType(" fusil cannon scier");
    jim.attacks();
  }
  return 0;
}