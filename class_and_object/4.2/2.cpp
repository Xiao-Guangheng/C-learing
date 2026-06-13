// 内连函数成员
// 两种声明方式隐式声明，显式声明

// 显式声明，把函数体放在类外面
#include <iostream>
using namespace std;

class Clock {
public:
    void setTime(int newH, int newM, int newS);  // 隐式声明
    void showTime(){
        cout << hour << ":" << minute << ":" << second << endl;
    }                          
private:
    int hour, minute, second;
};

// 显式声明，把函数体放在类外面，并使用 inline 关键字
inline void Clock::setTime(int newH, int newM, int newS) {
    hour = newH;      
    minute = newM;
    second = newS;
}