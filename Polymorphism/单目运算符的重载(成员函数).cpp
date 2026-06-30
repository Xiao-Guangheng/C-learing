// 单目运算符的重载 (成员函数形式)
// 单目运算符重载为成员函数时：没有参数（或对于 ++/-- 有一个 int 占位参数区分前后置）

#include <iostream>
using namespace std;

class Counter {
private:
    int value;

public:
    Counter(int v = 0) : value(v) {}

    // 前置 ++ 运算符重载 (++c)
    Counter& operator++() {   //这里就不需要参数了，参数就是它本身。
        ++value;            // 先自增
        return *this;       // 返回自增后的对象本身（引用）
    }

    // 后置 ++ 运算符重载 (c++) —— 多一个 int 占位参数
    Counter operator++(int) {   //这里的int不表示参数，而是为了区分前置和后置的重载函数，后置++需要一个int占位参数
        Counter old = *this;    // 保存旧的对象，为什么要返回一个临时对象？因为后置++返回的是自增前的值，所以需要保存旧值
        ++value;                // 自增
        return old;             // 返回旧值（临时对象，不能返回引用）
    }

    // 前置 -- 运算符重载 (--c)
    Counter& operator--() {
        --value;
        return *this;
    }

    // 后置 -- 运算符重载 (c--)
    Counter operator--(int) {
        Counter old = *this;
        --value;
        return old;
    }

    // 负号 - 运算符重载 (-c)
    Counter operator-() const {
        return Counter(-value);   // 返回负值的临时对象
    }

    // 逻辑非 ! 运算符重载 (!c)
    bool operator!() const {
        return value == 0;        // value 为 0 返回 true
    }

    void display() const {
        cout << value;
    }
};

int main() {
    // ========== 前置 ++ / 后置 ++ ==========
    Counter c1(5);
    cout << "c1 = ";
    c1.display();

    cout << "\n--- 前置 ++c ---" << endl;
    Counter& ref = ++c1;        // 前置++返回引用，ref 就是 c1 本身
    cout << "++c1 = ";
    c1.display();
    cout << ", ref 就是 c1 本身：";
    ref.display();

    cout << "\n\n--- 后置 c++ ---" << endl;
    Counter c2(5);
    Counter old = c2++;         // 后置++返回旧值的临时对象
    cout << "c2++ 返回的旧值 = ";
    old.display();
    cout << "\n自增后的 c2 = ";
    c2.display();

    // ========== 前置 -- / 后置 -- ==========
    Counter c3(10);
    cout << "\n\n--- 前置 --c ---" << endl;
    --c3;
    cout << "--c3 = ";
    c3.display();

    Counter c4(10);
    cout << "\n--- 后置 c-- ---" << endl;
    c4--;
    cout << "c4-- 后 = ";
    c4.display();

    // ========== 负号 - ==========
    Counter c5(8);
    Counter c6 = -c5;
    cout << "\n\n--- 负号运算符 ---" << endl;
    cout << "c5 = ";
    c5.display();
    cout << ", -c5 = ";
    c6.display();

    // ========== 逻辑非 ! ==========
    Counter c7(0);
    Counter c8(3);
    cout << "\n\n--- 逻辑非运算符 ---" << endl;
    cout << "!c7 (c7=0) = " << !c7 << "  (0为真)" << endl;
    cout << "!c8 (c8=3) = " << !c8 << "  (非0为假)" << endl;

    // ========== 前置和后置的区别演示 ==========
    cout << "\n\n--- 前置 vs 后置 经典对比 ---" << endl;
    Counter a(1), b(1);
    cout << "初始化：a=1, b=1" << endl;

    // 前置++
    Counter& result_a = ++a;
    // 后置++
    Counter result_b = b++;

    cout << "++a 表达式的结果 = ";
    result_a.display();
    cout << ", 此时 a = ";
    a.display();

    cout << "\nb++ 表达式的结果 = ";
    result_b.display();
    cout << ", 此时 b = ";
    b.display();

    cout << "\n结论：前置++返回自增后的自身引用；后置++返回自增前的副本" << endl;

    return 0;
}

