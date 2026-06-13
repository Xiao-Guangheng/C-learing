// oj.1.10.cpp
#include<iostream>
#include<iomanip>
using namespace std;

//你提交的代码在这里
class Fixed_Deposit{
public:
    Fixed_Deposit():amount(10000.00),rate(3.30),year(1){};
    Fixed_Deposit(double amount,double rate,int year){
        this->amount=amount;
        this->rate=rate*100;
        this->year=year;
        }
    double GetRate(){
        return rate/100;
    }
    double GetAmount(){
        return amount;
    }
    int GetYears(){
        return year;
    }
    double GetAll(){
        return amount * (1 + (rate /100)* year);  
    }
    void Set(double amount,double rate,int year){
        this->amount=amount;
        this->rate=rate*100;
        this->year=year;
    }
    void Show(){
        cout<<"amount="<<amount;        //输出存款本金
        cout<<"  rate="<<rate<<"%"; //输出存款利率
        cout<<"  years="<<year;        //输出存款年数
        cout<<"  total="<<GetAll()<<endl;    //输出到期本息合计
    }
private:
    double amount;
    int year;
    double rate;
};
int main()
{
    cout<<fixed<<setprecision(2);
    Fixed_Deposit f1;
    cout<<"Show object f1:"<<endl;
    cout<<"amount="<<f1.GetAmount();        //输出存款本金
    cout<<"  rate="<<f1.GetRate()*100<<"%"; //输出存款利率
    cout<<"  years="<<f1.GetYears();        //输出存款年数
    cout<<"  total="<<f1.GetAll()<<endl;    //输出到期本息合计
    double amount,rate;
    int years;
    cin>>amount>>rate>>years;
    Fixed_Deposit f2(amount,rate,years);
    cout<<"Show object f2:"<<endl;
    cout<<"amount="<<f2.GetAmount();        //输出存款本金
    cout<<"  rate="<<f2.GetRate()*100<<"%"; //输出存款利率
    cout<<"  years="<<f2.GetYears();        //输出存款年数
    cout<<"  total="<<f2.GetAll()<<endl;    //输出到期本息合计
    cin>>amount>>rate>>years;
    cout<<"Reset and Show object f1:"<<endl;
    f1.Set(amount,rate,years);
    f1.Show();
    return 0;
}
