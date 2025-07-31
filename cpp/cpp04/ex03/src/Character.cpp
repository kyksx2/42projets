/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:21:19 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/28 15:47:36 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Character.hpp"
#include "../include/Materia.hpp"

Character::Character() : name("default") {
  for (int i = 0; i < 4; i++) {
    materia[i] = NULL;
  }
  for (int i = 0; i < 1000; i++) {
    dropped[i] = NULL;
  }
}

Character::Character(std::string const &name) : name(name) {
  for (int i = 0; i < 4; i++) {
    materia[i] = NULL;
  }
  for (int i = 0; i < 1000; i++) {
    dropped[i] = NULL;
  }
}

Character::Character(Character const &src) {
  for (int i = 0; i < 4; i++) {
    materia[i] = NULL;
  }
  for (int i = 0; i < 1000; i++) {
    dropped[i] = NULL;
  }
  *this = src;
}

Character &Character::operator=(Character const &src) {
  if (this != &src) {
    name = src.name;
    for (int i = 0; i < 4; i++) {
      if (materia[i])
        delete materia[i];
      materia[i] = NULL;
    }
    for (int i = 0; i < 4; i++) {
      if (src.materia[i])
        materia[i] = src.materia[i]->clone();
    }
    for (int i = 0; i < 1000; i++) {
      delete dropped[i];
      dropped[i] = NULL;
    }
  }
  return *this;
}

Character::~Character() {
  for (int i = 0; i < 4; i++) {
    if (materia[i])
      delete materia[i];
  }
  for (int i = 0; i < 1000; i++) {
    if (dropped[i])
      delete dropped[i];
  }
}

std::string const &Character::getName() const { return name; }

void Character::equip(AMateria *m) {
  if (!m)
    return;
  for (int i = 0; i < 4; i++) {
    if (!materia[i]) {
      materia[i] = m;
      return ;
    }
  }
  delete m;
}

void Character::unequip(int idx) {
  if (idx < 0 || idx >= 4 || !materia[idx])
    return;
  if (materia[idx]) {
    for (int i = 0; i < 1000; i++) {
      if (!dropped[i]) {
        dropped[i] = materia[idx];
        materia[idx] = NULL;
        return;
      }
    }
    std::cerr << "Error: dropped materia inventory full, cannot unequip. "
                 "Potential memory leak."
              << std::endl;
  }
}

void Character::use(int idx, ICharacter &target) {
  if (idx < 0 || idx >= 4 || !materia[idx])
    return;
  this->materia[idx]->use(target);
}