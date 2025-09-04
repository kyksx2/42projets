/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:28:40 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/21 12:04:38 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_H
#define AFORM_H
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
  AForm();
  AForm(const std::string name, bool s, const int gs, const int ge);
  AForm(const AForm &src);
  virtual ~AForm();

  AForm &operator=(const AForm &src);

  std::string getname() const;
  bool getSignedAForm() const;
  int getgradeSign() const;
  int getgradeExecute() const;

  void beSigned(Bureaucrat& src);
  virtual void execute(Bureaucrat const& executor) const = 0;
  
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char *what() const throw();
  };
  class FormNotSignedException : public std::exception {
    const char *what() const throw();
  };

private:
  const std::string name;
  bool signedForm;
  const int gradeSign;
  const int gradeExecute;
};

#endif