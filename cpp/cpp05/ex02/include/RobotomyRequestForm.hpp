/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:28:53 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/21 14:41:02 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class Robotomy : public AForm {
    public :
    Robotomy();
    Robotomy(const Robotomy& src);
    Robotomy(const std::string& target);
    ~Robotomy();
    
    Robotomy& operator=(const Robotomy& src);
    void execute(Bureaucrat const& executor) const;

    private :
    std::string target;
};

#endif