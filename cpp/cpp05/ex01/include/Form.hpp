/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:42:22 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/02 12:02:32 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
#define FORM_H
#include <iostream>

class Bureaucrat;

class Form {
public:
  Form();
  Form(const std::string name, bool s, const int gs, const int ge);
  Form(const Form &src);
  ~Form();

  Form &operator=(const Form &src);

  std::string getname() const;
  bool getSignedForm() const;
  int getgradeSign() const;
  int getgradeExecute() const;

  void beSigned(Bureaucrat& src);
  
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
    const char *what() const throw();
  };

private:
  const std::string name;
  bool signedForm;
  const int gradeSign;
  const int gradeExecute;
};

std::ostream &operator<<(std::ostream &os, const Form &src);

#endif