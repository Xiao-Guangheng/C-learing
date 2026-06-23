#include <iostream>
using namespace std;

class Vector {
private:
    double x, y;
    
public:
    Vector(double x = 0, double y = 0) : x(x), y(y) {}
    
    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
    
    Vector operator-(const Vector& v) {
        Vector temp;
        temp.x = x - v.x;
        temp.y = y - v.y;
        return temp;
    }
    
    friend Vector operator+(const Vector& v1, const Vector& v2);
};
//非成员函数
Vector operator+(const Vector& v1, const Vector& v2) {
    Vector temp;
    temp.x = v1.x + v2.x;
    temp.y = v1.y + v2.y;
    return temp;
}

int main() {
    Vector v1(3, 4);
    Vector v2(1, 2);
    
    cout << "v1 = ";
    v1.display();
    cout << "v2 = ";
    v2.display();
    
    Vector v3 = v1 + v2;
    cout << "v1 + v2 = ";
    v3.display();
    
    Vector v4 = v1 - v2;
    cout << "v1 - v2 = ";
    v4.display();
    
    return 0;
}