#include "Account.hpp"
#include <time.h>
#include <iostream>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

int Account::getNbAccounts(void)
{
	return(_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return(_totalAmount);
}

int Account::getNbDeposits(void)
{
	return(_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return(_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals() << std::endl; 
}

Account::Account(int initial_deposit)
{
	_accountIndex = Account::_nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_totalAmount += _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount << ";created" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;

	_totalAmount += deposit;
	_amount += deposit;
	_nbDeposits++;
	Account::_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";p_amount:" << p_amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";p_amount:" << _amount;
	
	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount << ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	char time_str[18];
	time_t temp;
	struct tm *timeptr;

	temp = time(NULL);
	timeptr = localtime(&temp);
	strftime(time_str, sizeof(time_str), "[%Y%m%d_%H%M%S]", timeptr);
	std::cout << time_str;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount << ";closed" << std::endl;
}