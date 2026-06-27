#include <iostream>
using namespace std;

class A {
public:
    int data;
    A(int x = 0) : data(x) { cout << "① A 构造: " << data << endl; }
};

class B : virtual public A {
public:
    B(int x) : A(x) { cout << "② B 构造" << endl; }
};

class C : virtual public A {
public:
    C(int x) : A(x) { cout << "③ C 构造" << endl; }
};

class D : public B, public C {
public:
    D(int x) : A(x), B(x + 1), C(x + 2) {
        cout << "④ D 构造   data=" << data << "（来自 D 的 A(100)，B/C 传给 A 的值被忽略）" << endl;
    }
    void show() { cout << "A::data = " << data << endl; }
};

int main() {
    cout << "===== 创建 D 对象 =====" << endl;
    D obj(100);
    cout << "B 和 C 里传给 A 的值被忽略了，只有 D 传的 A(100) 生效" << endl;
    obj.show();
    return 0;
}
