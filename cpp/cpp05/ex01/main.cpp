/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:44:27 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/27 09:41:29 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/Bureaucrat.hpp"
#include "./include/Form.hpp"

using namespace std;

int main() {
    cout << "---- f1 ----" << endl;
    try {
        Form f("f1", false, 15, 15);
        cout << f;
        Bureaucrat b1(12, "b1");
        cout << b1;
    }
    catch (exception& e) {
        cout << "error " << e.what() << endl;
    }
    cout << "---- f2 ----" << endl;
    try {
        Form f2("f2", false, 15, 12);
        Bureaucrat b2(12, "b2");
        b2.signForm(f2);
    }
    catch (exception& e) {
        cout << "error: " << e.what() << endl;
    }
    cout << "---- f3 ----" << endl;
    try {
        Form f3("f3",false, 1, 1);
        Bureaucrat b3(150, "b3");
        b3.signForm(f3);
    }
    catch (exception& e) {
        cout << "error: " << e.what() << endl;
    }
    return (0);
}