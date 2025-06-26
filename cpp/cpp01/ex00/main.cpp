/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:09:14 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/23 13:57:38 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie* zombie1 = newZombie("stavo");
    zombie1->announce();
    Zombie* zombie2 = newZombie("oldpee");
    zombie2->announce();
    Zombie* zombie3 = newZombie("zefor");
    zombie3->announce();
    randomChump("zed");
    delete zombie1;
    delete zombie2;
    delete zombie3;
    return (0);
}