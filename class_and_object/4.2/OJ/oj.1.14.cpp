// oj.1.14.cpp
#include<iostream>
#include<cstring>
using namespace std;

//你提交的代码在这里
class Laboratory{
private:
    int room_no;
    int capacity;
    char name[20];
public:
    Laboratory():room_no(0),capacity(0){
        strcpy(name,"NULL");
    }
    Laboratory(int room_no,int capacity,const char* name):room_no(room_no),capacity(capacity){
        strcpy(this->name,name);
    }
    int GetRoom_no(){
        return room_no;
    }
    int GetCapacity(){
        return capacity;
    }
    const char* GetName(){
        return name;
    }
    void Set(int room_no,int capacity,const char* name){
        this->room_no=room_no;
        this->capacity=capacity;
        strcpy(this->name,name);
    }
    void Set(){
        room_no=99999;
        capacity=1000;
        strcpy(name,"None");
    }
    void Show(){
        cout<<room_no<<"/"<<capacity<<"/"<<name<<endl;
    }
};
int main()
{
    Laboratory L1;
    cout<<"Show object L1:";
    cout<<L1.GetRoom_no()<<"/"<<L1.GetCapacity()<<"/"<<L1.GetName()<<endl;
    int room_no;
    int capacity;
    char name[20];
    cin>>room_no>>capacity>>name;
    Laboratory L2(room_no,capacity,name);
    cout<<"Show object L2:";
    cout<<L2.GetRoom_no()<<"/"<<L2.GetCapacity()<<"/"<<L2.GetName()<<endl;
    cin>>room_no>>capacity>>name;
    cout<<"Reset and Show object L1:";
    L1.Set(room_no,capacity,name);
    L1.Show();
    cout<<"Reset and Show object L2:";
    L2.Set();
    L2.Show();
    return 0;
}