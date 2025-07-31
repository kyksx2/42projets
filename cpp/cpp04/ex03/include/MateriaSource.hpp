/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:31:58 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/11 16:09:43 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H
#include "Materia.hpp"
#include <iostream>

class IMateriaSource {
public:
  virtual ~IMateriaSource() {}
  virtual void learnMateria(AMateria *) = 0;
  virtual AMateria *createMateria(std::string const &type) = 0;
};

class MateriaSource : public IMateriaSource {
public:
  MateriaSource();
  MateriaSource(MateriaSource const &src);
  virtual ~MateriaSource();

  MateriaSource &operator=(MateriaSource const &src);

  void learnMateria(AMateria *m);
  AMateria *createMateria(std::string const &type);

private:
  AMateria *materia[4];
};

#endif