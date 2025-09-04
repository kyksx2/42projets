/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:01:42 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/21 14:39:17 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(int grade, const std::string &name);
  Bureaucrat(const Bureaucrat &src);
  ~Bureaucrat();

  Bureaucrat &operator=(const Bureaucrat &src);

  std::string getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();
  void signForm(AForm &src);
  void executeForm(AForm const& form) const;

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

private:
  const std::string name;
  int grade;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src);

#endif