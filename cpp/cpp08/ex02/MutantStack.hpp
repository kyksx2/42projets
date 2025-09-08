/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:11:46 by kjolly            #+#    #+#             */
/*   Updated: 2025/09/04 11:07:09 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H
#include <iostream>
#include <algorithm>
#include <stack>

template < typename T, typename cont = std::deque<T> >
class MutantStack : public std::stack<T, cont> {
 public:
    MutantStack() : std::stack<T, cont>() {}
    MutantStack(MutantStack const& src) : std::stack<T, cont>(src) {}
    ~MutantStack() {}

    MutantStack& operator=(MutantStack const& src) {
        std::stack<T, cont>::operator=(src);
        return *this;
    }

    typedef typename std::stack<T, cont>::container_type::iterator iterator;
    typedef typename std::stack<T, cont>::container_type::iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator c_begin() { return this->c.begin(); }
    const_iterator C_end() { return this->c.end(); }
};

#endif