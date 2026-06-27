#include "date.h"
#include <iostream>
#include <cstdlib>   //包含标准库头文件cstdlib，用于使用exit()函数

using namespace std;

namespace{
    const int Days_before_month[]={0,31,59,90,120,151,181,212,243,273,304,334,365};
}  //此定义只在当前文件有效，用于储存某一个月前的总天数，便于计算两个日期之间的天数差
//Days_before_month 只是一个辅助用的查找表，没必要暴露给外部。
//把它放在匿名命名空间中，清晰地表达了"这是本文件的私有实现，外部不要依赖它"的意图。

Date::Date(int year,int month,int day):year(year),month(month),day(day){   //类外定义构造函数
    if (day <=0 || day >getMaxday()){
        cout<<"Invalid day!"<<endl;
        show();
        cout<<endl;
        exit(1);  //退出程序
    }

    int years =year -1;  //计算前几年总天数

    totaldays = years*365 + years/4 - years/100 + years/400 + Days_before_month[month-1] + day;

    if (isLeapYear() && month>2) totaldays++;  //如果是闰年且月份大于2，则总天数加1
}

int Date::getMaxday() const{
    if (isLeapYear() && month==2) 
        return 29;  //闰年2月有29天
    else 
        return Days_before_month[month]-Days_before_month[month-1];  //返回当月天数
}
void Date::show() const{
    cout<<getYear()<<"-"<<getMonth()<<"-"<<getDay();
}

