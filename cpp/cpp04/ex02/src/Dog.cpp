/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 00:05:01 by marvin            #+#    #+#             */
/*   Updated: 2025/07/04 00:05:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : aAnimal(), brain(new Brain()) {
  std::cout << "Dog constructor called" << std::endl;
  type = "Dog";
}

Dog::Dog(Dog const &src) : aAnimal(), brain(new Brain()) {
  std::cout << "Dog copy constructor called" << std::endl;
  *this = src;
}

Dog &Dog::operator=(Dog const &src) {
  std::cout << "Dog Copy assignement operator called" << std::endl;
  if (this != &src) {
    this->type = src.getType();
    if (this->brain)
      delete this->brain;
    this->brain = new Brain(*src.brain);
  }
  return (*this);
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
  delete brain;
}

void Dog::setIdea(int index, std::string idea) { brain->setIdea(index, idea); }

std::string Dog::getIdea(int index) const { return brain->getIdea(index); }

void Dog::makeSound() const { std::cout << "WOUF" << std::endl; }
