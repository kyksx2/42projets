/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:56:41 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/01 11:30:07 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void    increment(int i) {
    i++;
    std::cout << i << std::endl;
}

int main() {
    std::string array = "je suis kyllian";
    int tab[] = {0, 1, 2, 3};

    std::cout << "--- TEST STRING ---" << std::endl;
    iter(array.c_str(), array.size(), printEllement<char>);
    std::cout << std::endl;
    std::cout << "--- TEST INT ---" << std::endl;
    iter(tab, 4, increment);
    std::cout << std::endl;
    return 0;
}