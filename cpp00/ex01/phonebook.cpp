/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:12:34 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/20 16:12:55 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void printClass(Contact contact) {
  std::cout << "first name: " << contact.firstName << '\n';
  std::cout << "last name: " << contact.lastName << '\n';
  std::cout << "nickname: " << contact.nickname << '\n';
  std::cout << "ds: " << contact.darkestSecret << '\n';
  std::cout << "pn: " << contact.phoneNumber << '\n';
  std::cout << "index: " << contact.index << '\n';
}

PhoneBook::PhoneBook() : nb_contact(0), older(0) {}

PhoneBook::~PhoneBook() { return; }

std::string formatField(const std::string &str) {
  if (str.length() > 10) {
    return (str.substr(0, 9) + ".");
  } else
    return (std::string(10 - str.length(), ' ') + str);
}

void PhoneBook::printList() {
  std::cout << "|     Index|First Name| Last Name|  Nickname|\n";
  for (int i = 0; i < nb_contact; ++i) {
    std::cout << '|' << std::setw(10) << i << '|'
              << formatField(contacts[i].firstName) << '|'
              << formatField(contacts[i].lastName) << '|'
              << formatField(contacts[i].nickname) << "|\n";
  }
}

bool PhoneBook::add() {
  Contact contact;
  std::cout << "enter the first name: " << '\n';
  if (!std::getline(std::cin, contact.firstName))
    return 0;
  else
    std::cout << "enter the last name: " << '\n';
  if (!std::getline(std::cin, contact.lastName))
    return 0;
  else
    std::cout << "enter the nickname: " << '\n';
  if (!std::getline(std::cin, contact.nickname))
    return 0;
  else
    std::cout << "enter your darkest secret: " << '\n';
  if (!std::getline(std::cin, contact.darkestSecret))
    return 0;
  else
    std::cout << "enter phone number: " << '\n';
  if (!std::getline(std::cin, contact.phoneNumber))
    return 0;
  contact.index = (nb_contact < 8) ? nb_contact : older;
  contacts[contact.index] = contact;
  if (nb_contact < 8)
    nb_contact++;
  else
    older = (older + 1) % 8; // ? ici le '%8' remet older a 0 cat 8 % 8 = 0;
  return 1;
}

int PhoneBook::search() {
  if (nb_contact <= 0) {
    std::cout << "No contact available, try \"ADD\"\n";
    return 0;
  }
  printList();

  std::cout << "Enter index of the contact\n";
  std::string input;
  if (!std::getline(std::cin, input)) {
    std::cout << "Input error\n";
    return 1;
  }
  if (input.length() > 1 || !isdigit(input[0])) {
    std::cout << "invalid input\n";
    return 0;
  }
  int index = input[0] - '0';
  if (index < 0 || index > nb_contact - 1) {
    std::cout << "Invalid index\n";
    return 0;
  }
  printClass(contacts[index]);
  return 0;
}
