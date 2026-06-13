// oj.1.7.cpp

#include<iostream>
#include<cstring>
using namespace std;

//你提交的代码在这里
class Student{
public:
    Student():id(10000),score(0){
        strcpy(name,"NULL");
    }
    Student(int no,const char xm[],int s):id(no),score(s){
        strcpy(name,xm);
    }
    int GetId() const {
        return id;
    }
    const char* GetName(){
        return name;
    
    }
    int GetScore() const {
        return score;
    }
    void Set(int no,char xm[],int s){   //重载函数，带参数，设置学生信息
        id=no;
        strcpy(name,xm);
        score=s;
    }
    void Set(){  //重载函数，不带参数，重置为默认学生信息
        id=99999;
        strcpy(name,"NONAME");
        score=100;
    }
    void Show(){
        cout<<id<<"-"<<name<<"-"<<score<<endl;
    }
private:
    int id;
    char name[9];
    int score;
};
int main()
{
    Student stu1;
    cout<<"Show object stu1:";
    //调用stu1的成员函数，使用默认构造函数创建对象stu1，并显示其信息
    cout<<stu1.GetId()<<"-"<<stu1.GetName()<<"-"<<stu1.GetScore()<<endl;   
    int no,s;
    char xm[9];
    cin>>no>>xm>>s;
    //调用带参数的构造函数创建对象stu2，并显示其信息
    Student stu2(no,xm,s);
    cout<<"Show object stu2:";
    cout<<stu2.GetId()<<"-"<<stu2.GetName()<<"-"<<stu2.GetScore()<<endl;
    cin>>no>>xm>>s;
    cout<<"Reset and Show object stu1:";
    //调用Set函数重置对象stu1的信息，并显示其信息
    stu1.Set(no,xm,s);
    stu1.Show();
    cout<<"Reset and Show object stu2:";
    //使用重载函数Set重置对象stu2的信息，并显示其信息
    stu2.Set();
    stu2.Show();
    return 0;
}