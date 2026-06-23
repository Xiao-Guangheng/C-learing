#include<iostream>
using namespace std;

class Figure {
protected:
    double x, y;
public:
    void set_dim(double i, double j = 0) {
        x = i; 
        y = j; 
    }
    virtual void show_area() {
        cout << "No area computation defined for this class.\n";
    }
};

class Triangle : public Figure {
public:
    void show_area() {
        cout << "Triangle with height " << x << " and base " << y;
        cout << " has an area of " << x * 0.5 * y << endl;
    }
};

class Square : public Figure {
public:
    void show_area() {
        cout << "Rectangle with dimensions " << x << " and " << y;
        cout << " has an area of " << x * y << endl;
    }
};

class Circle : public Figure {
public:
    void show_area() {
        cout << "Circle with radius " << x;
        cout << " has an area of " << 3.14159 * x * x << endl;
    }
};

int main() {
    Figure *p;
    Triangle t;
    Square s;
    Circle c;
    
    p = &t;
    p->set_dim(10.0, 5.0);
    p->show_area();
    
    p = &s;
    p->set_dim(10.0, 5.0);
    p->show_area();  // 原代码错误写成了 set_area()
    
    p = &c;
    p->set_dim(10.0);
    p->show_area();
    
    return 0;
}