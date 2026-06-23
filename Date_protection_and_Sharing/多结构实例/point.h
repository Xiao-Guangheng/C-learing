// point.h —— 点类声明
#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(double x = 0, double y = 0);
    double getX() const;
    double getY() const;
    void show() const;
private:
    double m_x, m_y;
};

#endif
