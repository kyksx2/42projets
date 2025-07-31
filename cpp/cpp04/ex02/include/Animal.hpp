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

class aAnimal { //? class abstraite!!
public:
  aAnimal(void);
  aAnimal(aAnimal const &src);
  virtual ~aAnimal();

  aAnimal &operator=(aAnimal const &src);

  virtual void makeSound() const = 0; //? ceci est  "une methode pur" 
  std::string getType() const;

protected:
  std::string type;
};

//! cette classe n'est pas instanciable a cause de la methode pur
//? la methode pur force les class fille a redefinir la fonction makesound

#endif
