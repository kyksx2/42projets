/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:24:45 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/21 14:46:27 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

Shrubbery::Shrubbery() : AForm("Shruberry", false, 145, 137), target("default") {}

Shrubbery::Shrubbery(const Shrubbery& src) {
    *this = src;
}

Shrubbery::Shrubbery(const std::string& tar) : AForm("Shruberry", false, 145, 137), target(tar) {}

Shrubbery& Shrubbery::operator=(const Shrubbery& src) {
    if (this != &src) {
        AForm::operator=(src);
        this->target = src.target;
    }
    return *this;
}

Shrubbery::~Shrubbery() {}

void Shrubbery::execute(Bureaucrat const& executor) const {
    if (!this->getSignedAForm()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > this->getgradeSign() ||
        executor.getGrade() > this->getgradeExecute()) {
        throw GradeTooLowException();
    }
    std::ofstream file((this->target +"_shrubbery").c_str());
    if (!file) {
        std::cerr << "Error: cannot open outfile" << std::endl;
        return ;
    }
    file << "       _-_\n";
    file << "    /~~   ~~\\\n";
    file << " /~~         ~~\\\n";
    file << "{               }\n";
    file << " \\  _-     -_  /\n";
    file << "   ~  \\\\ //  ~\n";
    file << "_- -   | | _- _\n";
    file << "  _ -  | |   -_\n";
    file << "      // \\\\\n";
    file.close();
}
