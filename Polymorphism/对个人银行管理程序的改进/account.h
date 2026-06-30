// account.h
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "date.h"
#include "accumulator.h"
#include <string>

// 账户基类
class Account { 
private:
    std::string id;      // 账号
    double balance;      // 余额
    static double total; // 所有账户的总金额
protected:
    Account(const Date &date, const std::string &id); // 供派生类调用的构造函数
    void record(const Date &date, double amount, const std::string &desc); // 记录一笔账
    void error(const std::string &msg) const; // 报告错误信息
public:
    const std::string &getId() const { return id; }
    double getBalance() const { return balance; }
    static double getTotal() { return total; }
    
    virtual void deposit(const Date &date, double amount, const std::string &desc) = 0; // 存入
    virtual void withdraw(const Date &date, double amount, const std::string &desc) = 0; // 取出
    virtual void settle(const Date &date) = 0; // 结算利息
    virtual void show() const; // 显示信息
    virtual ~Account() {} // 虚析构函数

    //为什么这都变成了虚函数呢,
    //因为这个类是一个抽象类,它的派生类有两个,一个是储蓄账户类,一个是信用账户类,
    //这两个类都有自己的存款和取款方法,所以父类的存款和取款方法就必须是虚函数
};

// 储蓄账户类
class SavingsAccount : public Account {
private:
    Accumulator acc;    // 累计利息累加器
    double rate;        // 利率
public:
    SavingsAccount(const Date &date, const std::string &id, double rate);
    double getRate() const { return rate; }
    virtual void deposit(const Date &date, double amount, const std::string &desc);
    virtual void withdraw(const Date &date, double amount, const std::string &desc);
    virtual void settle(const Date &date);
};

// 信用账户类
class CreditAccount : public Account {
private:
    Accumulator acc;    // 信用额度累加器（用于计息）
    double credit;      // 信用额度
    double rate;        // 日利率
    double fee;         // 年费
    
    double getDebt() const {
        double balance = getBalance();
        return (balance < 0 ? balance : 0);
    }
public:
    CreditAccount(const Date &date, const std::string &id, double credit, double rate, double fee);
    double getCredit() const { return credit; }
    double getRate() const { return rate; }
    double getFee() const { return fee; }
    virtual void deposit(const Date &date, double amount, const std::string &desc);
    virtual void withdraw(const Date &date, double amount, const std::string &desc);
    virtual void settle(const Date &date);
    virtual void show() const;
};

#endif // __ACCOUNT_H__