/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:25:47 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/27 18:00:30 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/Converter.hpp"

int main(int argc, char **av) {
    if (argc != 2 || av[0] == '\0') {
        std::cerr << "Usage: ./Converter <literal>" << std::endl;
        return (1);
    }
    ScalarConverter::convert(av[1]);
    return (0);
}