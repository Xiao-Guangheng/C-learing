#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

// ===================================================================
// 模板参数的三种形式：
//   ① 类型参数        template<typename T>
//   ② 非类型参数       template<typename T, int N>      ← 传"值"
//   ③ 模板模板参数     template<template<typename> class Container>  ← 传"模板名"
// ===================================================================

// -------------------------------------------------------
// ② 非类型参数：把 int、enum 等当作模板参数
//    N 不是类型，是一个编译期常量
// -------------------------------------------------------
template <typename T, int N>
class Array {
    T data[N];
public:
    int size() const { return N; }                    // N 直接当作数据成员

    T& operator[](int i) {
        if (i < 0 || i >= N) throw out_of_range("越界");
        return data[i];
    }
};

// -------------------------------------------------------
// ③ 模板模板参数：把"类模板名"当作参数传入
//    Container 本身是一个模板，而非具体类型
// -------------------------------------------------------
template <typename T>
class MyContainer {
    T* data;
    int sz;
public:
    MyContainer() : data(nullptr), sz(0) {}
    void push_back(const T&) { sz++; }
    int  size() const { return sz; }
};

// ★ 重点：template<typename> class Container
//   Container 是一个"只接受1个类型参数的类模板名"
template <typename T,template<typename> class Container>  
        //Container 是一个模板模板参数,作为模板，并不是一个具体的类型
class Wrapper {
    Container<T> c;          // 用传入的模板 + T 来实例化，就是用传入的模板来创建一个具体类型，一个对象
public:
    void add(const T& v)  { c.push_back(v); }
    int  count() const    { return c.size(); }
};


// ===================================================================
int main() {
    cout << "===== ② 非类型参数 =====" << endl;
    Array<int, 3> a3;
    Array<int, 8> a8;
    cout << "Array<int, 3> 大小: " << a3.size() << endl;  // 3
    cout << "Array<int, 8> 大小: " << a8.size() << endl;  // 8

    a3[0] = 100;
    cout << "a3[0] = " << a3[0] << endl;

    cout << "\n===== ③ 模板模板参数 =====" << endl;
    Wrapper<int, MyContainer> w;
    w.add(1);
    w.add(2);
    cout << "Wrapper<int, MyContainer> 元素数: " << w.count() << endl;

    // 也可以用标准库的模板（注意 C++17 后 vector 有两个模板参数，此处简化）
    // Wrapper<int, vector> w2;   // 需要适配

    return 0;
}
