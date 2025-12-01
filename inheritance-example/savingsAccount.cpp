#include "savingsAccount.h"

#include <iomanip>
#include <iostream>

void savingsAccount::setInterestRate(double interestRate) {
    this->interestRate = interestRate;
}
double savingsAccount::getInterestRate() const {
    return interestRate;
}
void savingsAccount::postInterest() const {
    std::cout << "Your daily interest is: " << std::fixed << std::setprecision(2)
                << "USD " << getAccountBalance() * (interestRate / 100.0 / 365.0) << std::endl;
}
void savingsAccount::withdraw(double amount) {
    double fee;
    if (amount > bankAccount::getAccountBalance()) {
        std::cout << "Not enough balance to withdraw: " << amount << std::endl;
        std::cout << "Your current balance is: " << bankAccount::getAccountBalance() << std::endl;
    } else {
        bankAccount::withdraw(amount);
        std::cout << "Your new balance is " << bankAccount::getAccountBalance();
    } 

}
void savingsAccount::print() const {
    bankAccount::print();
    std::cout << "Interest Rate %: " << getInterestRate() << std::endl;
}
savingsAccount::savingsAccount() = default;
savingsAccount::savingsAccount(int accountNumber, double balance, double interestRate)
    : bankAccount(accountNumber, balance), interestRate(interestRate) {}

