/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:21:48 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/27 18:04:38 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Serializer.hpp"

int main() {
    Data ptr;
    uintptr_t p;

    ptr.value = 42;
    p = Serializer::serialize(&ptr);
    std::cout << "serialize: "<< p << std::endl;
    Data* dptr = Serializer::deserialize(p);
    std::cout << "deserialize: "<< dptr->value << std::endl;
    return 0;
}

//?? ne pas oublier le pointeurs et adresses