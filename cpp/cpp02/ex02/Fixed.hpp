/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:53:08 by marvin            #+#    #+#             */
/*   Updated: 2025/06/28 13:53:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
# include <iostream>
# include <cmath>
# include <fstream>

class Fixed
{
public:
    Fixed();
    Fixed(Fixed const& src);
    Fixed(const int i);
    Fixed(const float f);
    ~Fixed();

    Fixed&  operator=(Fixed const& c_src);

    bool  operator>(Fixed const& c_src) const;
    bool  operator<(Fixed const& c_src) const;
    bool  operator>=(Fixed const& c_src) const;
    bool  operator<=(Fixed const& c_src) const;
    bool  operator==(Fixed const& c_src) const;
    bool  operator!=(Fixed const& c_src) const;

    Fixed  operator+(Fixed const& c_src) const;
    Fixed  operator-(Fixed const& c_src) const;
    Fixed  operator*(Fixed const& c_src) const;
    Fixed  operator/(Fixed const& c_src) const;
    //incrementation
    Fixed&  operator++(); //pre incrementation (++x) modifie la ref et la retourne
    Fixed  operator++(int); // post (x++) modifie mais retourne l'ancienne valeur
    Fixed&  operator--();
    Fixed  operator--(int);
    // ? le int est une convention pour differencier pré et post

    static Fixed& min(Fixed& a, Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

    // conversion float et int
    float toFloat() const;
    int toInt() const;
    // retourne et donne les valeurs
    int getRawBits() const;
    void setRawBits(int const raw);
    
    private:
    int value;
    static const int bits;
};

std::ostream&  operator<<(std::ostream& os, const Fixed& fixed);

#endif