#include <iostream>
#include <string>
using namespace std;

class Base1{
public:
    Base1(int i){
        cout<<"Base1 构造 i="<<i<<endl;
    }
};

class Base2{
public:
    Base2(int i){
        cout<<"Base2 构造 i="<<i<<endl;
    }
};

class Base3{
public:
    Base3(int i){
        cout<<"Base3 构造 i="<<i<<endl;
    }
};

class Derived: public Base2, public Base1, public Base3{
public:
    Derived(int a,int b,int c,int d)
        : Base1(a), Base2(d), m1(c), m2(b), m3(a), Base3(b) { }
private:
    Base1 m1;
    Base2 m2;
    Base3 m3;
};

int main() {
    cout << "===== 创建 Derived 对象 =====" << endl;
    Derived obj(1, 2, 3, 4);
    // 声明顺序：        Base2  →  Base1  →  Base3  →  m1  →  m2  →  m3
    // 初始化列表写的是： Base1(a), Base2(d), m1(c), Base3(b)
    // 实际执行顺序永远是声明顺序！
    return 0;
}