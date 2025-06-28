/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:53:13 by marvin            #+#    #+#             */
/*   Updated: 2025/06/28 13:53:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(): value(5) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    // this->value = src.getRawBits();
}

Fixed&  Fixed::operator=(Fixed const& c_src){
    std::cout << "Copy assignement operator called" << std::endl;
    if (this != &c_src)
        this->value = c_src.getRawBits();
    return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

void    Fixed::setRawBits(int const raw) {
    value = raw;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits function called" << std::endl;
    return (this->value);
}