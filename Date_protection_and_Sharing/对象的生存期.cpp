//对象的生存期

//静态生存期，动态生存期
//静态生存期：在程序运行期间一直存在，直到程序结束才销毁：使用static关键词，并不会随着每次函数调用而产生一个副本，也不会随着函数的返回而失效
//也就是说，当下一个函数返回后，下一次再调用时，该变量还会保持上一个个值，即使发生了递归调用，也不会为该变量创建副本

// ===== 时钟程序（静态/动态生存期 + 四种作用域）=====
#include <iostream>
using std::cout;
using std::endl;

int fileVar = 0;               // 文件作用域

class Clock {
public:
    static int count;           // 类作用域

    Clock(int h, int m, int s) : hour(h), min(m), sec(s) { fileVar++; count++; }

    void tick() {
        sec++;
        if (sec == 60) { sec = 0; min++; }
        if (min == 60) { min = 0; hour++; }
        if (hour == 24) { hour = 0; }
    }

    void show() const {
        cout << hour << ":" << min << ":" << sec;
    }

private:
    int hour, min, sec;         // 局部作用域（类内）
};
int Clock::count = 0;

void run(Clock c);              // 函数原型作用域：c 只在这行有效

void run(Clock c) {             // 这里的 c 是局部作用域
    static Clock sc(0, 0, 0);   // 静态局部：只创建一次，值一直保留
    c.tick();
    sc.tick();

    cout << "本地时钟："; c.show(); cout << endl;
    cout << "全局计数（类）：" << Clock::count << endl;
    cout << "全局计数（文件）：" << fileVar << endl;
}

int main() {
    Clock c1(10, 30, 0);        // 局部作用域
    Clock c2(10, 30, 0);

    cout << "===== 第1次 =====" << endl;
    run(c1);

    cout << "\n===== 第2次 =====" << endl;
    run(c2);

    return 0;
}