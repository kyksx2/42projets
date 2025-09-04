/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:24:51 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/21 15:23:50 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
  if (grade > 150)
    throw GradeTooLowException();
  else if (grade < 1)
    throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : name(src.name), grade(src.grade) {}

Bureaucrat::Bureaucrat(int grade, const std::string &name)
    : name(name), grade(grade) {
  if (grade > 150)
    throw GradeTooLowException();
  else if (grade < 1)
    throw GradeTooHighException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
  if (this != &src) {
    this->grade = src.getGrade();
  }
  return (*this);
}

std::string Bureaucrat::getName() const { return this->name; }

int Bureaucrat::getGrade() const { return this->grade; }

void Bureaucrat::incrementGrade() {
  if (this->grade == 1) {
    throw GradeTooHighException();
  } else
    this->grade--;
}

void Bureaucrat::decrementGrade() {
  if (this->grade == 150) {
    throw GradeTooLowException();
  } else
    this->grade++;
}

void Bureaucrat::signForm(AForm& src) {
  try {
    src.beSigned(*this);
    std::cout << this->name << " signed " << src.getname() << std::endl;
  }
  catch (std::exception& e) {
    std::cerr << this->name << " couldn't sign " << src.getname() << " because "<< e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const& form) const {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getname() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << this->getName() << " coudn't execute form because "
        << e.what() << std::endl;
    }
}


const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Bureaurat grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Bureaucrat grade too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src) {
  os << src.getName() << ", bureaucrat grade " << src.getGrade() << "."
     << std::endl;
  return os;
}
