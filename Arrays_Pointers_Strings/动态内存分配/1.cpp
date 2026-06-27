#include <iostream>
using namespace std;

class Point{
public:
    Point() : x(0), y(0) {
        cout << "Point默认构造" << endl;
    }

    Point(int x, int y) : x(x), y(y) {
        cout << "Point构造(" << x << "," << y << ")" << endl;
    }

    ~Point() {
        cout << "Point析构(" << x << "," << y << ")" << endl;
    }
    int getX() const { return x; }
    int getY() const { return y; }
    void move(int newx, int newy) { x = newx; y = newy; }
private:
    int x, y;
};

class ArrayOfPoints {
public:
    ArrayOfPoints(int size) : size(size) {
        points = new Point[size];
    }

    ArrayOfPoints(const ArrayOfPoints&) = delete; // 禁止拷贝构造

    ~ArrayOfPoints() {
        delete[] points;
    }

    Point& operator[](int i) {
        return points[i];
    }

private:
    Point* points;   // 动态分配的对象数组
    int size;   // 数组大小
};


int main(){

    int count;  //相当于传入的参数，就是size
    cout << "请输入点的个数: ";
    cin >> count;

    ArrayOfPoints arr(count);  //创建一个动态对象数组,
    //这个arr就相当于points，是一个指针，指向动态分配的对象数组
    arr[0].move(1, 2);
    arr[1].move(3, 4);

    return 0;
}