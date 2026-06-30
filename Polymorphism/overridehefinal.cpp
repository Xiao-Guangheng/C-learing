
// override 与 final 示例
// 作用是标记一个虚函数是重写基类的虚函数，如果没有正确重写，编译器会报错。

#include <iostream>
#include <string>
using namespace std;

// 基类
class Animal {
public:
    virtual void speak() const {
        cout << "动物发出声音" << endl;
    }
    virtual void move() const {
        cout << "动物在移动" << endl;
    }
    virtual ~Animal() = default;
};

// 派生类 - 使用 override
class Dog : public Animal {
public:
    // override 明确表示这是重写基类的虚函数
    void speak() const override {
        cout << "狗在叫：汪汪！" << endl;
    }  //override = "告诉编译器：
    //我就是要重写基类的函数，如果写错了请报错"，防止手滑写错函数名或参数。

    // 如果写成 void move() 但拼写错误，比如写成 movve()，编译器会报错
    void move() const override {
        cout << "狗在跑" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        cout << "猫在叫：喵喵~" << endl;
    }
    void move() const override {
        cout << "猫在走" << endl;
    }
};

// 使用 final 防止进一步继承
class GoldenRetriever final : public Dog {
public:
    void speak() const override {
        cout << "金毛在叫：旺旺！" << endl;
    }
    // 这里不能再有类继承 GoldenRetriever，因为它是 final
};

// 下面的代码如果取消注释会报错，因为 GoldenRetriever 是 final
// class LittleGolden : public GoldenRetriever { }; // 错误！

// 使用 final 禁止重写某个虚函数
class Base {
public:
    virtual void show() const {
        cout << "Base::show()" << endl;
    }
    virtual void info() const final {  // final 禁止派生类重写此函数
        cout << "Base::info() - 不可重写" << endl;
    }
    // final = "禁止派生类重写这个虚函数" 或 "禁止该类被继承"
};

class Derived : public Base {
public:
    void show() const override {
        cout << "Derived::show()" << endl;
    }
    // 下面的代码如果取消注释会报错，因为 info() 是 final
    // void info() const override { } // 错误！
};

int main() {
    cout << "=== 多态与 override 示例 ===" << endl;
    
    Animal* animals[3];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new GoldenRetriever();
    
    for (int i = 0; i < 3; i++) {
        animals[i]->speak();
        animals[i]->move();
        cout << "--------------------" << endl;
    }
    
    for (int i = 0; i < 3; i++) {
        delete animals[i];
    }
    
    cout << "\n=== final 示例 ===" << endl;
    Base* p = new Derived();
    p->show();
    p->info();  // 调用的是 Base::info()，Derived 无法重写
    
    delete p;
    
    return 0;
}

