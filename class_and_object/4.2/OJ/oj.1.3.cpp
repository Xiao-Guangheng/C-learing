#include<iostream>
using namespace std;

class Circle{
public:
    Circle():r(10){}  // 默认构造函数
    Circle(double r):r(r){}  // 带参构造函数
    double Get() const{
        return r;
    }
    void Set(double newr){
        r = newr;
    }
    double Circumference() const{
        return 2*3.14*r;
    }
    double Square() const{
        return 3.14*r*r;
    }
private:    
    double r;
};

int main()
{
    Circle c1;
    cout<<"Show object c1:"<<endl;
    cout<<"    radius="<<c1.Get()<<endl;
    cout<<"    Circumference="<<c1.Circumference()<<endl;
    cout<<"    Square="<<c1.Square()<<endl;
    double r;
    cin>>r;
    Circle c2(r);
    cout<<"Show object c2:"<<endl;
    cout<<"    radius="<<c2.Get()<<endl;
    cout<<"    Circumference="<<c2.Circumference()<<endl;
    cout<<"    Square="<<c2.Square()<<endl;
    cin>>r;
    cout<<"Reset and Show object c1:"<<endl;
    c1.Set(r);
    cout<<"    radius="<<c1.Get()<<endl;
    cout<<"    Circumference="<<c1.Circumference()<<endl;
    cout<<"    Square="<<c1.Square()<<endl;
    return 0;
}

// Input
// 2行，每行1个double类型非负实数，表示圆的半径。

// Sample Input 1 

// 1
// 2
// Sample Output 1

// Show object c1:
//     radius=10
//     Circumference=62.8
//     Square=314
// Show object c2:
//     radius=1
//     Circumference=6.28
//     Square=3.14
// Reset and Show object c1:
//     radius=2
//     Circumference=12.56
//     Square=12.56