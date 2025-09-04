/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:28:58 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/21 10:13:16 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H
#include "AForm.hpp"

class Shrubbery : public AForm {
    public :
    Shrubbery();
    Shrubbery(const Shrubbery& src);
    Shrubbery(const std::string& target);
    ~Shrubbery();
    
    Shrubbery& operator=(const Shrubbery& src);
    void execute(Bureaucrat const& executor) const;

    private :
    std::string target;
};

#endif