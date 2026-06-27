
//对象指针
#include <iostream>
using namespace std;

class Point {

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    void show() {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }

    //this指针
    Point (int x, int y) {
        this->x = x;  // 使用this指针区分成员变量和参数名
        this->y = y;  
     //表示我把传入的参数赋值给了当前对象的成员变量，
     //这个成员变量就是this->x，而后面的x就是传入的参数x
    }
private:
    int x, y;
};

int Point ::*px = &Point::x;  // 成员指针，指向类Point的成员变量x  ,这个x 是类的成员变量x，而不是对象的成员变量x
int Point ::*py = &Point::y;  // 成员指针，指向类Point的成员变量y

void (Point::*pShow)() = &Point::show;  // 成员函数指针，指向类Point的成员函数show

Point p5(5, 6);
Point *p6 = &p5;  // 指针指向对象p5

p5.*px = 10;  // 使用成员指针访问对象p5的成员变量x
p5.*py = 20;  // 使用成员指针访问对象p5的成员变量y

int main(){
    Point *p;
    Point pt(3, 4);
    p = &pt;  // 将对象的地址赋给指针

    Point a(1,2);
    Point *p1 = &a;  // 指针指向对象a

    Point *p3= Point(7, 8);  // 错误，不能将临时对象的地址赋给指针
    Point *p4 = new Point[3];  // 正确，动态分配对象数组

    p->show();

    //this指针

    //参数名和变量名相同的时候才需要使用this指针来区分
}