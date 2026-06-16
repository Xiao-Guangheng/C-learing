// 前向引用声明

#include <iostream>
#include <string>
using namespace std;

class B; // 前向引用声明

class A {
public:
    void showB(B& b); // 只能声明，B 还没定义完
};

class B {
public:
    void show() { cout << "我是 B" << endl; } 
};

void A::showB(B& b) { // B 定义完了，这里可以用了
    b.show();
}

int main() {
    A a;
    B b;
    a.showB(b);
    return 0;
}
