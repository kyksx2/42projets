/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:50:39 by marvin            #+#    #+#             */
/*   Updated: 2025/07/03 23:50:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Animal.hpp"
#include "./include/Cat.hpp"
#include "./include/Dog.hpp"

int main() {
  int size = 5;
  Animal *animals[size];
  std::cout << "--------constructeur--------" << std::endl;
  for (int i = 0; i < size / 2; i++) {
    animals[i] = new Cat;
  }
  for (int i = size / 2; i < size; i++) {
    animals[i] = new Dog;
  }
  std::cout << "--------animal sound--------" << std::endl;
  for (int i = 0; i < size; i++) {
    animals[i]->makeSound();
  }
  std::cout << "--------destructeur--------" << std::endl;
  for (int i = 0; i < size; i++) {
    delete animals[i];
  }
  return 0;
}

// int main() {
//   Dog dog_one;

//   dog_one.setIdea(0, "abboyer");
//   dog_one.setIdea(1, "chasser");
//   dog_one.setIdea(2, "lire moliere");

//   Dog copy_dog = dog_one;

//   std::cout << dog_one.getIdea(0) << std::endl;
//   std::cout << copy_dog.getIdea(0) << std::endl;
//   std::cout << dog_one.getIdea(1) << std::endl;
//   std::cout << copy_dog.getIdea(1) << std::endl;
//   std::cout << dog_one.getIdea(2) << std::endl;
//   std::cout << copy_dog.getIdea(2) << std::endl;
// }