//静态函数成员

//静态函数成员可以直接访问该类的静态数据和函数成员，而访问非静态成员必须通过对象名

#include <iostream>
using namespace std;
class A{
public:
    static void f(A a);
private :
    int x;

};

void A::f(A a){
    cout<<x;   //这个是错误的用法
    cout<<a.x;  //正确的用法，通过对象访问非静态成员
}



//具有静态数据的，函数成员的Point类

#include  <iostream>
using namespace std;

class Point {
public:
    Point(int x=0, int y=0) : x(x), y(y) { count++; }
    Point(const Point& p) : x(p.x), y(p.y) { count++; }
    ~Point() { count--; }
    int getX() const { return x; }
    int getY() const { return y; }
    static void show() {
        cout << "Point count=" << count << endl;
    }
private:
    int x, y;
    static int count;
};

int Point::count=0; //静态数据成员声明，用于记录点的个数

int main(){

    Point p1(4, 5);
    cout << "p1: (" << p1.getX() << "," << p1.getY() << ")" << endl;
    Point::show();  // count = 1

    Point p2(1, 2);
    cout << "p2: (" << p2.getX() << "," << p2.getY() << ")" << endl;
    Point::show();  // count = 2
    return 0;
}

//使用静态成员函数好处是可以不用依赖于任何对象，直接访问静态数据。