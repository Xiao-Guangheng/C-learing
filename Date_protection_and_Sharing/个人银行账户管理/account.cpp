// account.cpp —— 储蓄账户类实现
#include <iostream>
#include <cmath>
#include "account.h"
using namespace std;

double SavingsAccount::total=0;

SavingsAccount::SavingsAccount(int i, double b, double r)
    : id(i), balance(b), rate(r), lastDate(0), accumulation(0) {}

SavingsAccount::~SavingsAccount() {}

void SavingsAccount::record(int date, double amount) {
    accumulation = accumulate(date);
    lastDate = date;
    amount = floor(amount * 100 + 0.5) / 100;   // 保留两位小数
    balance += amount;
    cout << date << "\t#" << id << "\t" << amount << "\t" << balance << endl;
}

void SavingsAccount::deposit(int date, double amount) {
    record(date, amount);
}

void SavingsAccount::withdraw(int date, double amount) {
    if (amount > getBalance()) {
        cout << "Error: not enough money!" << endl;
        return;
    }
    record(date, -amount);
}

void SavingsAccount::settle(int date) {
    double interest = accumulate(date) * rate / 365;
    if (interest != 0) {
        record(date, interest);
    }
    accumulation = 0;
}

void SavingsAccount::show() const {
    cout << "#" << id << "\tBalance: " << balance << "\tRate: " << rate << endl;
}
