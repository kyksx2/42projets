/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:24:48 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/23 16:22:36 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm()
    : name("default"), signedForm(false), gradeSign(150), gradeExecute(150) {
      if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
      if (gradeSign > 150 || gradeExecute > 150)
        throw GradeTooLowException();
    }

AForm::AForm(const std::string name, bool s, const int gs, const int ge)
    : name(name), signedForm(s), gradeSign(gs), gradeExecute(ge) {
      if (gs < 1 || ge < 1)
        throw GradeTooHighException();
      if (gs > 150 || ge > 150)
        throw GradeTooLowException();
    }

AForm::AForm(const AForm &src)
    : name(src.name), signedForm(src.signedForm), gradeSign(src.gradeSign),
      gradeExecute(src.gradeExecute) {
        
      }

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &src) {
  if (this != &src) {
    signedForm = src.getSignedAForm();
  }
  return (*this);
}

void AForm::beSigned(Bureaucrat &src) {
  if (signedForm == true) {
    std::cout << "Form already signed!" << std::endl;
    return;
  }
  if (src.getGrade() > this->gradeSign)
    throw GradeTooLowException();
  signedForm = true;
}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Form grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Form grade too low!";
}

const char *AForm::FormNotSignedException::what() const throw() {
  return "Form not signed!";
}

std::string AForm::getname() const { return this->name; }

bool AForm::getSignedAForm() const { return this->signedForm; }

int AForm::getgradeSign() const { return this->gradeSign; }

int AForm::getgradeExecute() const { return this->gradeExecute; }

std::ostream &operator<<(std::ostream &os, const AForm &src) {
  os << "Form: " << src.getname() << std::endl
     << "signed: " << src.getSignedAForm() << std::endl
     << "grade required to sign it: " << src.getgradeSign() << std::endl
     << "grade required to execute it: " << src.getgradeExecute() << std::endl;
  return os;
}
