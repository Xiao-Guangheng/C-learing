//运算符重载为成员函数

//重载为成员函数就能自由访问本类的数据或成员。

//所以在实际使用的时候就是通过类的对象来访问重载的运算符


//双目运算符的重载：左操作数是对象本身数据，由this指针来访问，右操作数需要通过运算符重载函数的参数表来传递

#include <iostream>
using namespace std;

class Complex {
private:
    double real;   // 实部
    double imag;   // 虚部

public:
    // 构造函数
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // 重载双目运算符 "+" (成员函数形式)
    Complex operator+(const Complex& other) const {          
         //基本形式就是类名 operator 运算符名（const 类名& other）const
         //const修饰的是左操作数，即this指针指向的对象，保证不会修改左操作数的数据成员
         //传进去的参数就是对象，如果左操作数不是对象本身，或者是另一个类的对象，那么就需要使用友元函数来重载运算符
        return Complex(real + other.real, imag + other.imag);  
        //这里的real和imag是左操作数的成员变量，other.real和other.imag是右操作数的成员变量
        //为什么会自动直到这里的real就是this->real呢？因为这里的real是成员函数的成员变量，成员函数可以直接访问类的成员变量，所以这里的real就是this->real
        //这个对象相当于隐形的传递给了成员函数，所以成员函数可以直接访问类的成员变量
    }

    // 重载双目运算符 "-" (成员函数形式)
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // 重载双目运算符 "*" (成员函数形式)
    Complex operator*(const Complex& other) const {
        // (a+bi)(c+di) = (ac - bd) + (ad + bc)i
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    // 重载双目运算符 "==" (成员函数形式)
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imag == other.imag);
    }

    // 重载双目运算符 "!=" (成员函数形式)
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // 显示复数
    void display() const {
        if (imag >= 0)
            cout << real << " + " << imag << "i" << endl;
        else
            cout << real << " - " << -imag << "i" << endl;
    }
};

int main() {
    Complex c1(3.0, 4.0);   // 3 + 4i
    Complex c2(1.0, 2.0);   // 1 + 2i

    cout << "c1 = ";
    c1.display();
    cout << "c2 = ";
    c2.display();
//在使用重载的运算符的时候，要加上类名，
    // 使用重载后的 "+" 运算符
    Complex c3 = c1 + c2;
    cout << "c1 + c2 = ";
    c3.display();

    // 使用重载后的 "-" 运算符
    Complex c4 = c1 - c2;
    cout << "c1 - c2 = ";
    c4.display();

    // 使用重载后的 "*" 运算符
    Complex c5 = c1 * c2;
    cout << "c1 * c2 = ";
    c5.display();

    // 使用重载后的 "==" 运算符
    cout << boolalpha;
    cout << "c1 == c2 : " << (c1 == c2) << endl;

    // 链式运算: (c1 + c2) - c1
    Complex c6 = c1 + c2 - c1;
    cout << "(c1 + c2) - c1 = ";
    c6.display();

    return 0;
}

