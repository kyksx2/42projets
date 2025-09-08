/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:29:20 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/08 12:22:58 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av) {
    (void)av;
    if (ac != 2) {
        std::cerr << "Usage: ./btc <file>" << std::endl;
        return 1;
    }
    std::map<std::string, double> m1;
    if (!parseData(m1))
        return (1);
    if (!parseBase(m1, av[1]))
        return (1);
    return 0;
}