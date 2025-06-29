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

Fixed::Fixed(): value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(int i) {
    std::cout << "Int constructor called" << std::endl;
    this->value = i << bits;
    /* comme la valeur est preparer pour un format a virgule fixe
    sur 8 bits fractionnaires je dois egalement anticiper avec le int
    et ne pas juste faire "this->value = i" car il fera apres 10 / (1 << bits) */
}

Fixed::Fixed(float f) {
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(f * (1 << bits));
    /* ici on stocke un nombre à virgule fixe en utilisant 8 bits pour la partie fractionnaire.
    Pour convertir un float en ce format, on multiplie par 256 (1 << 8 (== 2^8)).
    roundf() arrondi en fonction des chiffres suivant la virgule.
    Pour récupérer le float, tu divises par 256.
    Puissance de 2 pour les opérations binaires. */
}

std::ostream&  operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return (out);
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

float   Fixed::toFloat(void) const {
    return ((float)this->value / (1 << bits));
}

int Fixed::toInt() const {
    return (this->value >> bits);
}

void    Fixed::setRawBits(int const raw) {
    value = raw;
}

int Fixed::getRawBits() const {
    return (this->value);
}