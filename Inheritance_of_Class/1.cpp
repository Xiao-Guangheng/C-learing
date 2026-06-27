// 简单继承示例
#include <iostream>
#include <string>
using namespace std;

// ============ 基类（父类）============
class Animal {
protected:                   // protected：自己能访问，派生类也能访问
    string name;
    int age;

public:
    Animal(string n = "无名", int a = 0) : name(n), age(a) {
        cout << "【Animal 构造】" << name << endl;
    }

    ~Animal() {
        cout << "【Animal 析构】" << name << endl;
    }

    void eat() const {       // 所有动物都能吃
        cout << name << " 正在吃东西" << endl;
    }

    void sleep() const {     // 所有动物都能睡
        cout << name << " 正在睡觉" << endl;
    }
};

// ============ 派生类（子类）============
class Dog : public Animal {  // ← 继承语法：class 子类 : 继承方式 父类
private:
    string breed;            // 狗独有的：品种

public:
    Dog(string n = "旺财", int a = 0, string b = "土狗")
        : Animal(n, a), breed(b) {        // ← 调用父类构造函数
        cout << "【Dog 构造】" << name << " 品种:" << breed << endl;
    }

    ~Dog() {
        cout << "【Dog 析构】" << name << endl;
    }

    void bark() const {      // 狗独有的：叫
        cout << name << "：汪汪汪！" << endl;
    }

    void show() const {      // 展示全部信息
        cout << "名字：" << name    // name 从 Animal 继承来的
             << "  年龄：" << age   // age  从 Animal 继承来的
             << "  品种：" << breed // breed 是 Dog 自己的
             << endl;
    }
};

// ============ 测试 ============
int main() {
    cout << "===== 1. 创建 Dog 对象 =====" << endl;
    Dog d("大黄", 3, "金毛");
    // 构造顺序：先 Animal 构造，再 Dog 构造

    cout << "\n===== 2. 调用继承来的函数 =====" << endl;
    d.eat();     // 来自 Animal，Dog 自动拥有
    d.sleep();   // 来自 Animal，Dog 自动拥有
    d.bark();    // Dog 自己的
    d.show();

    cout << "\n===== 3. 析构（离开作用域）=====" << endl;
    return 0;
    // 析构顺序：先 Dog 析构，再 Animal 析构（与构造相反！）
}
