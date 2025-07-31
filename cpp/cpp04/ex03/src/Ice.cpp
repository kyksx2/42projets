/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:21:06 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/28 11:47:17 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Materia.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(std::string &type) : AMateria(type) {}

Ice::Ice(Ice const &src) : AMateria("ice") { *this = src; }

Ice::~Ice() {}

Ice *Ice::clone() const { return (new Ice()); }

void Ice::use(ICharacter &target) {
  std::cout << "Ice: '* shoots an ice bolt at " << target.getName() << "*'"
            << std::endl;
}