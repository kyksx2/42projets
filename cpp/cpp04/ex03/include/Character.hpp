/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:33:31 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/28 12:26:24 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_H
#define ICHARACTER_H
#include <iostream>

//? l'interface est une maniere de deffinir un comportement
//? ca permet de donner des indications sur comment implementer une classe concrete

class AMateria;

class ICharacter {
public:
  virtual ~ICharacter() {}
  virtual std::string const &getName() const = 0;
  virtual void equip(AMateria *m) = 0;
  virtual void unequip(int idx) = 0;
  virtual void use(int idx, ICharacter &target) = 0;
};

class Character : public ICharacter {
public:
  Character();
  Character(std::string const &name);
  Character(Character const &src);
  virtual ~Character();

  Character &operator=(Character const &src);

  std::string const &getName() const;
  void equip(AMateria *m);
  void unequip(int idx);
  void use(int idx, ICharacter &target);

private:
  std::string name;
  AMateria *materia[4];
  AMateria *dropped[1000];
};

#endif