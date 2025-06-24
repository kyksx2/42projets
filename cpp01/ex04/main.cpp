/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 20:41:53 by marvin            #+#    #+#             */
/*   Updated: 2025/06/24 20:41:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int argc, char **argv) {
    (void)argv;
    if (argc != 4) {
        std::cout << "Bad arguments numbers\n";
        return 1;
    }
    std::string infile = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (infile.empty()) {
        std::cout << "Error: empty file\n";
        return 1;
    }
    return 0;
}