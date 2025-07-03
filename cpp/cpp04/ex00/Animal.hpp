/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:51:20 by marvin            #+#    #+#             */
/*   Updated: 2025/07/03 23:51:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H
# include <iostream>

class Animal {
public:
    Animal();
    Animal(Animal const& src);
    ~Animal();

    Animal& operator=(Animal const& src);

    void makeSound();
    std::string getType();
protected:
    std::string type;
}

#endif
