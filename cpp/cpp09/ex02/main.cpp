/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:15:41 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/11 10:02:28 by kjolly           ###   ########.fr       */
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
    std::cout << "After:  ";
    for(size_t i = 0; i < v1.size(); i++)
        std::cout << v1[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : "
            << V_end - V_start / CLOCKS_PER_SEC << "ms" << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::list : "
            << L_end - L_start / CLOCKS_PER_SEC << "ms" << std::endl;
    return (0);
}
