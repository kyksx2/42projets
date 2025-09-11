/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:29:45 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/11 10:27:39 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string trim(std::string dataStr, int type, int subPos) {
    std::string src;
    if (type == 1)
        src = dataStr.substr(0, subPos);
    else
        src = dataStr.substr(subPos + 1);
    if (src.empty())
        return src;
    size_t i = 0;
    while (i < src.length() && isspace(src[i]))
        i++;
    if (i >= src.length())
        return "";
    size_t j = src.size() - 1;
    while (j > i && isspace(src[j]))
        j--;
    return (src.substr(i, j - i + 1));
}

bool checkContent(std::string date, std::string value) {
    if (date.length() != 10)
        return false;
    for (size_t i = 0; i < date.length(); i++) {
        if (i == 4 || i == 7) {
            if (date[i] != '-')
                return false;            
        }
        else {
            if (!isdigit(date[i]))
                return false;
        }
    }
    char *end;
    double d = strtod(value.c_str(), &end);
    (void)d;
    if (*end != '\0')
        return false;
    return true;
}

bool goodDate(std::string date) {
    int year = 0;
    int month = 0;
    int day = 0;
    for(int i = 0; i < 4; i++) {
        year = year * 10 + (date[i] - '0');
    }
    if (year < 2009) {
        std::cout << "Error: bitcoin started in 2009" << std::endl;
        return false;
    }
    if (year > 2025) {
        std::cout << "Error: the limit is 2025" << std::endl;
        return false;
    }
    month = (date[5] - '0') * 10 + (date[6] - '0');
    day = (date[8] - '0') * 10 + (date[9] - '0');
    if (month < 1 || month > 12) {
        std::cout << "Error bad month on file" << std::endl;
        return false;
    }
    if (day < 1 || day > 31 || (month == 2 && day > 29)) {
        std::cout << "Error bad day on file" << std::endl;
        return false;
    }
    return true;
}

bool parseData(std::map<std::string, double>& m1) {
    std::ifstream data("data.csv");
    if (!data) {
        std::cerr << "Error: cannot open .csv file." << std::endl;
        return false;
    }
    std::string dataStr;
    std::getline(data, dataStr);
    while (getline(data, dataStr)){
        if (dataStr.empty())
            continue;
        size_t subPos = dataStr.find(",");
        if (subPos == std::string::npos) {
            std::cerr << "Error: bad line on .csv file" << std::endl;
            return false;
        }
        std::string date = trim(dataStr, 1, subPos);
        std::string value = trim(dataStr, 2, subPos);
        if (value.empty() || date.empty() || !checkContent(date, value)) {
            std::cerr << "Error: bad line on .csv file" << std::endl; 
            return false;
        }
        if (!goodDate(date))
            return false;
        char * end;
        double d = strtod(value.c_str(), &end);
        if (*end != '\0') {
            std::cout << "Error: convertion to double failed" << std::endl;
            return false;
        }
        m1[date] = d;
    }
    data.close();
    return true;
}

bool handleResult(double d, std::map<std::string, double> m1, std::string date, std::string value) {
        if (d > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            return false;
        }
        if (d <= 0) {
            std::cout << "Error: not a positive number." << std::endl;
            return false;
        }
        std::map<std::string, double>::iterator it = m1.lower_bound(date);
        double result = 0.0;
        if (it != m1.end() && it->first == date) {
            result = d * it->second;
        }
        else {
            if (it == m1.begin()) {
                std::cout << "Error: date too early" << std::endl;
                return false;
            }
            else {
                --it;
                result = d * it->second;
            }
        }
        std::cout << date << " => " << value << " = " << result << std::endl;
        return true;
}

bool parseBase(std::map<std::string, double>& m1, char *av) {
    std::ifstream base(av);
    if (!base) {
        std::cerr << "Error: cannot open data base file." << std::endl;
        return 1;
    }
    std::string baseStr;
    std::getline(base, baseStr);
    while(std::getline(base, baseStr)) {
        if (baseStr.empty())
            continue;
        size_t subPos = baseStr.find("|");
        if (subPos == std::string::npos) {
            std::cerr << "Error: bad line on data base file => \"" << baseStr << "\""  << std::endl;
            continue;
        }
        std::string date = trim(baseStr, 1, subPos);
        std::string value = trim(baseStr, 0, subPos);
        if (value.empty() || date.empty() || !checkContent(date, value)) {
            std::cerr << "Error: bad line on data base file => \"" << baseStr << "\"" << std::endl;
            continue;
        }
        if (!goodDate(date))
            return false;
        char * end;
        double d = strtod(value.c_str(), &end);
        if (*end != '\0') {
            std::cout << "Error: convertion to double failed" << std::endl;
            return false;
        }
        if (!handleResult(d, m1, date, value))
            continue;
    }
    return true;
}
