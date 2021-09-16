/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agachet <agachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 15:03:09 by agachet           #+#    #+#             */
/*   Updated: 2021/09/15 18:55:03 by agachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account( int initial_deposit )
{
	std::cout << "[19920104_091532] ";
	std::cout <<  "index:" << Account::_nbAccounts  << ";amouts:";
	std::cout << initial_deposit<< ";created" << std::endl;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts++;
	return ;
}

void	Account::displayAccountsInfos()
{
	std::cout << "[19920104_091532] " << "accounts:" << Account::_nbAccounts;
	std::cout << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits;
	std::cout << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::~Account( void)
{
	return ;
}

int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;

