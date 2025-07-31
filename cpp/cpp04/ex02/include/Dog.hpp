/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:56:05 by marvin            #+#    #+#             */
/*   Updated: 2025/07/03 23:56:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public aAnimal {
public:
  Dog();
  Dog(Dog const &src);
  ~Dog();

  Dog &operator=(Dog const &src);
  
  void makeSound() const;

  void setIdea(int index, std::string idea);
  std::string getIdea(int index) const;

private:
  Brain *brain;
};

#endif