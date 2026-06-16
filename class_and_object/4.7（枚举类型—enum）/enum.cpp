//enum的作用就是把数字转化为有意义的名字
//便于维护和阅读
//当声明enum时，会自动为每个枚举成员分配一个整数值，默认从0开始递增
//不默认的话可以自己指定枚举成员的值，例如：enum Color { RED = 1, GREEN = 2, BLUE = 4 };

#include <iostream>
using namespace std;

// 1. 传统枚举 (C风格)
enum Day {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY
};

// 2. 强类型枚举 (C++11引入，推荐使用)
enum class TrafficLight {
    RED,    // 默认底层值是 0
    YELLOW, // 1
    GREEN   // 2
};

int main() {
    // 传统枚举问题：作用域泄露
    Day today = MONDAY;
    
    // 强类型枚举优势：作用域明确，类型安全
    TrafficLight light = TrafficLight::GREEN;

    if (light == TrafficLight::GREEN) {
        cout << "绿灯亮起，车辆可以通行！" << endl;
    } else if (light == TrafficLight::RED) {
        cout << "红灯亮起，禁止通行！" << endl;
    }

    return 0;
}
