// line.h —— 线段类声明（由两个 Point 组成）
#ifndef LINE_H
#define LINE_H

#include "point.h"

class Line {
public:
    Line(Point s, Point e);
    double length() const;
    void show() const;
private:
    Point start, end;
};

#endif
