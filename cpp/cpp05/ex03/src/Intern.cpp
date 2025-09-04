/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:46:46 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/23 17:41:45 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src) {
    *this = src;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& src) {
    (void)src;
    return *this;
}

AForm* Intern::createPresidentForm(std::string target){ return new Presidential(target); }

AForm* Intern::createShrubberyForm(std::string target){ return new Shrubbery(target); }

AForm* Intern::createRobotomyForm(std::string target){ return new Robotomy(target); }

AForm*  Intern::makeForm(std::string nameForm, std::string target) {
    AForm* (Intern::*fct[3])(std::string) = {
        &Intern::createPresidentForm,
        &Intern::createShrubberyForm,
        &Intern::createRobotomyForm,
    };
    int index = -1;
    std::string form[3] = {"Presidential", "Shrubbery", "Robotomy"};

    for (int i = 0; i < 3; i++) {
        if (nameForm == form[i]) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        std::cout << "Intern cannot create: " << nameForm << std::endl;
        return NULL;
    }
    std::cout << "Intern creates " << nameForm << std::endl;
    return (this->*fct[index])(target);
}