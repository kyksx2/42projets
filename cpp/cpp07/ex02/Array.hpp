/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:12:59 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/02 10:29:01 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <ctime>
#include <cstdlib>


template < typename T >
class Array {
 public:
    Array() : array(NULL), len(0) {}

    Array(unsigned int n) : array(new T[n]), len(n) {}

    Array(const Array& src) : len(src.len) {
        array = new T[len];
        for(size_t i = 0; i < len; i++) {
            array[i] = src.array[i];
        }
    }

    ~Array() { delete[](array); }

    Array&    operator=(const Array& src) {
        if (this != &src) {
            delete[] array;
            len = src.len;
            array = new T[len];
            for(int i = 0; i < len; i++) {
                array[i] = src.array[i];
            }
        }
        return *this;
    }

    T&  operator[](size_t i) {
        if (i >= this->len)
            throw indexOutOfRange();
        return array[i];
    }

    const T&  operator[](size_t i) const {
        if (i >= this->len)
            throw indexOutOfRange();
        return array[i];
    }

    class indexOutOfRange : public std::exception {
        const char *what() const throw() {
            return "index out of range";
        }
    };
    
    size_t    size(){ return len; }
 private:
    T* array;
    size_t len;
};

#endif