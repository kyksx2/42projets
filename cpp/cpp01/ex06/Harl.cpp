/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 04:55:26 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/28 11:26:40 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::complain(std::string level){
  int index;
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  for (int i = 0; i < 4; i++) {
    if (level == levels[i]) {
        index = i;
      }
  }

  switch (index) {
  case 0:
    debug();
  case 1:
    info();
  case 2:
    warning();
  case 3:
    error();
  }
}

void Harl::debug() {
  std::cout << "[DEBUG] d'abord soeur friede puis apres malenia\n";
}

void Harl::info() {
  std::cout << "[INFO] dark souls 3 c'est peut etre le meilleur\n";
}

void Harl::warning() {
  std::cout << "[WARNING] par contre le 1v1 malenia c'etait du jamais vu\n";
}

void Harl::error() { std::cout << "[ERROR] le roi sans nom\n"; }