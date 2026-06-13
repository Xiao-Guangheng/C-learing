#include <iostream>
using namespace std;

class Point{
public:
    Point():x(10),y(16){}  // 默认构造函数

    // 带参构造函数：p2(20,100)
    Point(int x, int y) : x(x), y(y) {}


    void Show() const {
    cout << "(" << x << "," << y << ")";
    }
    void Set(int newx, int newy){
        x = newx;
        y = newy;
    }
private:
    int x;
    int y;
};