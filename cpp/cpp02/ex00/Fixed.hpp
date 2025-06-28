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

class Fixed
{
public:
    Fixed();
    Fixed(Fixed const& src);
    ~Fixed();

    Fixed&  operator=(Fixed const& c_src);

    int getRawBits() const;
    void setRawBits(int const raw);

private:
    int value;
    static const int bits;
};

#endif