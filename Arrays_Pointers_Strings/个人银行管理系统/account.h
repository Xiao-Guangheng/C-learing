//account.h
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "date.h"
#include <string>

//不写using namespace std;,在头文件里是因为会污染命名空间，导致其他文件也会受到影响。
//所以在给字符串命名的时候会使用std::string，而不是直接使用string。
//因为string是在std里面的，所以如果没有using namespace std;，就必须加上std::前缀。
//如果加上了using namespace std;，就可以直接使用string，而不需要加上std::前缀。

class SavingAccount {
private:
    std::string id;   //账户编号
    double balance;   //账户余额
    double rate;    //利率
    Date lastDate;              // 组合（has-a关系），不是继承
    double accumulation;        // 累计利息
    //这里使用static是因为静态变量表示的是所有对象的共享数据，而不是每个对象都有一份独立的数据。
    static double total;        // 所有账户总金额


    // 这几个函数之所以在私有数据里面，是因为它们是辅助函数，不需要被外部调用。它们的作用是帮助实现账户的操作和计算。
    //也就是说不能被外部调用的就要放在private里面，而能被外部调用的就要放在public里面。


    // 记录账户操作，更新累计利息、最后操作日期、余额和总金额，并输出操作信息
    void record(const Date &date, double amount, const std::string &desc);

    // 输出错误信息，不更新账户信息
    void error(const std::string &msg) const;

    double accumulate(const Date &date) const {
        return accumulation + balance * rate * date.distance(lastDate);
    }  // 计算累计利息
public:
//构造函数，初始化账户编号、余额、利率、最后操作日期和累计利息，并输出账户创建信息
    SavingAccount(const Date &date,const std::string &id,double rate );
//
    const std::string &getId() const { return id; }   //获取账户编号，这里是返回一个常量引用，避免拷贝，提高效率

    double getBalance() const { return balance; }  //获取账户余额

    double getRate() const { return rate; } 

    static double getTotal() { return total; }  //获取所有账户总金额，也是静态函数，不能访问非静态成员变量

    
    void deposit(const Date &date, double amount, const std::string &desc);   //存款，调用record()函数记录操作

    void withdraw(const Date &date, double amount, const std::string &desc);  //取款，调用record()函数记录操作

    void settle(const Date &date);  //    结算利息，调用record()函数记录操作

    void show() const;
};

#endif