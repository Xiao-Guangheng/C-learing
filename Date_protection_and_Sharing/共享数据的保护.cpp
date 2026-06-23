//共享数据的保护

//常对象，常成员函数

//const A a(3,4);   常对象
//const int i=10;   常量
//void print() const;  常成员函数
//static const int origin=0;  静态常成员

//常引用

#include <iostream>
#include <string>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    int getX() const { return x; }  // 常成员函数，保证不修改对象状态
    int getY() const { return y; }
    void setXY(int a, int b) { x = a; y = b; }
    void display() const { cout << "(" << x << ", " << y << ")"; }
};

// 常引用作函数参数：既能避免拷贝开销，又能保护实参不被修改
void showPoint(const Point& p) {    // p 是常引用
    cout << "坐标: ";
    p.display();                    // ✅ OK: display() 是常成员函数
    // p.setXY(10, 20);             // ❌ 错误! 常引用不能调用非常成员函数
}

// 常引用用于返回对象，避免拷贝且防止外部修改
const Point& getMidpoint(const Point& a, const Point& b) {
    static Point mid;               // 静态局部变量，返回引用安全
    int mx = (a.getX() + b.getX()) / 2;
    int my = (a.getY() + b.getY()) / 2;
    mid.setXY(mx, my);
    return mid;                     // 返回常引用，外部不能修改
}

// 常引用绑定临时对象，延长其生命周期
void demoConstRef() {
    const Point& ref = Point(100, 200);  // 常引用绑定右值（临时对象）
    ref.display();                       // ✅ 可以访问
    // ref.setXY(1, 2);                  // ❌ 不能修改
    cout << "  <- 常引用绑定的临时对象" << endl;
}

int main() {
    Point p1(3, 4), p2(9, 8);
    
    showPoint(p1);                     // 传对象，常引用接收
    cout << endl;
    
    const Point& mid = getMidpoint(p1, p2);
    cout << "中点: ";
    mid.display();                     // ✅ 可以访问常引用
    // mid.setXY(0, 0);                // ❌ 不能通过常引用修改
    cout << endl;
    
    demoConstRef();
    
    return 0;
}