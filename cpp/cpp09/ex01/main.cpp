/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:33:12 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/08 17:18:50 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool goodInput(char &c) {
    if (c != '/' && c != '*' && c != '-' && c != '+' && !isdigit(c) && c != ' ') {
        std::cerr << "Error: bad input." << std::endl;
        return false;
    }
    return true;
}

bool parsArg(int ac, char *av) {
    if (ac != 2) {
        std::cerr << "Usage: ./RPN <expression>" << std::endl;
        return false;
    }
    for (size_t i = 0; av[i]; i++) {
        if (!goodInput(av[i]))
            return false;
    }
    true;
}

int main(int ac, char **av) {
    if (!parsArg(ac, av[1]))
        return 1;
    std::string expr = av[1];
    std::istringstream iss(expr);
    std::string token;
    std::stack<int> s1;

    while (iss >> token) {
        
    }
    return (0);
}