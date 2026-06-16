//一个类内内嵌其他类的对象作为成员的情况 —— 组合（类的组合）

#include <iostream>
#include <string>
using namespace std;

// 日期类
class Date
{
private:
    int year, month, day;

public:
    // 默认构造函数
    Date() : year(2000), month(1), day(1) {}
    // 带参数的构造函数
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    // 复制构造函数
    Date(const Date& other) : year(other.year), month(other.month), day(other.day) {}
    // 析构函数
    ~Date() {}

    // 设置日期
    void SetDate(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }

    // 获取年月日
    int GetYear() const { return year; }
    int GetMonth() const { return month; }
    int GetDay() const { return day; }

    // 显示日期
    void Show() const
    {
        cout << year << "-" << month << "-" << day;
    }
};

// 学生类 —— 内嵌 Date 对象作为生日
class Student
{
private:
    string name;
    int age;
    Date birthday; // 类内内嵌其他类的对象作为成员（组合）

public:
    // 默认构造函数
    Student() : name(""), age(0), birthday() {}
    // 带参数的构造函数
    Student(string n, int a, int y, int m, int d)
        : name(n), age(a), birthday(y, m, d) {}
    // 带 Date 对象的构造函数
    Student(string n, int a, const Date& d)
        : name(n), age(a), birthday(d) {}
    // 复制构造函数
    Student(const Student& other)
        : name(other.name), age(other.age), birthday(other.birthday) {}
    // 析构函数
    ~Student() {}

    // 设置姓名
    void SetName(string n) { name = n; }
    // 设置年龄
    void SetAge(int a) { age = a; }
    // 设置生日
    void SetBirthday(int y, int m, int d) { birthday.SetDate(y, m, d); }
    void SetBirthday(const Date& d) { birthday = d; }

    // 获取信息
    string GetName() const { return name; }
    int GetAge() const { return age; }
    Date GetBirthday() const { return birthday; }

    // 显示学生信息
    void Show() const
    {
        cout << "姓名: " << name << endl;
        cout << "年龄: " << age << endl;
        cout << "生日: ";
        birthday.Show();
        cout << endl;
    }
};

int main()
{
    // 方式1：通过默认构造函数创建，再逐个设置
    cout << "===== 方式1：默认构造 + 逐个设置 =====" << endl;
    Student s1;
    s1.SetName("张三");
    s1.SetAge(20);
    s1.SetBirthday(2000, 1, 1);
    s1.Show();
    cout << endl;

    // 方式2：通过带参数构造函数直接初始化
    cout << "===== 方式2：带参构造函数初始化 =====" << endl;
    Student s2("李四", 21, 1999, 6, 15);
    s2.Show();
    cout << endl;

    // 方式3：先创建 Date，再传入 Student
    cout << "===== 方式3：组合构造 =====" << endl;
    Date d(2001, 10, 20);
    Student s3("王五", 19, d);
    s3.Show();
    cout << endl;

    // 方式4：复制构造函数
    cout << "===== 方式4：复制构造 =====" << endl;
    Student s4(s2);
    s4.Show();
    cout << endl;

    return 0;
}