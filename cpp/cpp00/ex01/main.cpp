/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:04:30 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/20 15:55:38 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

int main() {
  PhoneBook book;
  std::string commande;

  while (1) {
    std::cout << "wait for commande [ADD], [SEARCH] or [EXIT]" << '\n';
    if (!std::getline(std::cin, commande))
      return 0;
    if (commande == "ADD") {
      if (!book.add())
        return (1);
    }
    else if (commande == "SEARCH") {
      if (book.search() == 1)
        return (1);
    }
    else if (commande == "EXIT") {
      break;
    }
  }
  return 0;
}