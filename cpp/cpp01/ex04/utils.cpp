/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 18:11:19 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/25 18:12:46 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int check_pbm(std::string s1, std::string s2){
    if (s1.empty()) {
        std::cerr << "Error: empty file\n";
        return 0;
    }
    else if (s1.compare(s2) == 0) {
        std::cerr << "Error: string 1 is equal to string 2\n";
        return 0;
    }
    return 1;
}
