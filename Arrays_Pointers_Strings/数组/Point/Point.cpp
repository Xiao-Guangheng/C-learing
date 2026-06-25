//Point.cpp

#include <iostream>
#include "Point.h"
using namespace std;

// 静态成员定义
int Point::count = 0;

// 默认构造函数
Point::Point() : x(0), y(0) {
    count++;
    cout << "Default constructor called" << endl;
}

// 带参构造函数
Point::Point(int x, int y) : x(x), y(y) {
    count++;
    cout << "Constructor called" << endl;
}

Point::~Point() {
    count--;
    cout << "Destructor called" << endl;
}

void Point::move(int dx, int dy) {
    cout << "Moving the point by (" << dx << ", " << dy << ")" << endl;
    x += dx;
    y += dy;
}

void Point::showCount() {
    cout << "Current count: " << count << endl;
}
