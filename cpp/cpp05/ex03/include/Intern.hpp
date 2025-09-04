/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:46:14 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/23 13:47:21 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
#define INTERN_H
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
 public :
    Intern();
    Intern(const Intern& src);
    ~Intern();

    Intern& operator=(const Intern& src);

    AForm* makeForm(std::string nameForm, std::string target);
    AForm* createPresidentForm(std::string target) ;
    AForm* createShrubberyForm(std::string target) ;
    AForm* createRobotomyForm(std::string target) ;
};

#endif