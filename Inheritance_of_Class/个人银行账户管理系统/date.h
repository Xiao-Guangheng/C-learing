#ifndef __DATE_H__
#define __DATE_H__   //预处理指令，防止头文件被重复包含

class Date{
private:
    int year;
    int month;
    int day;
    int totaldays;
public:
    Date(int year,int month,int day);  //构造函数

    Date(const Date& other);  //拷贝构造函数

    ~Date();  //析构函数

    int getYear() const{return year;}  //获取年份
    int getMonth() const{return month;}  //获取月份
    int getDay() const{return day;}  //获取天

    int getMaxday() const;  //当月有多少天 
    
    bool isLeapYear() const{
        return (year%4==0 && year%100!=0) || (year%400==0);
    }  //是否是闰年

    void show() const;

    int distance(const Date& date) const{
        return totaldays - date.totaldays;
    }   //计算两个日期之间的天数差
};

#endif