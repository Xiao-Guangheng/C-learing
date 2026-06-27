// 深复制简单实例
#include <iostream>
#include <cstring>
using namespace std;

class Student {
public:
    Student(const char* name, int age) : age(age) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        cout << "构造: " << this->name << endl;
    }

    // 深复制：拷贝构造函数
    Student(const Student& other) : age(other.age) {
        name = new char[strlen(other.name) + 1];  // 分配新内存
        strcpy(name, other.name);                  // 复制内容
        cout << "深复制构造: " << name << endl;
    }

    // 注意：参数只有 const Student& other
    Student(const Student& other) : age(other.age) {
        
        // 1. 深复制字符指针 (name)
        name = new char[strlen(other.name) + 1];  
        strcpy(name, other.name);                  
        
        // 2. 深复制整型指针 (id)
        // 这里可以直接写 id = ...，不需要加 this->，编译器能认出来
        id = new int(*(other.id));
        
        cout << "深复制构造: " << name << endl;
    }   //age是普通类型，直接拷贝即可，相当于浅复制，而name和id是指针类型，需要深复制。

    // 深复制：赋值运算符
    Student& operator=(const Student& other) {
        if (this == &other) return *this;          // 防止自赋值
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        age = other.age;
        cout << "深复制赋值: " << name << endl;
        return *this;
    }

    ~Student() {
        cout << "析构: " << name << endl;
        delete[] name;
        delete id;
    }

    void show() const {
        cout << name << " " << age << "岁"
             << "  指针:" << (void*)name << endl;
    }

private:
    char* name;
    int   age;

    int* id;
};

int main() {
    // 1. 拷贝构造 —— 深复制
    cout << "=== 拷贝构造 ===" << endl;
    Student s1("张三", 20);
    Student s2 = s1;          // 深复制：新分配内存
    s1.show();
    s2.show();
    // 指针地址不同 → 各自独立的堆内存
    cout << endl;

    // 2. 赋值运算符 —— 深复制
    cout << "=== 赋值运算符 ===" << endl;
    Student s3("李四", 22);
    Student s4("王五", 25);
    s3 = s4;                  // 深复制：s3 释放旧内存，分配新内存
    s3.show();
    s4.show();
    cout << endl;

    return 0;
}
//深层复制就是创建新的内存，浅层复制是共享内存的。