// ============================================================
// 复制构造函数.cpp  —— 完整学习笔记
// ============================================================
// 【核心概念】
//   复制构造函数 = 把整个对象的值"传"给新对象
//   本质就是一个传值过程：源对象 → 新对象
//
// 【写法三要素】（缺一不可）
//   const  : 保证源对象不被修改（只读）
//   &      : 引用传递，防止无限递归（若按值传递会反复触发复制构造）
//   other  : 形参名，代表被复制的源对象（业界习惯叫 other 或 rhs）
//
// 【两种定义方式】
//   方式一：函数体赋值（本例使用，适合基本类型）
//   方式二：初始化列表（更推荐，const/引用/子对象必须用它）
//           Point(const Point &other) : x(other.x), y(other.y) {}
//
// 【三种调用时机】
//   ① 用已有对象初始化新对象：Point b(a); 或 Point b = a;
//   ② 函数按值传参：fun(a);  实参→形参
//   ③ 函数按值返回：return obj;  （可能被编译器 RVO 优化掉）
//
// 【默认行为】
//   不写则编译器自动生成，执行逐成员浅拷贝。
//   成员全为基本类型时没问题，有指针成员时需自己写深拷贝。
// ============================================================
#include <iostream>
using namespace std;

class Point {
public:
    // 普通构造函数，用于初始化对象（带默认参数值）
    Point(int xx = 0, int yy = 0) {
        x = xx;
        y = yy;
    }

    // 复制构造函数的声明
    // const Point &other：const(不修改源对象) + &(引用传递防递归) + other(源对象)
    Point(const Point &other);

    int getX() { return x; }
    int getY() { return y; }

private:
    int x;
    int y;
};

// 复制构造函数的定义（函数体赋值方式）
// 进入此函数时：this → 新对象（正在出生），other → 源对象（被复制的）
// other.x 就是把源对象的 x 拿过来，赋给新对象的 x
Point::Point(const Point &other) {
    x = other.x;   // 源对象的值 → 新对象
    y = other.y;
    cout << "This is the copy constructor." << endl;
}

// 调用时机②：函数形参是类的对象（按值传递）
// 调用 fun(a) 时，实参 a 复制给形参 p，触发复制构造函数
void fun(Point p) {
    cout << "x=" << p.getX() << ", y=" << p.getY() << endl;
}

// 调用时机③：函数返回值是类的对象
// return 时把局部对象复制到调用方，触发复制构造函数（可能被编译器优化掉）
Point g() {
    Point a(10, 20);
    return a;
}

int main() {
    Point a(10, 20);       // 普通构造

    Point b = a;           // 调用时机①：初始化（= 不是赋值，是拷贝初始化）
    Point c(a);            // 调用时机①：等价写法，用 a 初始化 c

    fun(a);                // 调用时机②：按值传参

    Point d;
    b = g();               // 调用时机③：函数按值返回

    return 0;
}