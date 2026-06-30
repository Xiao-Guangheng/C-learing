// 纯虚函数.cpp
// 纯虚函数是没有实现的虚函数，必须在派生类中被重写

#include <iostream>
using namespace std;

// 抽象基类：形状
// 包含纯虚函数，不能实例化
class Shape {
public:
    // 纯虚函数：计算面积
    virtual double area() const = 0;

    // 普通成员函数
    void showArea() const {
        cout << "面积 = " << area() << endl;
    }
};

// 派生类：圆形
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    // 必须重写纯虚函数
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

// 派生类：矩形
class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}

    // 必须重写纯虚函数
    double area() const override {
        return width * height;
    }
};

int main() {
    // Shape s;            // 错误！抽象类不能实例化
    // Shape* p = new Shape; // 错误！

    Circle c(5.0);
    Rectangle r(3.0, 4.0);

    // 通过基类指针调用，实现多态
    Shape* shapes[2] = { &c, &r };

    for (int i = 0; i < 2; i++) {
        shapes[i]->showArea();
    }

    return 0;
}
