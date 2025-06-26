/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:22:15 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/24 17:14:20 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str) {
    this->type = str;
}

Weapon::~Weapon() {}

const std::string &Weapon::getType() const { return type; }

void    Weapon::setType(const std::string &newType) {
    this->type = newType;
}
