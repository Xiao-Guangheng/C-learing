#ifndef ZUOYE_STUDENT_H
#define ZUOYE_STUDENT_H

#include "zuoye_People.h"

class Student : virtual public People {
public:
    Student() = delete;
    Student(const People& p, string cno) : People(p), classNO(cno) {}
    Student(const Student& other) : People(other), classNO(other.classNO) {}
    virtual ~Student() {}

    virtual void show() const override {
        People::show();
        cout << "班号：" << classNO << endl;
    }
protected:
    string classNO;
};

#endif
