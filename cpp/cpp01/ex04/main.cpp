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
    std::string file = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (!check_pbm(s1, s2))
        return 1;

    std::ifstream infile(file.c_str());
    if (!infile) {
        std::cerr << "Error: cannot open infile\n";
        return 1;
    }
    
    std::string line;
    std::string result;
    while (getline(infile, line)){
        result += line + "\n";
    }
    infile.close();

    std::string newline;
    size_t count = 0;
    size_t start;
    while ((start = result.find(s1, count)) != std::string::npos) {
        newline = result.substr(count, start - count);
        newline += s2;
        count = start + s1.length();
    }
    newline += result.substr(count);

    std::ofstream outfile((file + ".replace").c_str());
    if (!outfile) {
        std::cerr << "Error: cannot open outfile\n";
        return 1;
    }

    outfile << newline;
    outfile.close();
    return 0;
}
