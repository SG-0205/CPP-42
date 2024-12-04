/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoldenb <sgoldenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:15:14 by sgoldenb          #+#    #+#             */
/*   Updated: 2024/11/01 17:48:10 by sgoldenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <exception>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void){}
Account::Account	(int initial_deposit){
	std::stringstream	log_message;

	if (initial_deposit < 0)
		throw std::invalid_argument("Can't create account with a negative deposit");
	_accountIndex = _nbAccounts;
	_nbAccounts ++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	log_message	<< "index:" << _accountIndex << ';'
				<< "amount:" << _amount << ';'
				<< "created" << std::endl;
	_displayTimestamp();
	std::cout << log_message.str();
}
Account::~Account(void){
	std::stringstream	log_message;

	_totalAmount -= _amount;
	log_message	<< "index:" << _accountIndex << ';'
				<< "amount:" << _amount << ';'
				<< "closed" << std::endl;
	_displayTimestamp();
	std::cout << log_message.str();
	_amount = 0;
}

int	Account::checkAmount(void) const {
	return (_amount);
}
int	Account::getNbAccounts(void){
	return (_nbAccounts);
}
int	Account::getTotalAmount(void){
	return (_totalAmount);
}
int	Account::getNbDeposits(void){
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals(void){
	return (_totalNbWithdrawals);
}
void	Account::_displayTimestamp(void){
	std::time_t			current_time;
	std::tm				*formatted;
	char				timestamp[20];

	std::time(&current_time);
	formatted = std::localtime(&current_time);
	std::strftime(timestamp, 19, "[%Y%m%d_%H%M%S] ", formatted);
	std::cout << timestamp;
}

void	Account::displayAccountsInfos(void) {
	std::stringstream	log_message;

	log_message	<< "accounts:" << getNbAccounts() << ';'
				<< "total:" << getTotalAmount() << ';'
				<< "deposits:" << getNbDeposits() << ';'
				<< "withdrawals:" << getNbWithdrawals() << std::endl;
	_displayTimestamp();
	std::cout << log_message.str();
}

void	Account::displayStatus(void) const {
	std::stringstream	log_message;

	log_message	<< "index:" << _accountIndex << ';'
				<< "amount:" << _amount << ';'
				<< "deposits:" << _nbDeposits << ';'
				<< "withdrawals:" << _nbWithdrawals << std::endl;
	_displayTimestamp();
	std::cout << log_message.str();
}

void	Account::makeDeposit(int deposit){
	int					p_amount;
	std::stringstream	log_message;

	if (deposit < 1)
		throw std::invalid_argument("Can't make a null or negative deposit");
	p_amount = _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits ++;
	_totalNbDeposits ++;
	log_message	<< "index:" << _accountIndex << ';'
			<< "p_amount:" << p_amount << ';'
			<< "deposit:" << deposit << ';'
			<< "amount:" << _amount << ';'
			<< "nb_deposits:" << _nbDeposits << std::endl;
	_displayTimestamp();
	std::cout << log_message.str();
}

bool	Account::makeWithdrawal(int withdrawal){
	int					p_amount;
	std::stringstream	log_message;

	if (withdrawal < 1)
		throw std::invalid_argument("Can't withdraw a null or negative amount");
	p_amount = checkAmount();
	if (withdrawal > p_amount)
	{
		log_message	<< "index:" << _accountIndex << ';'
			<< "p_amount:" << p_amount << ';'
			<< "withdrawal:refused" << std::endl;
		_displayTimestamp();
		std::cout << log_message.str();
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals ++;
	_totalNbWithdrawals ++;
	log_message	<< "index:" << _accountIndex << ';'
			<< "p_amount:" << p_amount << ';'
			<< "withdrawal:" << withdrawal << ';'
			<< "amount:" << _amount << ';'
			<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	_displayTimestamp();
	std::cout << log_message.str();
	return (true);
}
