/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:15:41 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/12 11:09:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
    std::cout << "Before:  ";
    for(size_t i = 0; i < v1.size(); i++)
        std::cout << v1[i] << " ";
    std::cout << std::endl;
    const std::clock_t V_start = std::clock();
    fordJohnsonSort(v1);
    const std::clock_t V_end = std::clock();
    const std::clock_t L_start = std::clock();
    fordJohnsonSort(l1);
    const std::clock_t L_end = std::clock();
    std::cout << "--- vector ---" << std::endl <<"After:  ";
    for(size_t i = 0; i < v1.size(); i++)
        std::cout << v1[i] << " ";
    std::cout << std::endl << "--- list ---" << std::endl << "After:  ";
    for(std::list<int>::iterator it = l1.begin(); it != l1.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    double elapsedV = double(V_end - V_start) * 1000.0 / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : "
            << elapsedV << "ms" << std::endl;
    double elapsedL = double(L_end - L_start) * 1000.0 / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::list : "
            << elapsedL << "ms" << std::endl;
    return (0);
}
