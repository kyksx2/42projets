/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:11:38 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/28 10:21:26 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Identify.hpp"

int main() {
    Base* b = generate();
    Base* b2 = generate();

    identify(b);
    std::cout << "--- test reference (try/catch) ---" << std::endl;
    identify(*b2);
    delete(b);
    delete(b2);
}
