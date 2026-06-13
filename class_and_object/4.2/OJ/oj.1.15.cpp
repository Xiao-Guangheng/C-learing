// oj.1.15.cpp
#include<iostream>
#include<cstring>
using namespace std;

//你提交的代码在这里
class Person{
private:
    char name[20];
    char sex[10];   
    int age;
public:
    Person():age(0){
        strcpy(name,"NULL");
        strcpy(sex,"NO");
    }
    Person(const char* name,const char* sex,int age):age(age){
        strcpy(this->name,name);
        strcpy(this->sex,sex);
    }
    const char* GetName(){
        return name;
    }
    const char* GetSex(){
        return sex;
    }
    int GetAge(){
        return age;
    }
    void Set(const char* name,const char* sex,int age){
        strcpy(this->name,name);
        strcpy(this->sex,sex);
        this->age=age;
    }
    void Set(){
        strcpy(name,"Unknown");
        strcpy(sex,"FM");
        age=1000;
    }
    void Show(){
        cout<<name<<","<<sex<<","<<age<<endl;
    }
};
int main()
{
    Person p1;
    cout<<"Show object p1:";
    cout<<p1.GetName()<<","<<p1.GetSex()<<","<<p1.GetAge()<<endl;
    char name[20],sex[10];
    int age;
    cin>>name>>sex>>age;
    Person p2(name,sex,age);
    cout<<"Show object p2:";
    cout<<p2.GetName()<<","<<p2.GetSex()<<","<<p2.GetAge()<<endl;
    cin>>name>>sex>>age;
    cout<<"Reset and Show object p1:";
    p1.Set(name,sex,age);
    p1.Show();
    cout<<"Reset and Show object p2:";
    p2.Set();
    p2.Show();
    return 0;
}