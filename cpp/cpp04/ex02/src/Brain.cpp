/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:19:47 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/28 11:11:51 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain const &src) {
    std::cout << "Brain copy constructeur called" << std::endl;
    if (this != &src)
        *this = src;
}

Brain &Brain::operator=(Brain const &src) {
    std::cout << "Animal Copy assignement operator called" << std::endl;
    for(int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
    return *this;
}

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

void Brain::setIdea(int index, std::string idea) {
  if (index >= 0 && index < 100)
    this->ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
  if (index >= 0 && index < 100)
    return ideas[index];
  return "";
}
