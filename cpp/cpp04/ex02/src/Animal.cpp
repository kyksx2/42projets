/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 00:04:11 by marvin            #+#    #+#             */
/*   Updated: 2025/07/04 00:04:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

aAnimal::aAnimal() {
  std::cout << "Animal constructor called" << std::endl;
  this->type = "Animal";
}

aAnimal::aAnimal(aAnimal const &src) {
  std::cout << "Animal constructor copy called" << std::endl;
  *this = src;
}

aAnimal::~aAnimal() { std::cout << "Animal destructor called" << std::endl; }

aAnimal &aAnimal::operator=(aAnimal const &src) {
  std::cout << "Animal Copy assignement operator called" << std::endl;
  if (this != &src)
    this->type = src.getType();
  return (*this);
}

void aAnimal::makeSound() const {
  std::cout << "*sound of random animal*" << std::endl;
}

std::string aAnimal::getType() const { return (this->type); }
