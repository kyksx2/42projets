/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:28:21 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/21 10:13:28 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H
#include "AForm.hpp"

class Presidential : public AForm {
    public :
    Presidential();
    Presidential(const Presidential& src);
    Presidential(const std::string& target);
    ~Presidential();
    
    Presidential& operator=(const Presidential& src);
    void execute(Bureaucrat const& executor) const;

    private :
    std::string target;
};

#endif