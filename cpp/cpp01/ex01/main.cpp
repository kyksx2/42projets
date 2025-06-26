/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:42:09 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/23 16:17:03 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <stdlib.h>

int main(int ac, char **av) {
    (void)ac;
    Zombie *zombie = zombieHorde(atoi(av[1]), av[2]);
    delete []zombie;
    return (0);
}