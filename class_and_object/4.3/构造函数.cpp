#include<iostream>
using namespace std;

class Clock{
public:
    Clock();  //默认构造函数
    Clock(int newH,int newM,int newS);  //带参数的构造函数
};

Clock::Clock(){
    cout<<"This is the default constructor."<<endl;
}
Clock::Clock(int newH,int newM,int newS){
    cout<<"This is the constructor with parameters."<<endl;
    cout<<"The time is "<<newH<<":"<<newM<<":"<<newS<<endl;
}

int main(){
    Clock clock1;  //调用默认构造函数
    Clock clock2(8,30,30);  //调用带参数的构造函数
    return 0;
}