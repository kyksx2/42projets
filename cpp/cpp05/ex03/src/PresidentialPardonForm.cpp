/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:24:53 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/21 11:38:34 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

Presidential::Presidential() : AForm("Presidential", false, 25, 5), target("default") {}

Presidential::Presidential(const Presidential& src) {
    *this = src;
}

Presidential::Presidential(const std::string& tar) : AForm("Presidential", false, 25, 5), target(tar) {}

Presidential& Presidential::operator=(const Presidential& src) {
    if (this != &src) {
        AForm::operator=(src);
        this->target = src.target;
    }
    return *this;
}

Presidential::~Presidential() {}

void Presidential::execute(Bureaucrat const& executor) const {
    if (!this->getSignedAForm())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getgradeSign() ||
        executor.getGrade() > this->getgradeExecute())
        throw GradeTooLowException();
    std::cout << "Deer people, " << this->target << " has been pardonned by Zaphod Beeblebox" << std::endl;
}
