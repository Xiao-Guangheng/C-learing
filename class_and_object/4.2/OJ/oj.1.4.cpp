// oj.1.4.cpp
#include<iostream>
using namespace std;

class Rectangle{
public:
    Rectangle():width(2),height(2){}  // 默认构造函数
    Rectangle(double w, double h):width(w),height(h){}  // 带参构造函数
    
    double GetWidth() const{
        return width;
    }
    double GetHeight() const{
        return height;
    }
    void Set(double neww, double newh){
        width = neww;
        height = newh;
    }
    double Perimeter() const{
        return 2*(width+height);
    }
    double Area() const{
        return width*height;
    }
private:
    double width;
    double height;
};

int main()
{
    Rectangle rect1;
    cout<<"Show object rect1:"<<endl;
    cout<<"    width="<<rect1.GetWidth()<<endl;
    cout<<"    height="<<rect1.GetHeight()<<endl;
    cout<<"    Perimeter="<<rect1.Perimeter()<<endl;
    cout<<"    Area="<<rect1.Area()<<endl;
    double w,h;
    cin>>w>>h;
    Rectangle rect2(w,h);
    cout<<"Show object rect2:"<<endl;
    cout<<"    width="<<rect2.GetWidth()<<endl;
    cout<<"    height="<<rect2.GetHeight()<<endl;
    cout<<"    Perimeter="<<rect2.Perimeter()<<endl;
    cout<<"    Area="<<rect2.Area()<<endl;
    cin>>w>>h;
    cout<<"Reset and Show object rect1:"<<endl;
    rect1.Set(w,h);
    cout<<"    width="<<rect1.GetWidth()<<endl;
    cout<<"    height="<<rect1.GetHeight()<<endl;
    cout<<"    Perimeter="<<rect1.Perimeter()<<endl;
    cout<<"    Area="<<rect1.Area()<<endl;
    return 0;
}

// Sample Input 1 

// 5.1 2.8
// 3 3
// Sample Output 1

// Show object rect1:
//     width=2
//     height=2
//     Perimeter=8
//     Area=4
// Show object rect2:
//     width=5.1
//     height=2.8
//     Perimeter=15.8
//     Area=14.28
// Reset and Show object rect1:
//     width=3
//     height=3
//     Perimeter=12
//     Area=9