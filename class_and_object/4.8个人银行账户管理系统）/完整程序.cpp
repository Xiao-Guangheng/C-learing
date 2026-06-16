#include <iostream>
#include <string>
using namespace std;

class SavingsAcount{
private:
    int id;
    double balance;
    double rate;
    int lastDate; // 上次结算日期，格式为 YYYYMMDD
    double accumulation; // 累计金额，用于结算利息

    void record(int date,double amount); // 记录每次存取款的日期和金额
    // 将函数名修改为 accumulate，避免与变量 accumulation 重名
    double accumulate(int date) const {
        return accumulation+balance*(date-lastDate);
    }  //获得到指定日期为止的存款金额按日累计值
public:
    SavingsAcount(): id(0), balance(0.0), rate(0.0) {}  // 默认构造函数
    SavingsAcount(int i, double b, double r): id(i), balance(b), rate(r) {} // 带参数的构造函数

    SavingsAcount( const SavingsAcount& other)
        : id(other.id), balance(other.balance), rate(other.rate) {} // 复制构造函数
    ~SavingsAcount() {} // 析构函数

    int GetId() const { return id; }
    double GetBalance() const { return balance; }
    double GetRate() const { return rate; }

    void show() const;
    void deposit(int date,double amount);
    void withdraw(int date,double amount);
    void settle(int date);
};

void SavingsAcount::record(int date,double amount){
    accumulation=accumulate(date); // 这里调用修改后的函数名
    lastDate=date;
    amount=floor(amount*100+0.5)/100; // 保留两位小数
    balance+=amount;
    cout<<date<<"\t#"<<id<<"\t"<<amount<<"\t"<<balance<<endl;
}
void SavingsAcount::deposit(int date,double amount){
    record(date,amount);
}
void SavingsAcount::withdraw(int date,double amount){
    if (amount >GetBalance()) {
        cout << "Error:not enough money!" << endl;
        return;
    }
    record(date,-amount);
}
void SavingsAcount::settle(int date){
    double interest=accumulate(date)*rate/365; // 这里调用修改后的函数名
    if (interest != 0) {
        record(date,interest);
    }
    accumulation=0;
}

void SavingsAcount::show() const{
    cout<<"#"<<id<<"\tBalance:"<<balance<<"\tRate:"<<rate<<endl;
}

int main(){
    SavingsAcount sa(1001,1000.0,0.015);
    sa.show();
    sa.deposit(20240101,500.0);
    sa.withdraw(20240201,200.0);
    sa.settle(20240301);
    sa.show();
}