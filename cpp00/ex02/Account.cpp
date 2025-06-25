/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjolly <kjolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:48:27 by kjolly            #+#    #+#             */
/*   Updated: 2025/06/20 14:32:38 by kjolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
  _totalAmount += initial_deposit;
  _accountIndex = _nbAccounts;
  _amount = initial_deposit;
  _nbDeposits = 0;
  _nbWithdrawals = 0;

  std::cout << "[";
  Account::_displayTimestamp();
  std::cout << "] ";
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";created\n";
  _nbAccounts++;
}

Account::~Account() {
  std::cout << "[";
  Account::_displayTimestamp();
  std::cout << "] ";
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";closed\n";
}

int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount(void) { return _totalAmount; }
int Account::getNbDeposits(void) { return _totalNbDeposits; }
int Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void Account::displayAccountsInfos(void) {
  std::cout << "[";
  Account::_displayTimestamp();
  std::cout << "] ";
  std::cout << "accounts:" << _nbAccounts << ";";
  std::cout << "total:" << _totalAmount << ";";
  std::cout << "deposits:" << _totalNbDeposits << ";";
  std::cout << "withdrawals:" << _totalNbWithdrawals << "\n";
}

void Account::makeDeposit(int deposit) {
  _nbDeposits++;
  _totalNbDeposits++;
  std::cout << "[";
  Account::_displayTimestamp();
  std::cout << "] ";
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "p_amount:" << _amount << ";";
  _amount += deposit;
  _totalAmount += deposit;
  std::cout << "deposit:" << deposit << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "deposit:" << _nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal) {
  if (checkAmount() < withdrawal) {
    std::cout << "[";
    Account::_displayTimestamp();
    std::cout << "] ";
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "withdrawal:refused\n";
    return false;
  }
    std::cout << "[";
    Account::_displayTimestamp();
    std::cout << "] ";
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << _amount << ";";
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << "nb_withdrawals:" << _nbWithdrawals << "\n";
    return true;
}

int Account::checkAmount(void) const { return _amount; }

void Account::displayStatus(void) const {
  std::cout << "[";
  Account::_displayTimestamp();
  std::cout << "] ";
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "deposit:" << _nbDeposits << ";";
  std::cout << "withdrawals:" << _nbWithdrawals << "\n";
}

void Account::_displayTimestamp(void) {
    time_t tp = time(NULL);
    
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localtime(&tp));
    std::cout << buffer;
}
