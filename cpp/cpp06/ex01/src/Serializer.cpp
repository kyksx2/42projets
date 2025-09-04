/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 16:17:29 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/27 11:53:48 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer() {}

uintptr_t   Serializer::serialize(Data* ptr) {
    uintptr_t uptr = reinterpret_cast<uintptr_t>(ptr);
    return (uptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    Data*  ptr = reinterpret_cast<Data*>(raw);
    return (ptr);
}

// !! reinterpret_cast -> permet une conversion bas niveau entre
// !! types de pointeurs et entiers