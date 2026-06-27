#include "account.h"
#include <iostream>
#include <cmath>

using namespace std;

double SavingAccount::total = 0;

SavingAccount::SavingAccount(const Date &date, const std::string &id, double rate)
    : id(id), balance(0), rate(rate), lastDate(date), acc(date, 0) {
    date.show();
    cout << "\t#" << id << " created" << endl;
}

void SavingAccount::record(const Date &date, double amount, const std::string &desc) {
    amount = floor(amount * 100 + 0.5) / 100;
    balance += amount;
    total += amount;
    acc.change(date, balance);   // 更新累加器
    lastDate = date;
    cout << "\t#" << id << "\t" << amount << "-" << balance << "-" << desc << "\t" << endl;
}

void SavingAccount::error(const std::string &msg) const {
    cout << "Error(#" << id << ") " << msg << "\t#" << endl;
}

void SavingAccount::deposit(const Date &date, double amount, const std::string &desc) {
    if (amount <= 0) {
        error("Deposit amount must be positive!");
        return;
    }
    record(date, amount, desc);
}

void SavingAccount::withdraw(const Date &date, double amount, const std::string &desc) {
    if (amount > getBalance()) {
        error("Not enough money!");
        return;
    }
    record(date, -amount, desc);
}

void SavingAccount::settle(const Date &date) {
    double interest = acc.getSum(date) * rate / date.distance(Date(date.getYear() - 1, 1, 1));
    if (interest != 0)
        record(date, interest, "interest");
    acc.reset(date, balance);
}

void SavingAccount::show() const {
    cout << id << "\tBalance: " << balance;
}
