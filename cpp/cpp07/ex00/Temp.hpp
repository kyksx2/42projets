/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Temp.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 11:13:21 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/29 16:24:28 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMP_H
#define TEMP_H
#include <iostream>

template < typename T >
T const & max(T const & a, T const & b) {
    return (a>b ? a : b);
}

template < typename T2 >
T2 const & min(T2 const & a, T2 const & b) {
    return (a<b ? a : b);
}

template < typename T3 >
void swap(T3 & a, T3 & b) {
    T3 c;

    c = a;
    a = b;
    b = c;
    // std::swap(a, b);
}

#endif