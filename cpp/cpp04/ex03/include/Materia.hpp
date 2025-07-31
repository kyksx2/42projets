/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:25:46 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/28 11:48:26 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIA_H
#define MATERIA_H
#include "Character.hpp"
#include <iostream>

class AMateria {
public:
  AMateria();
  AMateria(AMateria const &src);
  AMateria(std::string const &type);
  virtual ~AMateria();

  AMateria &operator=(AMateria const &src);

  std::string const &getType() const;
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);

protected:
  std::string type;
};

class Ice : public AMateria {
public:
    Ice();
    Ice(std::string &type);
    Ice(Ice const& src);
    ~Ice();

    Ice *clone() const;
    void use(ICharacter &target);    
};

class Cure : public AMateria {
public:
    Cure();
    Cure(std::string &type);
    Cure(Cure const& src);
    ~Cure();

    Cure *clone() const;
    void use(ICharacter &target);    
};

#endif