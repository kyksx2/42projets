/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:05:24 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/27 11:59:45 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
#define SERIALIZER_H
#include <iostream>
#include <stdint.h>

typedef struct s_data
{
    int value;
}   Data;


class Serializer {
 public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
 private:
    Serializer();
    ~Serializer();
};

#endif