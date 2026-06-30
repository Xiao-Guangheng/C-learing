// 虚函数.cpp —— 虚函数实现动态多态
// 虚函数必须是非静态的成员函数
// 动态绑定：运行时根据实际对象类型决定调用哪个函数

#include <iostream>
using namespace std;

// 基类 Animal
class Animal {
public:
    // 虚函数：允许在派生类中被重写
    // 通过 virtual 关键字声明
    virtual void speak() const {
        cout << "Animal 发出声音" << endl;
    }

    // 虚析构函数：确保通过基类指针删除派生类对象时正确调用派生类析构
    virtual ~Animal() {}
};

// 派生类 Dog，继承自 Animal
class Dog : public Animal {
public:
    // override 关键字（C++11）：明确表示重写基类虚函数
    // 即使不写 override，只要函数签名相同也会重写，但写出来更清晰安全
    void speak() const override {
        cout << "Dog 汪汪叫" << endl;
    }
};

// 派生类 Cat，继承自 Animal
class Cat : public Animal {
public:
    void speak() const override {
        cout << "Cat 喵喵叫" << endl;
    }
};

int main() {
    // 基类指针指向派生类对象 —— 这是动态多态的核心用法
    Animal* ptr1 = new Dog();
    Animal* ptr2 = new Cat();
    Animal* ptr3 = new Animal();

    cout << "通过基类指针调用 speak()：" << endl;
    cout << "ptr1（实际是 Dog） : ";
    ptr1->speak();  // 输出：Dog 汪汪叫
    //这里为什么会找到 Dog 的 speak() 函数呢？
    // 因为 ptr1 实际上指向的是一个 Dog 对象，而 speak() 是一个虚函数，所以在运行时会根据实际对象类型（Dog）来调用对应的函数。
    //所以动态绑定就是在运行时根据实际对象类型来决定调用哪个函数，而不是在编译时就确定了。

    cout << "ptr2（实际是 Cat） : ";
    ptr2->speak();  // 输出：Cat 喵喵叫

    cout << "ptr3（实际是 Animal）: ";
    ptr3->speak();  // 输出：Animal 发出声音

    // 基类引用也能实现动态多态
    Dog dog;
    Cat cat;
    Animal& ref1 = dog;
    Animal& ref2 = cat;

    cout << "\n通过基类引用调用 speak()：" << endl;
    ref1.speak();  // 输出：Dog 汪汪叫
    ref2.speak();  // 输出：Cat 喵喵叫

    // 清理动态内存
    delete ptr1;
    delete ptr2;
    delete ptr3;

    return 0;
}

// ========== 关键概念 ==========
// 1. virtual 关键字：告诉编译器这个函数需要动态绑定
// 2. 动态绑定：编译时不确定调用哪个函数，运行时根据实际对象类型决定
// 3. 虚函数表（vtable）：每个有虚函数的类都有一个虚函数表，
//    表中存放虚函数的地址。对象中有一个虚指针（vptr）指向该表
// 4. 基类指针/引用 指向 派生类对象，调用虚函数时触发动态多态
// 5. 如果去掉 virtual，则 ptr1->speak() 只会调用 Animal::speak()
//    因为编译时只知道 ptr1 是 Animal* 类型

