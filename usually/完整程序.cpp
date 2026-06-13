#pragma execution_character_set("utf-8")

#include "zuoye_TA.h"

int main() {
    Date t_d(1970, 1, 1);
    People t_p(14007, "李四", "man", "420107197001012020", t_d);
    Teacher t_t(t_p, "副教授", "计算机科学与技术");

    Date s_d(1998, 2, 2);
    People s_p(2020001, "张三", "man", "420107199802022046", s_d);
    Student s_s(s_p, "2002");
    Graduate s_g(s_s, "计算机科学与技术", t_t);
    Teacher s_t(s_s, "讲师", "计算机科学与技术");
    TA ta(s_g, s_t);
    ta.show();

    return 0;
}
    Date(const Date& other) : year(other.year), month(other.month), day(other.day) {}
    //析构函数
    ~Date() {}
    //內联函数
    inline void show() const {
        cout << year << "-" << month << "-" << day;
    }
    inline void SetDate(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }
private:
    int year, month, day;
};

class People {
public:
    People() = delete;  //禁止默认构造函数
    People(int num, string n, string s, string pid, const Date& d)
        : number(num), name(n), sex(s), id(pid), birthday(d) {}  //构造函数
    People(const People& other)
        : number(other.number), name(other.name), sex(other.sex),id(other.id), birthday(other.birthday) {}
    virtual ~People() {}  //虚析构函数

    virtual void show() const {  //虚函数
        cout << "编号：" << number << endl;
        cout << "姓名：" << name << endl;
        cout << "性别：" << sex << endl;
        cout << "出生日期：";
        birthday.show();
        cout << endl;
        cout << "身份证号：" << id << endl;
    }
protected:  //为什么这里是protected？因为派生类需要访问这些成员变量，后面基本都是protected了
    //类型兼容规则
    int number;
    string name;
    string sex;
    Date birthday;
    string id;
};
//需要访问基类的成员函数和成员变量，
//使用public继承可以保证基类的public成员在派生类中仍然是public的，
//方便派生类访问和使用基类的功能。
class Student : virtual public People {   //派生类Student虚继承People
public:
    //先使用delete删除默认构造函数，禁止使用默认构造函数创建对象，
    //因为Student类需要一个People对象来初始化基类部分。
    Student() = delete;  
    Student(const People& p, string cno): People(p), classNO(cno) {} 
    //构造函数，使用成员初始化列表调用People的构造函数来初始化基类部分
    Student(const Student& other): People(other), classNO(other.classNO) {}
    virtual ~Student() {}

    virtual void show() const override {
        People::show();
        cout << "班号：" << classNO << endl;
    }
protected:
    string classNO;
};

class Teacher : virtual public People {   //派生类Teacher虚继承People
public:
    Teacher() = delete;
    Teacher(const People& p, string prin, string dept)
        : People(p), principalship(prin), department(dept) {}
    Teacher(const Teacher& other)
        : People(other), principalship(other.principalship),
          department(other.department) {}
    virtual ~Teacher() {}

    virtual void show() const override {
        People::show();
        cout << "职务：" << principalship << endl;
        cout << "部门：" << department << endl;
    }
protected:
    string principalship;
    string department;
};

class Graduate : public Student {  //从Student派生Graduate，Student虚继承People
public:
    Graduate() = delete;
    Graduate(const Student& s, string sub, const Teacher& adv)
        : People(s), Student(s), subject(sub), adviser(adv) {}
    Graduate(const Graduate& other)
        : People(other), Student(other), subject(other.subject),
          adviser(other.adviser) {}
    virtual ~Graduate() {}

    virtual void show() const override {
        Student::show();
        cout << "专业：" << subject << endl;
        cout << "导师：" << endl;
        adviser.show();
    }
protected:
    string subject;
    Teacher adviser;
};

class TA : public Graduate, public Teacher {   //从Graduate和Teacher派生TA，Graduate虚继承People，Teacher虚继承People
public:
    TA() = delete;
    TA(const Graduate& g, const Teacher& t)
        : People(g), Graduate(g), Teacher(t) {}
    TA(const TA& other)
        : People(other), Graduate(other), Teacher(other) {}
    ~TA() {}

    void show() const override {
        Graduate::show();
        cout << "职务（助教）：" << Teacher::principalship << endl;
        cout << "部门（助教）：" << Teacher::department << endl;
    }
};

int main() {
    Date t_d(1970, 1, 1);
    People t_p(14007, "李四", "man", "420107197001012020", t_d);
    Teacher t_t(t_p, "副教授", "计算机科学与技术");

    Date s_d(1998, 2, 2);
    People s_p(2020001, "张三", "man", "420107199802022046", s_d);
    Student s_s(s_p, "2002");
    Graduate s_g(s_s, "计算机科学与技术", t_t);
    Teacher s_t(s_s, "讲师", "计算机科学与技术");
    TA ta(s_g, s_t);
    ta.show();

    return 0;
}