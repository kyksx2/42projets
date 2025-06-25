/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:46:37 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/23 10:04:36 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int main(int ac, char **av) {
  if (ac < 1)
    return (1);
  else if (ac == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
  else {
    for (int i = 1; av[i]; i++) {
      std::string s = av[i];
      for (int j = 0; av[i][j]; j++) {
        char c = std::toupper(av[i][j]);
        std::cout << c;
      }
    }
    std::cout << '\n';
  }
  return (0);
}
