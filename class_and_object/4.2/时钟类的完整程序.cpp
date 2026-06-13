#include <iostream>
using namespace std;

class Clock{
public:
    void setTime(int newH=0,int newM=0,int newS=0);
    void showTime();
private:
    int hour,minute,second;
};

// 定义setTime成员函数
void Clock::setTime(int newH,int newM,int newS){
    hour=newH;
    minute=newM;
    second=newS;
}

// 定义showTime成员函数
inline void Clock:: showTime(){
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}


// 主函数

int main(){
    Clock myClock;
    cout<<"First time set and output::"<<endl;
    myClock.setTime();
    myClock.showTime();
    cout<<"Second time set and output::"<<endl;
    myClock.setTime(8,30,30);
    myClock.showTime();
    return 0;
}