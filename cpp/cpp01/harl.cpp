/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 14:24:17 by marvin            #+#    #+#             */
/*   Updated: 2025/06/26 14:24:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

void Harl::complain(std::string level) {
    void (Harl::*fct[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*fct[i])();
            break;
        }
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

void Harl::error() {
    std::cout << "[ERROR] le roi sans nom\n";
}
