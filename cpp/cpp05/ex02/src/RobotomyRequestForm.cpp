/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:24:56 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/21 10:32:28 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

Robotomy::Robotomy() : AForm("Robotomy", false, 72, 45), target("default") {}

Robotomy::Robotomy(const std::string& tar) : AForm("Robotomy", false, 72, 45), target(tar) {}

Robotomy::Robotomy(const Robotomy& src) {
    *this = src;
}

Robotomy& Robotomy::operator=(const Robotomy& src) {
    if (this != &src) {
        AForm::operator=(src);
        this->target = src.target;
    }
    return *this;
}

Robotomy::~Robotomy() {}

void Robotomy::execute(Bureaucrat const& executor) const {
    if (!this->getSignedAForm()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > this->getgradeSign() ||
        executor.getGrade() > this->getgradeExecute()) {
            throw GradeTooLowException();
        }
    std::cout << "BZZZ...BZZZ...DRIIINGGGGGG" << std::endl;
    int r = std::rand() % 2;
    if (r) {
        std::cout << this->target << "has been robotomized" << std::endl;
    }
    else {
        std::cout << "robotomy failed" << std::endl;        
    }
}
