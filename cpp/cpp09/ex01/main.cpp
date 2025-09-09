/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:33:12 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/09 10:12:05 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

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