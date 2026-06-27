#include <iostream>
using namespace std;

class Base1 {
public:
    int var = 10;
    void fun() { cout << "Base1::fun()  var=" << var << endl; }
};

class Base2 {
public:
    int var = 20;
    void fun() { cout << "Base2::fun()  var=" << var << endl; }
};

class Derived : public Base1, public Base2 {
public:
    int var = 30;
    void fun() { cout << "Derived::fun()  var=" << var << endl; }
};

int main() {
    Derived obj;

    obj.var = 100;
    obj.fun();

    obj.Base1::var = 200;
    obj.Base1::fun();

    obj.Base2::var = 300;
    obj.Base2::fun();

    return 0;
}
