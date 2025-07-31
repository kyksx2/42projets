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

Animal::Animal() {
  std::cout << "Animal constructor called" << std::endl;
  this->type = "Animal";
}

Animal::Animal(Animal const &src) {
  std::cout << "Animal constructor copy called" << std::endl;
  *this = src;
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal &Animal::operator=(Animal const &src) {
  std::cout << "Animal Copy assignement operator called" << std::endl;
  if (this != &src)
    this->type = src.getType();
  return (*this);
}

void Animal::makeSound() const {
  std::cout << "*sound of random animal*" << std::endl;
}

std::string Animal::getType() const { return (this->type); }
