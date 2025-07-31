/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:07:43 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/28 11:11:01 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H
#include <iostream>

class Brain {
public:
  Brain();
  Brain(Brain const &src);
  ~Brain();

  Brain &operator=(Brain const &src);

  void  setIdea(int index, std::string idea);
  std::string getIdea(int index) const;
  
private:
  std::string ideas[100];
};

#endif