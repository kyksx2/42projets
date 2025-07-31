/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:20:58 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/28 11:47:10 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Materia.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(std::string &type) : AMateria(type) {}

Cure::Cure(Cure const &src) : AMateria("cure") { *this = src; }

Cure::~Cure() {}

Cure *Cure::clone() const { return (new Cure); }

void Cure::use(ICharacter &target) {
  std::cout << "Cure: '* heals " << target.getName() << "'s wounds *'"
            << std::endl;
}