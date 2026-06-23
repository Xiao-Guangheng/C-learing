// 最常用的编译预处理指令（多文件结构）

// ──── 模拟头文件 math_utils.h ────
#ifndef MATH_UTILS_H          // 1. #ifndef / #define / #endif  头文件保护，防止重复包含
#define MATH_UTILS_H

#define PI 3.14159            // 2. #define  定义宏常量
#define SQUARE(x) ((x)*(x))   // 2. #define  定义带参宏（宏函数）

inline double circleArea(double r) { return PI * SQUARE(r); }

#endif  // MATH_UTILS_H

// ──── 模拟头文件 config.h ────
#pragma once                  // 3. #pragma once  另一种头文件保护（更简洁，非标准但主流编译器都支持）

#define VERSION 2
#define DEBUG_MODE            // 控制条件编译

// ──── 4. 条件编译：调试/发布切换 ────
#ifdef DEBUG_MODE
    #define LOG(msg) std::cout << "[DEBUG] " << msg << std::endl
#else
    #define LOG(msg)          // 发布版：LOG 展开为空
#endif

// ──── 5. #if / #elif / #else / #endif  多分支条件编译（跨平台） ────
#define PLATFORM 1            // 1=Windows  2=Linux  3=macOS
#if PLATFORM == 1
    #define PLATFORM_NAME "Windows"
#elif PLATFORM == 2
    #define PLATFORM_NAME "Linux"
#elif PLATFORM == 3
    #define PLATFORM_NAME "macOS"
#else
    #error "不支持的平台！"    // 6. #error  编译时产生错误并终止
#endif

// ──── 7. #pragma  编译器特定指令 ────
#pragma message("正在编译平台: " PLATFORM_NAME)   // 编译时输出消息

// ──── 8. #undef  取消宏定义 ────
#undef VERSION                // VERSION 不再可用

// ──── 测试主程序 ────
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "平台: " << PLATFORM_NAME << endl;

    LOG("程序启动");          // 调试宏

    double r = 3.0;
    cout << "圆面积(r=3): " << circleArea(r) << endl;

    LOG("程序结束");
    return 0;
}