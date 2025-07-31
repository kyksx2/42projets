/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:21:30 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/11 17:09:18 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Materia.hpp"

AMateria::AMateria() : type("default materia") {}

AMateria::AMateria(AMateria const &src) { *this = src; }

AMateria::AMateria(std::string const &type) { this->type = type; }

AMateria::~AMateria() {}

AMateria &AMateria::operator=(AMateria const &src) {
  if (this != &src) {
    this->type = src.type;
  }
  return (*this);
}

void AMateria::use(ICharacter &target) {
  std::cout << "default: " << target.getName() << std::endl;
}


std::string const &AMateria::getType() const { return (this->type); }

