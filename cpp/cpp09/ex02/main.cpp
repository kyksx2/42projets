/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:15:41 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/09 12:46:53 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool checkArg(char **av) {
    for (int i = 0; av[i]; i++)
        for (int j = 0; av[i][j]; j++)
            if (!isdigit(av[i][j]) && av[i][j] != ' ')
                return false;
    return true;
}

int main(int ac, char **av) {
    if (ac < 2 || !checkArg(&av[1])) {
        std::cerr << "Error: bad input." << std::endl;
        return (1);
    }
    std::vector<int> v1;
    std::list<int> l1;
    for (size_t i = 1; av[i]; i++) {
            int n = atoi(av[i]);
            v1.push_back(n);
            l1.push_back(n);
    }
}