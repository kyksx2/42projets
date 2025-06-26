/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:23:29 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/24 19:01:00 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string str) : name(str), weapon(NULL) { return; }

HumanB::~HumanB() { return; }

void HumanB::setWeapon(Weapon *weapon) {
    this->weapon = weapon;
}

void HumanB::attacks() {
    if (weapon)
        std::cout << name << " attaque avec un " << weapon->getType() << "\n";
    else
        std::cout << name << " a les mains vides\n";
}
