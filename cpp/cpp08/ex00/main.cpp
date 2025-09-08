/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:03:25 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/02 16:22:15 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
    std::vector<int>    v;

    v.push_back(1);
    v.push_back(5);
    v.push_back(14);
    v.push_back(18);
    v.push_back(9);
    
    std::cout << "--- test error ---" << std::endl;
    try {
        std::vector<int>::iterator found = easyfind(v, 0);
        std::cout << "I found: " << *found << std::endl;
    }
    catch(std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "--- test ok ---" << std::endl;
    try {
        std::vector<int>::iterator found = easyfind(v, 14);
        std::cout << "I found: " << *found << std::endl;
    }
    catch(std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "--- test last occurence ---" << std::endl;
    try {
        std::vector<int>::iterator found = easyfind(v, 9);
        std::cout << "I found: " << *found << std::endl;
    }
    catch(std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}