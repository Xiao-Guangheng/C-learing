// 动态内存分配 —— new 和 delete 以及动态对象数组
#include <iostream>
using namespace std;

class Point {
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

    inline void show() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }

private:
    int x, y;
};

void demo_basic() {

    cout << "--- 3. 动态数组（大小运行时决定）---" << endl;
    int n;
    cout << "请输入数组大小: ";
    cin >> n;
    int* arr = new int[n];           // n 在运行时才确定！
    for (int i = 0; i < n; i++) arr[i] = i;
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    delete[] arr;
}

//============================================================
// 二、动态对象数组
//============================================================
void demo_obj_array() {
    cout << "--- 动态对象数组 ---" << endl;

    int n;
    cout << "请输入对象个数: ";
    cin >> n;
    Point* arr = new Point[n];       // n 运行时决定
    for (int i = 0; i < n; i++) {
        arr[i].show();
    }
    delete[] arr;
}

//============================================================
// 三、new/delete 与 new[]/delete[] 必须配对
//============================================================
void demo_pitfall() {
    cout << "--- 常见错误 ---" << endl;
    cout << "new 配 delete, new[] 配 delete[]" << endl;
    cout << "配错会导致：部分对象未析构（内存泄漏）或程序崩溃" << endl;

    int* p = new int(10);
    delete p;
    p = nullptr;  // 好习惯

    Point* q = new Point(3, 4);
    delete q;
}

//============================================================
// 主函数
//============================================================
int main() {
    demo_basic();
    cout << endl;
    demo_obj_array();
    cout << endl;
    demo_pitfall();

    return 0;
}
