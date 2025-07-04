/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:42:27 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/02 11:14:24 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(){
    ClapTrap claptrap("solid snake");

    claptrap.attack("mario");
    claptrap.takeDamage(11);
    claptrap.beRepaired(5);
    return 0;
}