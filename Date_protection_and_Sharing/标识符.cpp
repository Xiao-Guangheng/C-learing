// 标识符的作用域示例
#include <iostream>
using namespace std;

// 1. 全局作用域 (Global Scope)
// 定义在所有函数之外，整个文件都可以通过 ::myVar 访问它
int myVar = 10;

// 2. 命名空间作用域 (Namespace Scope)
// 包含在命名空间中，通过 MySpace::myVar 访问
namespace MySpace {
    int myVar = 20;
}

// 3. 类作用域 (Class Scope)
// 包含在类中，如果是静态变量通过 MyClass::myVar 访问
class MyClass {
public:
    static int myVar; 
};
int MyClass::myVar = 30; // 静态变量的初始化

int main() {
    // 4. 局部作用域 (Local Scope)
    // 定义在函数内部，只要在这个函数里就有效，且会“遮蔽”外面的同名全局变量
    int myVar = 40;

    cout << "--- 同名标识符(myVar)在不同作用域互不干扰 ---" << endl;

    // 5. 块（语句）作用域 (Block Scope)
    // 仅在这一对花括号 { } 内部有效
    {
        int myVar = 50; 
        cout << "块作用域的值:   " << myVar << "  (离得最近的生效)" << endl;
    } // 出了这个大括号，块里面的 myVar 就消失了

    // 分别调用各个作用域里叫 "myVar" 的变量：
    cout << "局部作用域的值: " << myVar << "  (当前函数里的)" << endl;             
    cout << "类作用域的值:   " << MyClass::myVar << "  (类里的)" << endl;    
    cout << "命名空间的值:   " << MySpace::myVar << "  (命名空间里的)" << endl;    
    cout << "全局作用域的值: " << ::myVar << "  (全局的，用 :: 来专门访问全局)" << endl;           

    return 0;
}


//三种
//函数原型作用域（函数声明的时候，不包含定义）
//局部作用域（在一个函数的定义里面）
//类作用域（在类的定义里面）
//命名空间作用域（在命名空间的定义里面）
//全局变量，文件作用域

//命名空间作用域定义了实体所属的空间，命名空间使用namespace作为关键词。

