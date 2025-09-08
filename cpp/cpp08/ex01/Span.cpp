/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 17:15:59 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/03 12:52:09 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0), tabNums() {}

Span::Span(unsigned int num) : N(num), tabNums() {}

Span::Span(const Span& src) : N(src.N), tabNums(src.tabNums) {}

Span&   Span::operator=(const Span& src) {
    if (this != &src) { tabNums = src.tabNums; }
    return *this;
}

Span::~Span() {}

void   Span::addNumber(int n) {
    if (tabNums.size() >= this->N)
        throw std::runtime_error("max numbers reached");
    this->tabNums.push_back(n);
}

void    Span::addRangeNumbers(std::vector<int>::iterator first, std::vector<int>::iterator last) {
    for (;first != last; first++) {
        if (this->tabNums.size() >= this->N)
            throw std::runtime_error("max numbers reached");
        this->tabNums.push_back(*first);
    }
}

int Span::shortestSpan() {
    if (this->tabNums.size() < 2)
        throw std::runtime_error("need at least 2 numbers");

    std::sort(this->tabNums.begin(), this->tabNums.end());
    std::vector<int>::iterator it = this->tabNums.begin();
    int minSpan = *(it + 1) - *it;

    for (; it != this->tabNums.end() - 1; ++it) {
        int minTmp = *(it + 1) - *it;
        if (minTmp < minSpan)
            minSpan = minTmp;
    }
    return minSpan;
}

int Span::longestSpan() {
    if (this->tabNums.size() < 2)
        throw std::runtime_error("need at least 2 numbers");

    int min = *min_element(this->tabNums.begin(), this->tabNums.end());
    int max = *max_element(this->tabNums.begin(), this->tabNums.end());
    return max - min;
}

void Span::printConteneur() {
    for(std::vector<int>::iterator it = this->tabNums.begin(); it != this->tabNums.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
