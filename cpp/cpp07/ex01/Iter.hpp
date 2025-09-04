/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:21:35 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/01 11:26:54 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H
#include <iostream>

template < typename T, typename F >
void    iter(T* a, size_t len, F function) {
    for(size_t i = 0; i < len; i++) {
        function(a[i]);
    }
}

template < typename U >
void    printEllement(const U& u) {
    std::cout << u;
}

template < typename L >
void    upcase(L a) {
    char c = std::toupper(a);
    std::cout << c;
}

void    increment(int i);

#endif