/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:16:02 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/03 12:40:04 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_H
#define SPAN_H
#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>

class Span {
 public:
   Span();
   Span(unsigned int num);
   Span(const Span& src);
   ~Span();
   Span& operator=(const Span& src);

   void addNumber(int n);
   void addRangeNumbers(std::vector<int>::iterator first,
     std::vector<int>::iterator last);
   void printConteneur();
   int shortestSpan();
   int longestSpan();

 private:
   unsigned int N; //max integer to store
   std::vector<int> tabNums;
};

#endif