// 运算符重载为非成员函数（友元函数）
// 当左操作数不是本类对象时，必须使用非成员函数形式

#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i";
        else
            cout << real << " - " << -imag << "i";
    }

    double getReal() const { return real; }
    double getImag() const { return imag; }

    // 声明友元函数（非成员函数可以访问私有成员）
    //为什么要使用友元函数而不是直接使用全局函数？因为友元函数可以访问类的私有成员，而全局函数不能直接访问类的私有成员。
    //其实就是因为如果想要访问对象的私有成员，就需要使用友元函数，而不是全局函数。
    //不管是左操作数还是右操作数，想要访问对象的私有成员，就需要使用友元函数，而不是全局函数。
    friend Complex operator+(const Complex& c1, const Complex& c2);  //没有this指针，不能还使用隐式表示
    //这里的两个操作数还都是Complex类型的对象，所以可以使用友元函数来访问它们的私有成员。
    friend Complex operator+(double d, const Complex& c);  //表示一个double类型的左操作数和一个Complex类型的右操作数
    friend Complex operator+(const Complex& c, double d);  //表示一个左操作数为Complexx的对象，右操作数为一个double类型的数据

    // << 原本是位左移运算符（如 1<<3 = 8），C++标准库将其重载为"流插入运算符"
    // 用于把数据插入输出流：cout << 42; 这里再次重载，让 << 能输出 Complex 对象
    friend ostream& operator<<(ostream& os, const Complex& c);  // 重载 << 为输出运算符

    // >> 原本是位右移运算符（如 8>>2 = 2），C++标准库将其重载为"流提取运算符"
    // 用于从输入流提取数据：cin >> x; 这里再次重载，让 >> 能读入 Complex 对象
    friend istream& operator>>(istream& is, Complex& c);        // 重载 >> 为输入运算符

    // ========== 单目运算符重载（非成员函数/友元） ==========
    friend Complex operator-(const Complex& c);        // 一元负号：-c
    friend bool operator!(const Complex& c);           // 逻辑非：!c（判断是否为零）
    friend Complex& operator++(Complex& c);            // 前置 ++c
    friend Complex operator++(Complex& c, int);        // 后置 c++
    friend Complex& operator--(Complex& c);            // 前置 --c
    friend Complex operator--(Complex& c, int);        // 后置 c--
};

// ========== 非成员函数（友元）—— 两个都是参数 ==========

// Complex + Complex
Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}  //实现：这里不需要加friend关键字，因为它已经在类中声明为友元函数了。
//如果要使用的时候，只需要直接调用即可，不需要加friend关键字。

// double + Complex（左操作数是 double，不是 Complex！）
Complex operator+(double d, const Complex& c) {
    return Complex(d + c.real, c.imag);
}

// Complex + double（虽然可以写成成员函数，但为了对称也写成非成员）
Complex operator+(const Complex& c, double d) {
    return Complex(c.real + d, c.imag);
}

// 重载 << （左操作数是 ostream，更不可能是本类对象）
ostream& operator<<(ostream& os, const Complex& c) {
    if (c.imag >= 0)
        os << c.real << " + " << c.imag << "i";
    else
        os << c.real << " - " << -c.imag << "i";
    return os;
}

// 重载 >> （左操作数是 istream）
istream& operator>>(istream& is, Complex& c) {
    cout << "输入实部和虚部: ";
    is >> c.real >> c.imag;
    return is;
}

// ========== 单目运算符重载（非成员函数/友元） ==========

// 一元负号：-c → 返回实部和虚部都取反的新对象
Complex operator-(const Complex& c) {
    return Complex(-c.real, -c.imag);
}

// 逻辑非：!c → 当实部和虚部都为零时返回 true
bool operator!(const Complex& c) {
    return (c.real == 0 && c.imag == 0);
}

// 前置 ++c → 实部和虚部分别 +1，返回自增后的引用
Complex& operator++(Complex& c) {
    c.real += 1;
    c.imag += 1;
    return c;
}

// 后置 c++ → 返回自增前的副本，实部和虚部分别 +1
Complex operator++(Complex& c, int) {
    Complex temp(c);  // 保存原值
    c.real += 1;
    c.imag += 1;
    return temp;      // 返回原值
}

// 前置 --c → 实部和虚部分别 -1，返回自减后的引用
Complex& operator--(Complex& c) {
    c.real -= 1;
    c.imag -= 1;
    return c;
}

// 后置 c-- → 返回自减前的副本，实部和虚部分别 -1
Complex operator--(Complex& c, int) {
    Complex temp(c);
    c.real -= 1;
    c.imag -= 1;
    return temp;
}

// ========== 非友元的非成员函数（只通过公有接口访问） ==========
// 如果不希望破坏封装，也可以通过公有 getter/setter 实现，不需要友元

bool operator==(const Complex& c1, const Complex& c2) {
    return (c1.getReal() == c2.getReal()) && (c1.getImag() == c2.getImag());
}

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    // 1. Complex + Complex
    Complex c3 = c1 + c2;
    cout << "c1 + c2 = " << c3 << endl;

    // 2. double + Complex（左操作数是 double）
    Complex c4 = 5.0 + c1;
    cout << "5.0 + c1 = " << c4 << endl;

    // 3. Complex + double
    Complex c5 = c1 + 10.0;
    cout << "c1 + 10.0 = " << c5 << endl;

    // 4. 链式混合运算
    Complex c6 = c1 + c2 + 5.0;
    cout << "c1 + c2 + 5.0 = " << c6 << endl;

    // 5. 比较运算符
    Complex c7(3, 4);
    cout << boolalpha;
    cout << "c1 == c2 : " << (c1 == c2) << endl;
    cout << "c1 == c7 : " << (c1 == c7) << endl;

    // 6. 输入输出
    Complex c8;
    cin >> c8;
    cout << "你输入的是: " << c8 << endl;

    // ==================== 7. 单目运算符测试 ====================
    cout << "\n========== 单目运算符测试 ==========" << endl;

    // 一元负号
    Complex c9(5, -3);
    cout << "c9 = " << c9 << endl;
    cout << "-c9 = " << (-c9) << endl;

    // 逻辑非
    Complex c10(0, 0);
    Complex c11(1, 0);
    cout << "!c10 (0+0i) = " << !c10 << endl;
    cout << "!c11 (1+0i) = " << !c11 << endl;

    // 前置 ++
    Complex c12(2, 3);
    cout << "c12 初始值 = " << c12 << endl;
    cout << "++c12 = " << (++c12) << endl;
    cout << "自增后 c12 = " << c12 << endl;

    // 后置 ++
    Complex c13(2, 3);
    cout << "\nc13 初始值 = " << c13 << endl;
    cout << "c13++ = " << (c13++) << endl;
    cout << "自增后 c13 = " << c13 << endl;

    // 前置 --
    Complex c14(5, 5);
    cout << "\nc14 初始值 = " << c14 << endl;
    cout << "--c14 = " << (--c14) << endl;
    cout << "自减后 c14 = " << c14 << endl;

    // 后置 --
    Complex c15(5, 5);
    cout << "\nc15 初始值 = " << c15 << endl;
    cout << "c15-- = " << (c15--) << endl;
    cout << "自减后 c15 = " << c15 << endl;

    return 0;
}

