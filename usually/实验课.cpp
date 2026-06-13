//point.h
#ifndef _POINT_H_
#define _POINT_H_

class Point{
protected:
    int x,y;
public:
    Point();
    Point(double x,double y);
    double Area() const;
    void Show() const;
    double GetX() const;
    double GetY() const;
};

#endif  //_POINT_H_
//point.cpp
#include "point.h"
#include <iostream>
using namespace std;

Point::Point(){
    x=0;
    y=0;
}
Point::Point(double x,double y){
    this->x=x;
    this->y=y;
}
double Point::Area() const{
    return 0;
}
void Point::Show() const{
    cout<<"x="<<x<<" "<<y="<<y<<endl;
}

double Point::GetX() const{
    return x;
}
double Point::GetY() const{
    return y;
}

//line.h
#ifndef _LINE_H_
#define _LINE_H_
#include "point.h"

class Line{
private:
    Point start,end;
public:
    Line();
    Line(Point start,Point end);
    double Area() const;
    void Show() const;
};

#endif  //_LINE_H_

//line.cpp
#include "line.h"
#include <iostream>
#include <cmath>
using namespace std;

Line::Line(){}
Line::Line(double xv1,double yv1,double xv2,double yv2):start(xv1,yv1),end(xv2,yv2){}

double Line::GetLength() const{
    double dx=end.GetX()-start.GetX();
    double dy=end.GetY()-start.GetY();
    return sqrt(dx*dx+dy*dy);
}
double Line::Area() const{
    return 0;
}
void Line::Show() const{
    cout<<"Start Point: ";
    start.Show();
    cout<<"End Point: ";
    end.Show();
}

//circle.h
#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include "point.h"

class Circle :public Point{
private:
    double radius;
public:
    Circle();
    Circle(double x,double y,double r);
    Circle(const Circle &cir);
    double Area() const;
    void Show() const;
};

#endif  //_CIRCLE_H_

//circle.cpp
#include "circle.h"
#include <iostream>
#include <cmath>
using namespace std;

const double PI=3.14159;

Circle::Circle():radius(0){}
Circle::Circle(double x,double y,double r):Point(x,y){
    radius=r;
}
Circle::Circle(const Circle &cir):Point(cir){
    radius=cir.radius;
}

double Circle::Area() const{
    return PI*radius*radius;
}
void Circle::Show() const{
    Point::Show();
    cout<<"Radius: "<<radius<<endl;
}

#include "point.h"
#include "line.h"
#include "circle.h"
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    Point pt(0,0);
    Circle c11(100,100,10),c12(c11);
    Line ln1(0,0,100,100),ln2;

    cout<<pt.Area()<<"\t";
    pt.Show();

    cout<<c11.Area()<<"\t";
    c11.Show();
    cout<<c12.Area()<<"\t";
    c12.Show();

    cout<<ln1.Area()<<"\t";
        <<ln1.GetLength()<<endl;
    ln1.Show();
    cout<<ln2.Area()<<"\t";
    ln2.Show();

    return 0;
}