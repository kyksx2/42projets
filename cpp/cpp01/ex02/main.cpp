/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:52:51 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/24 10:04:59 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPtr = &str;
    std::string &stringRef = str;

    std::cout << "memory adress str: " << &str << "\n";
    std::cout << "memory adress Ref: " << &stringRef << "\n";
    std::cout << "memory adress Ptr: " << stringPtr << "\n";

    std::cout << "value of str: " << str << "\n";
    std::cout << "value of Ref: " << stringRef << "\n";
    std::cout << "value of Ptr: " << *stringPtr << "\n";

    return 0;
}
