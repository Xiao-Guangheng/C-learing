#include<iostream>
using namespace std;

class Clock{
public:
    void setTime(int newH,int newM,int newS);
    void showTime();    
private:
    int hour,minute,second;
};

void Clock::setTime(int newH,int newM,int newS){
    hour=newH;
    minute=newM;
    second=newS;
};

inline void Clock:: showTime(){
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}
