/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:18:03 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/25 11:45:31 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/AForm.hpp"
#include "./include/Bureaucrat.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/ShrubberyCreationForm.hpp"
#include "./include/Intern.hpp"

using namespace std;

int main() {
    srand(std::time(NULL));
    AForm* gen = NULL;
    try {
        cout << "--- TEST SHRUBBERY ---" << endl;
        Intern randomIntern;
        Bureaucrat b1(15, "b1");

        gen = randomIntern.makeForm("Shrubbery", "t1");
        if (gen) {            
            gen->beSigned(b1);
            b1.executeForm(*gen);
        }
        else
            cerr << "Error: Shrubbery failed" << endl;
        delete(gen);
    }
    catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
        delete(gen);
    }
    try {
        cout << "\n--- TEST PRESIDENTIAL ---" << endl;
        Intern randomInter2;
        Bureaucrat b2(5, "b2");

        gen = randomInter2.makeForm("Presidential", "target_pres");
        if (gen) {
            gen->beSigned(b2);
            b2.executeForm(*gen);            
        }
        else
            cerr << "Error: gens failed" << endl;
        delete(gen);
    }
    catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
        delete(gen);
    }
    try {
        cout << "\n--- TEST ROBOTOMY ---" << endl;
        Intern randomInter3;
        Bureaucrat b3(1, "b3");

        gen = randomInter3.makeForm("Robotomy", "target_rob");
        if (gen){            
            gen->beSigned(b3);
            b3.executeForm(*gen);
        }
        else
            cerr << "Error: gen failed" << endl;
        delete(gen);
    }
    catch (exception &e) {
        delete(gen);
        cerr << "Error: " << e.what() << endl;
    }
    try {
        cout << "\n--- TEST ERROR ---" << endl;
        Intern randomInter4;
        Bureaucrat b3(1, "b3");

        gen = randomInter4.makeForm("error", "target_rob");
        if (gen){            
            gen->beSigned(b3);
            b3.executeForm(*gen);
        }
        else
            cerr << "Error: gen failed" << endl;
        delete(gen);
    }
    catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
        delete gen;
    }
    return 0;
}