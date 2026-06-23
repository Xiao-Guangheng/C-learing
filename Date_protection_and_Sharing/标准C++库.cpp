//标准C++库

#define PI 3.14

//使用#define 定义符号常量

#undef PI

//#undef  删除#define定义的宏

//条件编译指令

//五种形式

#include <iostream>
using namespace std;

#define DEBUG       // 定义 DEBUG 宏，控制条件编译

// 形式1：#ifdef ... #endif     如果标识符已定义，则编译
#ifdef DEBUG
    const char* MODE = "Debug 模式";
#endif

// 形式2：#ifndef ... #endif    如果标识符未定义，则编译
#ifndef RELEASE
    const char* BUILD = "非 Release 版本";
#endif

// 形式3：#if ... #else ... #endif    根据常量表达式选择编译
#define VERSION 3
#if VERSION >= 3
    const char* VER = "版本 >= 3";
#else
    const char* VER = "旧版本";
#endif

// 形式4：#if ... #elif ... #else ... #endif    多分支条件编译
#define PLATFORM 2          // 1=Windows  2=Linux  3=macOS
#if PLATFORM == 1
    const char* OS = "Windows";
#elif PLATFORM == 2
    const char* OS = "Linux";
#elif PLATFORM == 3
    const char* OS = "macOS";
#else
    const char* OS = "Unknown";
#endif

// 形式5：#ifdef ... #else ... #endif    与形式3类似，但判断的是标识符是否定义
#define FEATURE_X
#ifdef FEATURE_X
    void feature() { cout << "X 功能已启用" << endl; }
#else
    void feature() { cout << "X 功能未启用" << endl; }
#endif


int main() {
    cout << MODE << endl;       // 形式1
    cout << BUILD << endl;      // 形式2
    cout << VER << endl;        // 形式3
    cout << OS << endl;         // 形式4
    feature();                  // 形式5
    return 0;
}

