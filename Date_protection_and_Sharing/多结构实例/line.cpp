// line.cpp —— 线段类实现
#include <iostream>
#include <cmath>
#include "line.h"
using namespace std;

Line::Line(Point s, Point e) : start(s), end(e) {}

double Line::length() const {
    double dx = end.getX() - start.getX();
    double dy = end.getY() - start.getY();
    return sqrt(dx * dx + dy * dy);
}

void Line::show() const {
    cout << "线段: ";
    start.show();
    cout << " -> ";
    end.show();
    cout << "  长度 = " << length() << endl;
}
