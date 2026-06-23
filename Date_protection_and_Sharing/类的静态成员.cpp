// 类的静态成员
// 
// 为什么 count 必须用 static？
//   — 普通成员：每个对象各有一份，互不相干，p1.count 和 p2.count 是两码事
//   — 静态成员：整个类只有一份，所有对象共享，p1 和 p2 看到的是同一个 count
//   要统计"全班有多少人"，必须用共用的计数器（static），不能靠每个人兜里自
//   己的数（普通成员）。
//
// 为什么 count 要放在 private 里？
//   — 如果放在 public，外部可以随便写 Point::count = 0 把数据改乱
//   — 放在 private，只有构造函数(+1)和析构函数(-1)能改，外部只能看不能改
//   — 保证 count 永远等于"当前存活的 Point 对象数量"

#include <iostream>
using namespace std;

class Point {
public:
    Point(int x, int y) : x(x), y(y) { count++; }
    Point(const Point& p) : x(p.x), y(p.y) { count++; }
    ~Point() { count--; }
    int getX() const { return x; }
    int getY() const { return y; }

    void show() const {
        cout << "Point count=" << count << endl;
    }

private:
    int x, y;
    static int count;                     // 所有对象共享一份，放 private 防篡改
    static constexpr int origin = 0;
};

int Point::count = 0;

int main() {
    Point p1(4, 5);
    cout << "p1: (" << p1.getX() << "," << p1.getY() << ")" << endl;
    p1.show();  // count = 1

    Point p2(1, 2);
    cout << "p2: (" << p2.getX() << "," << p2.getY() << ")" << endl;
    p2.show();  // count = 2
    return 0;
}