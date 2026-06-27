
#ifndef __ACCUMULATOR_H__
#define __ACCUMULATOR_H__

#include "date.h"

class Accumulator {
private:
    Date lastDate;  // 上次更新的日期
    double value;     // 累计的值
    double sum;       // 累计的总和
public:
    //构造函数，date为起始日期，value为初始值
    Accumulator(const Date &date, double value = 0.0)
        : lastDate(date), value(value), sum(0.0) {}

    //获得到日期date的累加结果
    double getSum( const Date &date)const {
        return sum + value * date.distance(lastDate);
    }

    //在date将数值变更为value
    void change(const Date &date, double value) {
        sum = getSum(date);  // 更新累计总和
        lastDate = date;     // 更新最后日期
        this->value = value; // 更新当前值
    }

    //初始化，将日期变为date，数值变为value，累加器清零
    void reset(const Date &date, double value ) {
        lastDate = date;
        this->value = value;
        sum = 0.0;
    }
};

#endif