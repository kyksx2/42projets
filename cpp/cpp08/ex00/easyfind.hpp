/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:02:51 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/02 12:09:41 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
#define EASYFIND_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template < typename T >
typename T::iterator    easyfind(T& cont, int elem) {
    typename T::iterator it = std::find(cont.begin(), cont.end(), elem);
    if (it == cont.end()) {
        throw std::runtime_error("occurence not found");
    }
    return (it);
}

#endif