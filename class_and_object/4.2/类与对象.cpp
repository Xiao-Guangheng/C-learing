// 类与对象.cpp
#include <iostream>
using namespace std;

class Clock {
public:
    void setTime(int newH, int newM, int newS);  // 声明
    void showTime();                             // 显示时间
// public:
    // void setTime(int newH=0, int newM=0, int newS=0);  
// 使用默认形参值的成员函数声明  
private:
    int hour, minute, second;
};

// 类外定义 setTime 函数（用 :: 作用域解析符）
// 类的成员函数需要用类名约束
void Clock::setTime(int newH, int newM, int newS) {
    hour = newH;      // 可以访问 private 成员
    minute = newM;
    second = newS;
}

void Clock::showTime() {
    cout << hour << ":" << minute << ":" << second << endl;
}

int main() {
    Clock myClock;
    
    // 因为是 public，所以外部可以调用
    myClock.setTime(14, 30, 25);   // ✅ 设置时间为 14:30:25
    myClock.showTime();             // 输出：14:30:25
    
    // myClock.hour = 10;           // ❌ 错误！private 成员不可外部访问
}

