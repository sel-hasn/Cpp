#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
}

Account::Account( int initial_deposit )
{
    this->_accountIndex = getNbAccounts();
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout<<"index:"<<getNbAccounts();
    std::cout<<";amount:"<<initial_deposit;
    std::cout<<";created"<<std::endl;
    Account::_totalAmount += initial_deposit;
    Account::_nbAccounts += 1;
}

Account::~Account( void )
{
    _displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex;
    std::cout<<";amount:"<<this->checkAmount();
    std::cout<<";closed"<<std::endl;
    Account::_nbAccounts -= 1;
}

void	Account::makeDeposit( int deposit )
{
    this->_nbDeposits++;
    _displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex;
    std::cout<<";p_amount:"<<this->checkAmount();
    std::cout<<";deposit:"<<deposit;
    this->_amount += deposit;
    std::cout<<";amount:"<<this->checkAmount();
    std::cout<<";nb_deposits:"<<this->_nbDeposits<<std::endl;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex;
    std::cout<<";p_amount:"<<this->checkAmount();
    if (this->checkAmount() - withdrawal < 0)
    {
        std::cout<<";withdrawal:refused"<<std::endl;
        return (false);
    }
    this->_nbWithdrawals++;
    std::cout<<";withdrawal:"<<withdrawal;
    this->_amount -= withdrawal;
    std::cout<<";amount:"<<this->checkAmount();
    std::cout<<";nb_withdrawals:"<<this->_nbWithdrawals<<std::endl;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;
    return (true);
}


void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout<<"accounts:"<<getNbAccounts();
    std::cout<<";total:"<<getTotalAmount();
    std::cout<<";deposits:"<<getNbDeposits();
    std::cout<<";withdrawals:"<<getNbWithdrawals()<<std::endl;
}

void	Account::_displayTimestamp( void )
{
    time_t rawtime;
    struct tm* timeinfo;
    char buffer[80];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "[%Y%m%d_%H%M%S] ", timeinfo);
    std::cout<<buffer;
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout<<"index:"<<this->_accountIndex;
    std::cout<<";amount:"<<this->checkAmount();
    std::cout<<";deposits:"<<this->_nbDeposits;
    std::cout<<";withdrawals:"<<this->_nbWithdrawals<<std::endl;
}

int	Account::getNbAccounts( void )
{
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (Account::_totalNbWithdrawals);
}
