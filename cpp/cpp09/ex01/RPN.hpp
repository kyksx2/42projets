/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 12:32:54 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/11 10:44:16 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_H
#define RPN_H
#include <sstream>
#include <string>
#include <iostream>
#include <stack>
#include <algorithm>

bool goodInput(char &c);
bool parsArg(int ac, char *av);
bool isOperator(std::string token);
bool onlySpace(std::string expr);

#endif