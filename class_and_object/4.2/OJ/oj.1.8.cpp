// oj.1.8.cpp
#include<iostream>
#include<cmath>
using namespace std;

//你提交的代码在这里
class Line{
public:
    Line():x1(0),y1(0),x2(0),y2(0){};
    Line(double x1,double y1,double x2,double y2):
        x1(x1),y1(y1),x2(x2),y2(y2){};
    void Set(double x1,double y1,double x2,double y2){
        this->x1=x1;
        this->y1=y1;
        this->x2=x2;
        this->y2=y2;
    }   
    void Set(){
        x1=1;
        y1=5;
        x2=8;
        y2=4;
    }
    void Show(){
        cout<<"("<<x1<<","<<y1<<")--("<<x2<<","<<y2<<")"<<"length="<<sqrt(pow(x2-x1,2)+pow(y2-y1,2))<<endl;
    }

private:
    double x1;
    double y1;
    double x2;
    double y2;
};
int main()
{
    Line L1;
    cout<<"Show object L1:";
    L1.Show();
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    Line L2(x1,y1,x2,y2);
    cout<<"Show object L2:";
    L2.Show();
    cin>>x1>>y1>>x2>>y2;
    cout<<"Reset and Show object L1:";
    L1.Set(x1,y1,x2,y2);
    L1.Show();
    cout<<"Reset and Show object L2:";
    L2.Set();
    L2.Show();
    return 0;
}