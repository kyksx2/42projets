/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:35:25 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/27 18:04:02 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Converter.hpp"
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

int find_type(std::string src) {
    if (src == "-inff" || src == "+inff" || src == "nanf"
        || src == "-inf" || src == "+inf" || src == "nan")
        return PSEUDO;
    if (src.size() == 3 && src[0] == '\'' && src[2] == '\'')
        return CHAR;
    if (src[src.size() - 1] == 'f' && src.find('.') != std::string::npos)
        return FLOAT;
    if (src.find('.') != std::string::npos)
        return DOUBLE;
    size_t i = (src[0] == '+' || src[0] == '-') ? 1 : 0; //? si on trouve + ou - on commence a 1 sinon 0
    for (; i < src.size(); i++)
        if (!isdigit(src[i]))
            return INVALIDE;
    return INT;
}

void    convertInt(std::string src) {
    long i = static_cast<long>(atol(src.c_str()));
    
    if (i < INT_MIN || i > INT_MAX) {
        std::cerr << "int out of range" << std::endl;
        return ;
    }
    if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else if (i < 32 || i > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void    convertFloat(std::string src) {
    size_t i = (src[0] == '+' || src[0] == '-') ? 1 : 0;
    for (; i < src.size() && src[i] != '.'; i++) {
        if (!isdigit(src[i])) {
            std::cerr << "Error: wrong literal" << std::endl;
            return ;
        }
    }
    if (i == 0) {
        std::cerr << "Error: bad float" << std::endl;
        return ;
    }
    i++;
    if (src[i] == 'f') {
        std::cerr << "Error: bad float" << std::endl;
        return ;
    }
    for (; i < src.size() && src[i] != 'f'; i++) {
        if (!isdigit(src[i])) {
            std::cerr << "Error: wrong literal" << std::endl;
            return;
        }
    }
    float f = static_cast<float>(atof(src.c_str()));
    if (std::isinf(f)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
        std::cout << "double: " << (f > 0 ? "+inf" : "-inf") << std::endl;
        return ;
    }
    char c = static_cast<char>(f);
    if (c < 0 || c > 127)
        std::cout << "char: impossible" << std::endl;
    else if (c < 32 || c > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void    convertDouble(std::string src) {
    size_t i = (src[0] == '+' || src[0] == '-') ? 1 : 0;
    for (; i < src.size() && src[i] != '.'; i++) {
        if (!isdigit(src[i])) {
            std::cerr << "Error: wrong literal" << std::endl;
            return ;
        }
    }
    if (i == 0) {
        std::cerr << "Error: bad double" << std::endl;
        return ;
    }
    i++;
    for (; i < src.size(); i++) {
        if (!isdigit(src[i]))
        {
            std::cerr << "Error: wrong literal" << std::endl;
            return;
        }
    }
    double d = static_cast<double>(atof(src.c_str()));
    if (std::isinf(d)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (d > 0 ? "+inff" : "-inff") << std::endl;
        std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
        return ;
    }
    char c = static_cast<char>(d);
    if (c < 0 || c > 127)
        std::cout << "char: impossible" << std::endl;
    else if (c < 32 || c > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void    convertPseudo(std::string src) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (src == "nanf" || src == "nan")
        std::cout << "float: nanf" << std::endl << "double: nan" << std::endl;
    else if (src == "-inff" || src == "-inf")
        std::cout << "float: -inff" << std::endl << "double: -inf" << std::endl;
    else if (src == "+inff" || src == "+inf")
        std::cout << "float: +inff" << std::endl << "double: +inf" << std::endl;
}

void    convertChar(std::string src) {
    char c = src[1];

    if (c < 32 || c > 126)
        std::cout << "Non displayable char" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void    ScalarConverter::convert(const std::string& src) {
    int type = find_type(src);

    if (type == CHAR)
        convertChar(src);
    else if (type == INT)
        convertInt(src);
    else if (type == FLOAT)
        convertFloat(src);
    else if (type == DOUBLE)
        convertDouble(src);
    else if (type == PSEUDO)
        convertPseudo(src);
    else
        std::cerr << "Error: bad type" << std::endl;
}