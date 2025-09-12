/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:15:37 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/12 10:46:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool checkArg(char **av) {
    for (int i = 0; av[i]; i++) {
        if (av[i][0] == '\0')
            return false;
        for (int j = 0; av[i][j]; j++)
            if (!isdigit(av[i][j]))
                return false;
    }
    return true;
}

std::vector<int> jacobsthalSuite(int size) {
    std::vector<int> j;
    long j0 = 0;
    long j1 = 1;
    long j2 = 0;

    while (1) {
        j2 = j1 + (2 * j0);
        if (j2 > size)
            break;
        j.push_back(j2);
        j0 = j1;
        j1 = j2;
    }
    for (int i = size; i >= 1; i--) {
        bool find = false;
        for (size_t k = 0; k < j.size(); k++) {
            if (j[k] == i) {
                find = true;
                break;
            }
        }
        if (!find)
            j.push_back(i);
    }
    for (std::vector<int>::iterator it = j.begin(); it != j.end(); it++)
        --(*it);
    return j;
}