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

Fixed::Fixed(): value(0) {}

Fixed::Fixed(Fixed const& src) { *this = src; }

Fixed::Fixed(int i) { this->value = i << bits; }

Fixed::Fixed(float f) { this->value = roundf(f * (1 << bits)); }

std::ostream&  operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return (out);
}

Fixed&  Fixed::operator=(Fixed const& c_src){
    if (this != &c_src)
        this->value = c_src.getRawBits();
    return (*this);
}

bool  Fixed::operator>(Fixed const& c_src) const { return (value > c_src.value); }

bool  Fixed::operator<(Fixed const& c_src) const { return (value < c_src.value); }

bool  Fixed::operator>=(Fixed const& c_src) const { return (value >= c_src.value); }

bool  Fixed::operator<=(Fixed const& c_src) const { return (value <= c_src.value); }

bool  Fixed::operator==(Fixed const& c_src) const { return (value == c_src.value); }

bool  Fixed::operator!=(Fixed const& c_src) const { return (value != c_src.value); }

Fixed  Fixed::operator+(Fixed const& c_src) const {
    Fixed new_f;
    new_f.value = this->value + c_src.value;
    return (new_f);
}

Fixed  Fixed::operator-(Fixed const& c_src) const {
    Fixed new_f;
    new_f.value = this->value - c_src.value;
    return (new_f);
}

Fixed  Fixed::operator*(Fixed const& c_src) const {
    Fixed new_f;
    long tmp = static_cast<long>(this->value) * static_cast<long>(c_src.value);
    new_f.value = static_cast<int>(tmp >> bits);
    return (new_f);
}

Fixed Fixed::operator/(const Fixed& c_src) const {
    Fixed result;
    if (c_src.value == 0) {
        std::cout << "error\n";
    }
    else {
        long tmp = (static_cast<long>(this->value) << bits) / c_src.value;
        result.value = static_cast<int>(tmp);
    }
    return result;
}

Fixed&  Fixed::operator++() {
    this->value += 1;
    return (*this);
}

Fixed  Fixed::operator++(int) {
    Fixed temp = *this;
    this->value += 1;
    return (temp);
}

Fixed&  Fixed::operator--() {
    this->value -= (1 << bits);
    return (*this);
}

Fixed  Fixed::operator--(int) {
    Fixed temp = *this;
    this->value += (1 << bits);
    return (temp);
}

Fixed::~Fixed() {}

Fixed& Fixed::min(Fixed& a, Fixed& b) { return (a < b) ? a : b; }

Fixed& Fixed::max(Fixed& a, Fixed& b) { return (a > b) ? a : b; }

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { return (a < b) ? a : b; }

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) { return (a > b) ? a : b; }

float   Fixed::toFloat(void) const { return ((float)this->value / (1 << bits)); }

int Fixed::toInt() const { return (this->value >> bits); }

void    Fixed::setRawBits(int const raw) { value = raw; }

int Fixed::getRawBits() const { return (this->value); }