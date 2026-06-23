// main.cpp —— 主程序
#include <iostream>
#include "point.h"
#include "line.h"

using namespace std;

int main() {

    Point p1(0, 0), p2(3, 4);
    cout << "点 p1: "; p1.show(); cout << endl;
    cout << "点 p2: "; p2.show(); cout << endl;

    Line line(p1, p2);
    line.show();

    return 0;
}
