/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:15:17 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/12 11:02:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <ctime>

bool checkArg(char **av);
std::vector<int> jacobsthalSuite(int size);

template <typename T>
void fordJohnsonSort(T& v) {
    if (v.size() <= 1)
        return ;
    T small;
    T big;
    typename T::iterator i = v.begin();
    while (i != v.end()) {
        typename T::value_type a = *i;
        typename T::value_type b;
        typename T::iterator next = i;
        next++;
        if (next != v.end()) 
            b = *next;
        else {
            small.push_back(a);
            break;
        }
        if (a >= b) {
            big.push_back(a);
            small.push_back(b);
        }
        else {
            big.push_back(b);
            small.push_back(a);
        }
        i = next;
        i++;
    }
    fordJohnsonSort(big);
    std::vector<int> jacobsthal = jacobsthalSuite(small.size());
    for(std::vector<int>::iterator itj = jacobsthal.begin(); itj != jacobsthal.end(); itj++) {
        std::vector<int>::value_type index = *itj;
        typename T::iterator it = small.begin();
        std::advance(it, index);   // avance de index pas à pas
        typename T::value_type elem = *it;
        typename T::iterator pos = big.begin();
        while (pos != big.end() && *pos < elem )
            pos++;
        big.insert(pos, elem);
    }
    v = big;
}

#endif