/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 10:28:30 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/25 11:40:26 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/AForm.hpp"
#include "./include/Bureaucrat.hpp"
#include "./include/PresidentialPardonForm.hpp"
#include "./include/RobotomyRequestForm.hpp"
#include "./include/ShrubberyCreationForm.hpp"

using namespace std;

int main() {
    srand(std::time(NULL));
    try {
        cout << "--- test Shrubbery ---" << endl;
        Bureaucrat b1(137, "b1");
        Shrubbery s1("target_1");

        s1.beSigned(b1);
        b1.executeForm(s1);
    }
    catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
    }
    try {
        cout << "\n--- test Presidential ---" << endl;
        Bureaucrat b2(5, "b2");
        Presidential p1("target_2");

        p1.beSigned(b2);
        b2.executeForm(p1);
    }
    catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
    }
    try {
        cout << "\n--- test Robotomy 1 ---" << endl;
        Bureaucrat b3(1, "b3");
        Robotomy r1("target_3");

        r1.beSigned(b3);
        b3.executeForm(r1);
    }
    catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
    }
    try {
        cout << "\n--- test Robotomy 2 ---\n" << endl;
        Bureaucrat b4(1, "b4");
        Robotomy r2("target_3");

        r2.beSigned(b4);
        b4.executeForm(r2);
    }
    catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
    }
    try {
        cout << "\n--- test Robotomy 3 ---" << endl;
        Bureaucrat b5(1, "b5");
        Robotomy r3("target_3");

        r3.beSigned(b5);
        b5.executeForm(r3);
    }
    catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
    }
    try {
        cout << "\n--- test Robotomy 4 ---" << endl;
        Bureaucrat b6(1, "b6");
        Robotomy r4("target_3");

        r4.beSigned(b6);
        b6.executeForm(r4);
    }
    catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}