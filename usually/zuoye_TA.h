#ifndef ZUOYE_TA_H
#define ZUOYE_TA_H

#include "zuoye_Graduate.h"
#include "zuoye_Teacher.h"

class TA : public Graduate, public Teacher {
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

#endif
