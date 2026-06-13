#ifndef ZUOYE_TEACHER_H
#define ZUOYE_TEACHER_H

#include "zuoye_People.h"

class Teacher : virtual public People {
public:
    Teacher() = delete;
    Teacher(const People& p, string prin, string dept)
        : People(p), principalship(prin), department(dept) {}
    Teacher(const Teacher& other)
        : People(other), principalship(other.principalship), department(other.department) {}
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

#endif
