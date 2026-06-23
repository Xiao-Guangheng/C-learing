// account.h —— 储蓄账户类定义
#ifndef ACCOUNT_H
#define ACCOUNT_H

class SavingsAccount {
private:
    int id;
    double balance;
    double rate;
    int lastDate;           // 上次结算日期，格式为 YYYYMMDD
    double accumulation;    // 累计金额，用于结算利息
    static double total;
    void record(int date, double amount);   // 记录每次存取款的日期和金额
    double accumulate(int date) const {     // 获得到指定日期为止的存款金额按日累计值
        return accumulation + balance * (date - lastDate);
    }
public:
    SavingsAccount(int i, double b, double r);
    ~SavingsAccount();

    int getId() const { return id; }
    double getBalance() const { return balance; }
    double getRate() const { return rate; }

    static double getTotal(){ return total;}

    void show() const;
    void deposit(int date, double amount);
    void withdraw(int date, double amount);
    void settle(int date);
};

#endif
