#include <iostream>
using namespace std;

// 基类：提取共性
class Shape {
protected:
    double x, y;
public:
    Shape(double x = 0, double y = 0) : x(x), y(y) {}
    double getX() const { return x; }
    double getY() const { return y; }
    void move(double dx, double dy) { x += dx; y += dy; }
    virtual double area() const = 0;        // 纯虚函数：强制子类实现
};

// 派生类1：只需写自己独特的部分
class Circle : public Shape {
    double r;
public:
    Circle(double x, double y, double r) : Shape(x, y), r(r) {}
    double area() const { return 3.14 * r * r; }
};

// 派生类2
class Rect : public Shape {
    double w, h;
public:
    Rect(double x, double y, double w, double h) : Shape(x, y), w(w), h(h) {}
    double area() const { return w * h; }
};

int main() {
    Circle c(0, 0, 10);
    Rect   r(5, 5, 4, 6);

    // 统一接口：用基类指针操作不同子类
    Shape* shapes[] = { &c, &r };
    for (auto s : shapes)
        cout << "面积: " << s->area() << endl;

    // 复用基类方法
    c.move(3, 4);
    cout << "圆移动后位置: (" << c.getX() << "," << c.getY() << ")" << endl;
}
