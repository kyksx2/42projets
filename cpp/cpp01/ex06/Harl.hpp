/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 04:55:16 by kjolly            #+#    #+#             */
/*   Updated: 2025/07/03 15:39:48 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H
#include <iostream>

class Harl {
public:
    void complain(const std::string level);
private:
    void debug();
    void info();
    void warning();
    void error();
};

#endif