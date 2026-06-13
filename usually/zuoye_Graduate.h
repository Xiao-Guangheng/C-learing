#ifndef ZUOYE_GRADUATE_H
#define ZUOYE_GRADUATE_H

#include "zuoye_Student.h"
#include "zuoye_Teacher.h"

class Graduate : public Student {
public:
    Graduate() = delete;
    Graduate(const Student& s, string sub, const Teacher& adv)
        : People(s), Student(s), subject(sub), adviser(adv) {}
    Graduate(const Graduate& other)
        : People(other), Student(other), subject(other.subject), adviser(other.adviser) {}
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

#endif
