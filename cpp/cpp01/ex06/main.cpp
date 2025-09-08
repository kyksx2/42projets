/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 04:55:06 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/07 10:49:09 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

bool isallupper(std::string av) {
    for (size_t i = 0; i < av.length(); i++) {
        if (!std::isupper(static_cast<unsigned char>(av[i])))
            return false;
    }
    if (av != "ERROR" && av != "DEBUG" && av != "INFO" && av != "WARNING") {
        return false;
    }
    return true;
}

int main(int ac, char **av) {
    if (ac != 2 || !isallupper(av[1])) {
        std::cout << "Usage: ./harl <LEVEL>\n";
        return 1;
    }
    Harl harl;
    harl.complain(av[1]);
    return 0;
}