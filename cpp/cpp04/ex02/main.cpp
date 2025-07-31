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

// int main() {
// std::cout << "--------constructeur--------" << std::endl;
// const aAnimal* j = new Dog();
// const aAnimal* i = new Cat();
// std::cout << "--------type--------" << std::endl;
// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
// std::cout << "--------sound--------" << std::endl;
// i->makeSound();
// j->makeSound();
// std::cout << "--------destructor--------" << std::endl;
// delete i;
// delete j;
// }

int main() {
  Dog dog_one;

  dog_one.setIdea(0, "abboyer");
  dog_one.setIdea(1, "chasser");
  dog_one.setIdea(2, "lire moliere");

  Dog copy_dog = dog_one;

  std::cout << dog_one.getIdea(0) << std::endl;
  std::cout << copy_dog.getIdea(0) << std::endl;
  std::cout << dog_one.getIdea(1) << std::endl;
  std::cout << copy_dog.getIdea(1) << std::endl;
  std::cout << dog_one.getIdea(2) << std::endl;
  std::cout << copy_dog.getIdea(2) << std::endl;
}