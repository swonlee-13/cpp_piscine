#include "Account.hpp"
#include <ctime>
#include <string>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account() {}

Account::Account(int initial_deposit) {
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" 
              << "amount:" << _amount << ";" << "created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";" << "closed"
              << std::endl;
    _nbAccounts--;
    _totalAmount -= _amount;
    _totalNbDeposits -= _nbDeposits;
    _totalNbWithdrawals -= _nbWithdrawals;
}

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}

int     Account::checkAmount(void) const {
    return _amount ;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";" 
              << "total:" << _totalAmount << ";" 
              << "deposits:" << _totalNbDeposits << ";"
              << "withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

void    Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";"
              << "deposit:" << deposit << ";";
    _amount += deposit;
    _nbDeposits++;
    std::cout << "amount:" << _amount << ";"
              << "nb_deposits:" << _nbDeposits
              << std::endl;
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool    Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _amount << ";"
              << "withdrawal:";
    if (withdrawal > _amount){
        std::cout << "refused" << std::endl;
        return false ;
    } else {
        _amount -= withdrawal;
        _totalNbWithdrawals++;
        _nbWithdrawals++;
        _totalAmount -= withdrawal;
        std::cout << withdrawal << ";"
                  << "amount:" << _amount << ";"
                  << "nb_withdrawals:" << _nbWithdrawals << std::endl;
        return true ;
    }
}

void    Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals
              << std::endl;
}

void    Account::_displayTimestamp() {

    std::time_t _time = std::time(NULL);
    std::tm *timeInfo = std::localtime(&_time);
    char buffer[16];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", timeInfo);
    std::string res(buffer);
    std::cout << "[" << res << "] ";
    return ;
}
