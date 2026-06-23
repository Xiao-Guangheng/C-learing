// point.cpp —— 点类实现
#include <iostream>
#include "point.h"
using namespace std;

Point::Point(double x, double y) : m_x(x), m_y(y) {}

double Point::getX() const { return m_x; }

double Point::getY() const { return m_y; }

void Point::show() const {
    cout << "(" << m_x << ", " << m_y << ")";
}
