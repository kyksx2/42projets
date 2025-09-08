/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:11:29 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/04 11:32:03 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {
    MutantStack<int> s1;
    
    s1.push(5);
    s1.push(3);

    MutantStack<int> s2 = s1;
    MutantStack<int>::iterator iterator = s1.begin();

    std::cout << "--- copy test ---" << std::endl;
    std::cout << "s1.size: " << s1.size() << std::endl
        << "s1.begin: " << *iterator << std::endl
        << "s1.top: " << s1.top() << std::endl;
    std::cout << "s2.size: " << s2.size() << std::endl
        << "s2.begin: " << *iterator << std::endl
        << "s2.top: " << s2.top() << std::endl;

    std::cout << "--- iterator test ---" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "mstack.top: " << mstack.top() << std::endl;

    std::cout << "--- pop/size test ---" << std::endl;
    std::cout << mstack.size() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << "--- print stack with iterator test ---" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}
