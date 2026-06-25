//Point.h
#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point();
    Point(int x, int y);
    ~Point();
    void move(int newx, int newy);
    int getX() const{ return x; }
    int getY() const{ return y; }

    static void showCount();
private:
    int x, y;
    static int count;
};
#endif