// oj.1.9.cpp
#include<iostream>
#include<cstring>
using namespace std;

//你提交的代码在这里
class Country{
public:
    Country():population(0){
        strcpy(name,"NULL");
        strcpy(capital,"NONE");
    }
    Country(const char* name,const char* capital,int population):population(population){
        strcpy(this->name,name);
        strcpy(this->capital,capital);
    }
    const char* GetName(){
        return name;
    }
    const char* GetCapital(){
        return capital;
    }
    int GetPopulation(){
        return population;
    }
    void Set(const char* name,const char* capital,int population){
        strcpy(this->name,name);
        strcpy(this->capital,capital);
        this->population=population;
    }
    void Set(){
        strcpy(name,"China");
        strcpy(capital,"Beijing");
        population=1400000000;
    }
    void Show(){
        cout<<name<<"-"<<capital<<"-"<<population<<endl;
    }
private:
    char name[40];
    char capital[40];
    int population;

};
int main()
{
    Country c1;
    cout<<"Show object c1:";
    cout<<c1.GetName()<<"-"<<c1.GetCapital()<<"-"<<c1.GetPopulation()<<endl;
    char name[40],capital[40];
    int population;
    cin>>name>>capital>>population;
    Country c2(name,capital,population);
    cout<<"Show object c2:";
    cout<<c2.GetName()<<"-"<<c2.GetCapital()<<"-"<<c2.GetPopulation()<<endl;
    cin>>name>>capital>>population;
    cout<<"Reset and Show object c1:";
    c1.Set(name,capital,population);
    c1.Show();
    cout<<"Reset and Show object c2:";
    c2.Set();   //重载函数
    c2.Show();
    return 0;
}