/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:33:02 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/11 10:43:52 by kjolly           ###   ########.fr       */
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
    return true;
}

bool isOperator(std::string token) {
    return (token == "+" || token == "-" || token == "/" || token == "*");
}

bool onlySpace(std::string expr) {
    for (size_t i = 0; i < expr.size(); i++) {
        if (!isspace(expr[i]))
            return false;
    }
    return true;
}