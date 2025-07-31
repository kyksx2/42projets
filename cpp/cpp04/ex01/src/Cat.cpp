/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 00:04:40 by marvin            #+#    #+#             */
/*   Updated: 2025/07/04 00:04:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain()) {
  std::cout << "Cat constructor called" << std::endl;
  this->type = "Cat";
}

Cat::Cat(Cat const &src) : Animal(), brain(new Brain(*src.brain)) {
  std::cout << "Cat copy constructor called" << std::endl;
  this->type = src.type;
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
  delete brain;
}

Cat &Cat::operator=(Cat const &src) {
  std::cout << "Cat Copy assignement operator called" << std::endl;
  if (this != &src) {
    this->type = src.getType();
    if (this->brain)
      delete this->brain;
    this->brain = new Brain(*src.brain);
  }
  return (*this);
}

void Cat::makeSound() const { std::cout << "MIAOU" << std::endl; }

void Cat::setIdea(int index, std::string idea) { brain->setIdea(index, idea); }

std::string Cat::getIdea(int index) const { return brain->getIdea(index); }
