// 派生类的析构函数
#include <iostream>
using namespace std;

class Base1 {
public:
    Base1(int i) { cout << "Base1 构造 i=" << i << endl; }
    ~Base1()      { cout << "Base1 析构" << endl; }
};

class Base2 {
public:
    Base2(int i) { cout << "Base2 构造 i=" << i << endl; }
    ~Base2()      { cout << "Base2 析构" << endl; }
};

class Base3 {
public:
    Base3(int i) { cout << "Base3 构造 i=" << i << endl; }
    ~Base3()      { cout << "Base3 析构" << endl; }
};

class Derived : public Base2, public Base1, public Base3 {
private:
    Base1 m1;
    Base2 m2;
    Base3 m3;
public:
    Derived(int a, int b, int c, int d)
        : Base1(a), Base2(d), m1(c), m2(b), m3(a), Base3(b) {
        cout << "Derived 构造" << endl;
    }
    ~Derived() { cout << "Derived 析构" << endl; }
};

int main() {
    cout << "===== 创建 =====" << endl;
    Derived obj(1, 2, 3, 4);
    cout << "===== 即将离开作用域 =====" << endl;
    return 0;
}