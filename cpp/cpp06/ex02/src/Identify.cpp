/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:35:28 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/28 12:19:42 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Identify.hpp"

Base::~Base() {};

Base* generate(void) {
    srand(std::time(NULL));
    if (rand()%3 == 0)
        return new A;
    else if (rand()%3 == 1)
        return new B;
    else
        return new C;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A identified" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B identified" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C identified" << std::endl;
    else
        std::cout << "Error" << std::endl;
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A identified" << std::endl;
    }
    catch (std::exception &bc) {
        std::cout << "Error: bad cast " << bc.what() << std::endl;
    }
    try{
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "B identified" << std::endl;
    }
    catch (std::exception &bc) {
        std::cout << "Error: bad cast " << bc.what() << std::endl;
    }
    try {        
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "C identified" << std::endl;
    }
    catch (std::exception &bc) {
        std::cout << "Error: bad cast " << bc.what() << std::endl;
    }
}
