// 析构函数.cpp
#include <iostream>
using namespace std;

// 完成对象被删除之前的一些清理工作，在对象的生存周期即将结束的时刻被启动调用的。

// 没有返回值，不接受任何参数

class Clock{
public:
    Clock();  //默认构造函数
    Clock(int newH,int newM,int newS);  //带参数的构造函数
    ~Clock();  //析构函数
private:
    int hour,minute,second;
};

