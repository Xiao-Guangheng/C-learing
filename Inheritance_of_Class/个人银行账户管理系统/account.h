//account.h
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "date.h"
#include "accumulator.h"
#include <string>

class SavingAccount {
private:
    std::string id;              // 账户编号
    double balance;              // 余额
    double rate;                 // 利率
    Date lastDate;               // 上次操作日期
    Accumulator acc;             // 累计利息累加器
    static double total;         // 所有账户总金额

    void record(const Date &date, double amount, const std::string &desc);

    void error(const std::string &msg) const;

public:
    SavingAccount(const Date &date, const std::string &id, double rate);

    const std::string &getId() const { return id; }

    double getBalance() const { return balance; }

    double getRate() const { return rate; }

    static double getTotal() { return total; }

    void deposit(const Date &date, double amount, const std::string &desc);

    void withdraw(const Date &date, double amount, const std::string &desc);

    void settle(const Date &date);

    void show() const;
};

#endif