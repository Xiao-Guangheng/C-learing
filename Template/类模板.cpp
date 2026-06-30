#include <iostream>
#include <stdexcept>
using namespace std;

// ============================================================
// 示例1：最简单的类模板 —— Pair（存储两个值）
// ============================================================
template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(const T1& a, const T2& b) : first(a), second(b) {}

    T1 getFirst()  const { return first; }
    T2 getSecond() const { return second; }

    void setFirst(const T1& a)  { first = a; }
    void setSecond(const T2& b) { second = b; }

    void display() const {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

// ============================================================
// 示例2：容器类模板 —— Stack（栈）
// ============================================================
template <typename T, int SIZE = 100>   // 模板参数不仅可以是类型，还可以是常量
class Stack {
private:
    T data[SIZE];
    int top;          // 栈顶下标，-1 表示空
public:
    Stack() : top(-1) {}

    void push(const T& value) {
        if (top >= SIZE - 1)
            throw overflow_error("栈已满！");
        data[++top] = value;
    }

    T pop() {
        if (top < 0)
            throw underflow_error("栈已空！");
        return data[top--];
    }

    bool empty() const { return top == -1; }

    int size() const { return top + 1; }
};

// ============================================================
int main() {
    // ---- 使用 Pair ----
    cout << "=== Pair 示例 ===" << endl;

    Pair<int, double> p1(10, 3.14);
    p1.display();                           // (10, 3.14)

    Pair<string, int> p2("张三", 20);       // 类型组合完全自由
    p2.display();                           // (张三, 20)

    // ---- 使用 Stack ----
    cout << "\n=== Stack 示例 ===" << endl;

    Stack<int, 10> s;                       // 栈容量为 10
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "栈内元素个数: " << s.size() << endl;   // 3

    while (!s.empty())
        cout << "弹出: " << s.pop() << endl;         // 3, 2, 1

    return 0;
}
