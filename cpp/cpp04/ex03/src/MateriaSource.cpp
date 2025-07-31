/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 13:22:00 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/28 15:53:42 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++)
    materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &src) {
  for (int i = 0; i < 4; i++)
    materia[i] = NULL;
  *this = src;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src) {
  if (this != &src) {
    for (int i = 0; i < 4; i++) {
      if (materia[i])
        delete materia[i];
      materia[i] = NULL;
    }
    for (int i = 0; i < 4; i++) {
      if (src.materia[i])
        materia[i] = src.materia[i]->clone();
    }
  }
  return *this;
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++) {
    if (materia[i])
      delete materia[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  for (int i = 0; i < 4; i++) {
    if (!materia[i]) {
      materia[i] = m->clone();
      delete m;
      return;
    }
  }
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < 4; i++) {
    if (materia[i] && materia[i]->getType() == type )
      return (materia[i]->clone());
  }
  return (NULL);
}
