// 移动构造函数.cpp

#include <iostream>
using namespace std;

int makeValue() {
	return 99;
}

int main() {
	int x = 10;

	// 你的理解：一个 & 是左值引用，必须绑定左值（有名字的对象）
	int& lr = x; // OK: x 是左值

	// 你的理解：两个 && 是右值引用，必须绑定右值（临时值，比如 19）
	int&& rr1 = 19;         // OK: 19 是右值
	int&& rr2 = x + 1;      // OK: 表达式结果是右值
	int&& rr3 = makeValue(); // OK: 返回临时值是右值

	// 注意：有名字的变量永远是左值，即使它类型是 T&&
	rr1 = 20; // rr1 作为表达式是左值

    // int && re=x; // 错误：x 是左值，不能绑定到右值引用
    // int &fd = x*x; // 错误：x*x 是右值，不能绑定到左值引用

    //move函数可以将左值对象移动为右值并绑定右值引用
    int a=1;
    int && r = std::move(a); // 将 a 移动为右值并绑定到 r

    
	cout << lr << " " << rr1 << " " << rr2 << " " << rr3 << endl;
	return 0;
}

