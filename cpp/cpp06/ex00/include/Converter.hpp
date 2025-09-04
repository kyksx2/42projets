/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:22:27 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/27 18:02:00 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
#define CONVERTER_H
#include <iostream>
#include <climits>
#include <cmath>
#include <vector>

typedef enum e_type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALIDE,
}   t_type;

class ScalarConverter {
    public:
        static void convert(const std::string& src);
    private:
        ScalarConverter();
        ~ScalarConverter();
};

int find_type(std::string src);
void    convertChar(std::string src);
void    convertFloat(std::string src);
void    convertInt(std::string src);
void    convertDouble(std::string src);
void    convertPseudo(std::string src);

#endif