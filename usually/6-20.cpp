#include <iostream>
using namespace std;

class SimpleCircle
{
private:
    double radius;
public:
    SimpleCircle() : radius(0) {}   //默认构造函数，初始化为0
    SimpleCircle(double r) : radius(r) {}   //带参数的构造函数
    SimpleCircle(const SimpleCircle& c) : radius(c.radius) {}  //复制构造函数
    void add(double r) { radius += r; }  //增加半径
    void show() const { cout << "Radius:" << radius << endl; }  //显示半径
};
int main()
{
    SimpleCircle c1,c2(2);
    c1.show();
    c2.show();
    SimpleCircle c3(c2);
    c2.add(10);
    c2.show();
    c3.show();

    return 0;
}