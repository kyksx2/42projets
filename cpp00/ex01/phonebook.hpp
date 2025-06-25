/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 18:12:28 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/20 16:09:08 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook {
public:
  PhoneBook();
  ~PhoneBook();
  int     nb_contact;
  int     older;
  bool add();
  int search();
  void printList();

private:
  Contact contacts[8];
};

#endif