/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:42:25 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/19 10:15:44 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include "../include/Bureaucrat.hpp"

Form::Form()
    : name("default"), signedForm(false), gradeSign(150), gradeExecute(150) {
      if (gradeSign < 1 || gradeExecute < 1)
        throw GradeTooHighException();
      if (gradeSign > 150 || gradeExecute > 150)
        throw GradeTooLowException();
    }

Form::Form(const std::string name, bool s, const int gs, const int ge)
    : name(name), signedForm(s), gradeSign(gs), gradeExecute(ge) {
      if (gs < 1 || ge < 1)
        throw GradeTooHighException();
      if (gs > 150 || ge > 150)
        throw GradeTooLowException();
    }

Form::Form(const Form &src)
    : name(src.name), signedForm(src.signedForm), gradeSign(src.gradeSign),
      gradeExecute(src.gradeExecute) {
        
      }

Form::~Form() {}

Form &Form::operator=(const Form &src) {
  if (this != &src) {
    signedForm = src.getSignedForm();
  }
  return (*this);
}

void Form::beSigned(Bureaucrat &src) {
  if (signedForm == true) {
    std::cout << "Form already signed!" << std::endl;
    return;
  }
  if (src.getGrade() > this->gradeSign)
    throw GradeTooLowException();
  signedForm = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Form grade too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Form grade too low!";
}

std::string Form::getname() const { return this->name; }

bool Form::getSignedForm() const { return this->signedForm; }

int Form::getgradeSign() const { return this->gradeSign; }

int Form::getgradeExecute() const { return this->gradeExecute; }

std::ostream &operator<<(std::ostream &os, const Form &src) {
  os << "Form: " << src.getname() << std::endl
     << "signed: " << src.getSignedForm() << std::endl
     << "grade required to sign it: " << src.getgradeSign() << std::endl
     << "grade required to execute it: " << src.getgradeExecute() << std::endl;
  return os;
}
