/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:15:17 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/10 18:03:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <ctime>

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
    for (typename T::iterator i = small.begin(); i != small.end(); i++) {
        typename T::value_type elem = *i;
        typename T::iterator it = big.begin();
        while (it != big.end() && *it < elem)
            it++;
        big.insert(it, elem);
    }
    v = big;
}

#endif