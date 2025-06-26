/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:43:58 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/23 16:19:28 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void    Zombie::setName(std::string name) {
    this->name = name;
}

Zombie *zombieHorde(int n, std::string name) {
    Zombie *zombie = new Zombie[n];
    for (int i = 0; i < n; i++) {
        zombie[i].setName(name);
        zombie[i].announce();
    }
    return (zombie);
}
