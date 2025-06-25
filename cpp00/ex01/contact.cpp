/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 21:20:22 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/20 16:09:23 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() {
  Contact::darkestSecret = "";
  Contact::firstName = "";
  Contact::lastName = "";
  Contact::nickname = "";
  Contact::phoneNumber = "";
  Contact::index = 0;
}

Contact::~Contact() { return; }