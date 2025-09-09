/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:33:12 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/09 09:42:14 by kjolly           ###   ########.fr       */
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

int main(int ac, char **av) {
    if (!parsArg(ac, av[1]))
        return 1;
    std::string expr = av[1];
    std::istringstream iss(expr);
    std::string token;
    std::stack<int> s1;

    int a = 0;
    int b = 0;
    while (iss >> token) {
        if (isOperator(token)) {
            if (s1.size() < 2) {
                std::cerr << "Error: bad operator input";
                return (1);
            }
            else if (s1.size() >= 2) {
                a = s1.top();
                s1.pop();
                b = s1.top();
                s1.pop();
                if (token == "+")
                    s1.push(b + a);
                else if (token == "-")
                    s1.push(b - a);
                else if (token == "*")
                    s1.push(b * a);
                else if (token == "/")
                    s1.push(b / a);
            }
        }
        if (/*s1.size() < 2 && */!isOperator(token)) {
            s1.push(atoi(token.c_str()));
        }
    }
    std::cout << s1.top() << std::endl;
    return (0);
}