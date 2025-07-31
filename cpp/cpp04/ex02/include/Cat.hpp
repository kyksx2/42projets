/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:57:06 by marvin            #+#    #+#             */
/*   Updated: 2025/07/03 23:57:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat : public aAnimal {
public:
  Cat();
  Cat(Cat const &src);
  ~Cat();

  Cat &operator=(Cat const &src);

  void makeSound() const;

  void  setIdea(int index, std::string idea);
  std::string getIdea(int index) const;

private:
  Brain *brain;
};

#endif