// oj.1.13.cpp
#include<iostream>
#include<cstring>
using namespace std;

//你提交的代码在这里
class Course{
private:
    int id;
    char name[40];
    int credit;
public:
    Course():id(0),credit(0){
        strcpy(name,"NULL");
    }
    Course(int id,const char* name,int credit):id(id),credit(credit){
        strcpy(this->name,name);
    }
    int GetId(){
        return id;
    }
    const char* GetName(){
        return name;
    }
    int GetCredit(){
        return credit;
    }
    void Set(int id,const char* name,int credit){
        this->id=id;
        strcpy(this->name,name);
        this->credit=credit;
    }
    void Set(){
        id=9999999;
        strcpy(name,"None");
        credit=10000;
    }
    void Show(){
        cout<<id<<"/"<<name<<"/"<<credit<<endl;
    }
};
int main()
{
    Course c1;
    cout<<"Show object c1:";
    cout<<c1.GetId()<<"/"<<c1.GetName()<<"/"<<c1.GetCredit()<<endl;
    double id;
    char name[40];
    int credit;
    cin>>id>>name>>credit;
    Course c2(id,name,credit);
    cout<<"Show object c2:";
    cout<<c2.GetId()<<"/"<<c2.GetName()<<"/"<<c2.GetCredit()<<endl;
    cin>>id>>name>>credit;
    cout<<"Reset and Show object c1:";
    c1.Set(id,name,credit);
    c1.Show();
    cout<<"Reset and Show object c2:";
    c2.Set();
    c2.Show();
    return 0;
}