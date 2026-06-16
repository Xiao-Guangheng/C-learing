//结构体出现的意义就是为了保持和C语言的兼容性
//在只需要纯数据，无函数的情况下使用

//结构体和类的语法，作用基本一致，只有一个区别
//结构体默认的访问权限是public，类默认的访问权限是private
//所以结构体前面可以省略public,后面的private和protected成员必须写

#include <iostream>
#include <string>

using namespace std;

struct Student
{
    // 结构体默认是 public（公有），外部可以直接访问
    string name;
    
    // 默认构造函数
    Student() {}

    // 带参构造函数
    Student(string n, int a, string i) {
        name = n;
        age = a;
        id = i;
    }
protected:
    // protected（受保护的），外部不能直接访问，但可以在派生类（子类）中访问
    int age;

private:
    // private（私有的），外部和子类都不能访问，只能在结构体内部使用
    string id; // 学号

public:
    // 必须在这里加回 public:，否则下面的方法会被当做 private 处理！
    // 提供 public 的方法（接口）供外部写入 protected 和 private 数据
    void setAge(int a) { 
        if (a > 0 && a <= 150) { // 可以在方法中加入逻辑控制
            age = a; 
        }
    }
    void setId(string i) { id = i; }

    // 提供 public 的方法供外部读取/展示数据
    void showInfo() {
        cout << "姓名：" << name << "，年龄：" << age << "，学号：" << id << endl;
    }
};

int main()
{
    // 1. 实例化结构体对象并赋值
    Student s1;
    s1.name = "张三";          // public 成员，外界可以直接读写
    // s1.age = 20;            // 错误：age 是 protected 成员，外界无法直接访问
    // s1.id = "20230001";     // 错误：id 是 private 成员，外界无法直接访问
    
    s1.setAge(20);             // 正确：通过 public 方法间接写入 age
    s1.setId("20230001");      // 正确：通过 public 方法间接写入 id

    // 2. 使用构造函数进行初始化
    Student s2("李四", 21, "20230002");

    // 打印结构体成员信息
    cout << "学生1信息：" << endl;
    s1.showInfo();

    cout << "\n学生2信息：" << endl;
    s2.showInfo();

    return 0;
}

