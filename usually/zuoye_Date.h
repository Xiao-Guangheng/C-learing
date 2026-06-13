#ifndef ZUOYE_DATE_H
#define ZUOYE_DATE_H

#include <iostream>
using namespace std;

class Date {
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {}
    Date(const Date& other) : year(other.year), month(other.month), day(other.day) {}
    ~Date() {}

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

#endif
