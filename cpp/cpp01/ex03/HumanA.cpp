/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:23:41 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/24 19:00:33 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &weapon): name(str), weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attacks() {
    std::cout << name << " attaque avec un " << weapon.getType() << "\n";
}
