#ifndef ZUOYE_PEOPLE_H
#define ZUOYE_PEOPLE_H

#include <iostream>
#include <string>
#include "zuoye_Date.h"
using namespace std;

class People {
public:
    People() = delete;
    People(int num, string n, string s, string pid, const Date& d)
        : number(num), name(n), sex(s), id(pid), birthday(d) {}
    People(const People& other)
        : number(other.number), name(other.name), sex(other.sex), id(other.id), birthday(other.birthday) {}
    virtual ~People() {}

    virtual void show() const {
        cout << "编号：" << number << endl;
        cout << "姓名：" << name << endl;
        cout << "性别：" << sex << endl;
        cout << "出生日期：";
        birthday.show();
        cout << endl;
        cout << "身份证号：" << id << endl;
    }
protected:
    int number;
    string name;
    string sex;
    Date birthday;
    string id;
};

#endif
