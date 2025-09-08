/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:15:55 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/03 12:51:38 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    srand(std::time(NULL));
    Span sp = Span(5);
    Span sp2 = Span(5);
    std::vector<int> v;

    for(int i = 0; i < 5; i++) {
        int r = rand()%100;
        v.push_back(r);
    }
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "--- 1er conteneur ---" << std::endl;
    sp.printConteneur();
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;

    std::cout << "\n--- fonction add with iterator ---" << std::endl;
    sp2.addRangeNumbers(v.begin(), v.end());
    sp2.printConteneur();

    std::cout << "\n--- Error with addNumber ---" << std::endl;
    try {
        sp.addNumber(6);
    }
    catch(std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n--- Error with addRangeNumbers ---" << std::endl;
    std::vector<int> v2;

    for(int i = 0; i < 8; i++) {
        int r = rand()%100;
        v2.push_back(r);
    }
    try {
        Span sp3(5);
        sp3.addRangeNumbers(v2.begin(), v2.end());
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}