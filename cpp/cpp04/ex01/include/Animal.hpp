/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:51:20 by marvin            #+#    #+#             */
/*   Updated: 2025/07/03 23:51:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>

class Animal {
public:
  Animal(void);
  Animal(Animal const &src);
  virtual ~Animal();

  Animal &operator=(Animal const &src);

  virtual void makeSound() const;
  std::string getType() const;

protected:
  std::string type;
};

#endif
