// oj.1.6.cpp
#include<iostream>
using namespace std;

class Date{
public:
    Date():y(2015),m(5),d(20) {}
    Date(int year,int month,int day):y(year),m(month),d(day) {}

    int GetYear(){
        return y;
    }

    int GetMonth(){
        return m;
    }

    int GetDay(){
        return d;
    }

    void Set(int year,int month,int day){
        y=year;
        m=month;
        d=day;
    }
    void Set(){   //重载函数，不带参数，重置为默认日期
        y = 2015;  
        m = 5;
        d = 20;
    }

    void Show(){
        cout<<y<<"-"<<m<<"-"<<d<<endl;
    }
private:
    int y;
    int m;
    int d; 
};

int main()
{
    Date d1;
    cout<<"Show object d1:";
    cout<<d1.GetYear()<<"-"<<d1.GetMonth()<<"-"<<d1.GetDay()<<endl;
    int y,m,d;
    cin>>y>>m>>d;
    Date d2(y,m,d);
    cout<<"Show object d2:";
    cout<<d2.GetYear()<<"-"<<d2.GetMonth()<<"-"<<d2.GetDay()<<endl;
    cin>>y>>m>>d;
    cout<<"Reset and Show object d1:";
    d1.Set(y,m,d);
    d1.Show();
    cout<<"Reset and Show object d2:";
    d2.Set();
    d2.Show();
    return 0;
}