
#include "account.h"
#include <iostream>
#include <cmath>

using namespace std;

double SavingAccount::total = 0;  //初始化静态成员变量，重点**

SavingAccount::SavingAccount(const Date &date,const std::string &id,double rate )
    :id(id),balance(0),rate(rate),lastDate(date),accumulation(0){
    date.show();
    cout<<"\t#"<<id<<" created"<<endl;
}  //对象进行初始化，使用初始化列表，避免调用默认构造函数，减少不必要的开销

void SavingAccount::record(const Date &date, double amount, const std::string &desc){
    accumulation = accumulate(date);  //更新累计利息
    lastDate = date;  //更新最后操作日期
    amount = floor(amount*100+0.5)/100;  //四舍五入到分
    balance += amount;  //更新余额
    total += amount;  //更新总金额
    cout<<"\t#"<<id<<"\t"<<amount<<"-"<<balance<<"-"<<desc<<"\t"<<endl;

}

void SavingAccount::error(const std::string &msg) const{
    cout<<"Error(#"<<id<<") "<<msg<<"\t#"<<endl;
}

void SavingAccount::deposit(const Date &date, double amount, const std::string &desc){
    if (amount <= 0) {
        error("Deposit amount must be positive!");
        return;
    }
    record(date, amount, desc);
}

void SavingAccount::withdraw(const Date &date, double amount, const std::string &desc){
    if (amount >getBalance()) {
        error("Not enough money!");
        return;
    }
    record(date, -amount, desc);
}

void SavingAccount::settle(const Date &date){
    double interest = accumulate(date)*rate/date.distance(Date(date.getYear()-1,1,1));  //计算累计利息
    if (interest != 0   )
        record(date, interest, "interest");
    accumulation = 0;  //清零累计利息
}

