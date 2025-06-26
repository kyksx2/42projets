/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:24:12 by marvin            #+#    #+#             */
/*   Updated: 2025/06/26 14:24:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

bool isallupper(std::string av) {
    for (size_t i = 0; i < av.length(); i++) {
        if (!std::isupper(static_cast<unsigned char>(av[i])))
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
