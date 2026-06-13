// default,delete函数.cpp
#include<iostream>
using namespace std;

class Mystr{
public:
    Mystr() = default;  // 使用默认构造函数
    ~Mystr() = default;  // 使用默认析构函数
    Mystr(const std::string& _s) : s(_s) {} // 带参数的构造函数
    Mystr(const Mystr& A) = default;  // 使用默认复制构造函数
    Mystr(Mystr &&str) = default;  // 使用默认移动构造函数


    Mystr(const Mystr&) = delete;  // 删除拷贝构造函数
    Mystr& operator=(const Mystr&) = delete;  // 删除拷贝赋值运算符

private:
    string s;

};