// 类的友元

//在类外，但是与类有特殊关系的函数或类，可以访问类的私有成员和保护成员，这种函数或类称为友元。

//使用类的组合可以实现友元的功能，但是比较复杂，如果需要多次使用就不方便了

//通过友元函数，一个普通函数或者类的成员函数可以访问封装于另外一个类中数据，
//这样来看，友元是对数据隐蔽和封装的破坏，但是为了数据共享，这种破坏是有必要的

//友元函数是类中用关键字friend修饰的非成员函数


#include <iostream>
#include <cmath>
using namespace std;

class Point{

public:
    Point(int x=0,int y=0):x(x),y(y){}
    int getX() {return x;}
    int getY() {return y;}

    friend float dist(Point &p1,Point &p2);  //友元函数的声明
private:
    int x,y;
};

float dist (Point &p1,Point &p2){
    double x=p1.x-p2.x;
    double y=p1.y-p2.y;
    return static_cast<float>(sqrt(x*x+y*y0));
}

int main(){
    Point myp1(1,1),myp2(4,5);
    cout<<dist(myp1,myp2)<<endl;
    return 0;
}