/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:42:36 by kjolly            #+#    #+#             */
/*   Updated: 2025/08/27 09:37:50 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

using namespace std;

int main() {
  try {
    cout << "Error try 1: " << endl;
    Bureaucrat t(151, "t");
  } catch (exception &e) {
    cerr << "error: " << e.what() << endl;
  }
  try {
    cout << "\nError try 2: " << endl;
    Bureaucrat t(0, "m");
    cout << "name: " << t.getName() << endl;
  } catch (exception &e) {
    cerr << "error: " << e.what() << endl;
  }
  try {
    cout << "\nGood try: " << endl;
    Bureaucrat t(20, "p");
    cout << "name: " << t.getName() << endl;
    cout << "grade: " << t.getGrade() << endl;
  } catch (exception &e) {
    cerr << "error: " << e.what() << endl;
  }
  try {
    cout << "\ndecrement try: " << endl;
    Bureaucrat t(149, "tt");
    cout << "grade: " << t.getGrade() << endl;
    t.decrementGrade();
    cout << "grade: " << t.getGrade() << endl;
  } catch (exception &e) {
    cerr << "error: " << e.what() << endl;
  }
  try {
    cout << "\nincrement try: " << endl;
    Bureaucrat t(2, "mm");
    cout << "grade: " << t.getGrade() << endl;
    t.incrementGrade();
    cout << "grade: " << t.getGrade() << endl;
  } catch (exception &e) {
    cerr << "error: " << e.what() << endl;
  }
  return 0;
}