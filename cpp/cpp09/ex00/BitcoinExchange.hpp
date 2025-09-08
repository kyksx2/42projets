/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 12:30:00 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/08 12:30:18 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>



std::string trim(std::string dataStr, int type, int subPos);
bool checkContent(std::string date, std::string value);
bool goodDate(std::string date);
bool parseData(std::map<std::string, double>& m1);
bool parseBase(std::map<std::string, double>& m1, char *av);
bool handleResult(double d, std::map<std::string, double> m1, std::string date, std::string value);

#endif