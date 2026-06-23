#include <iostream>
using namespace std;

class Clock {
private:
    int hour, minute, second;
    
public:
    Clock(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
    
    void display() {
        cout << hour << ":" << minute << ":" << second << endl;
    }
    
    Clock operator+(const Clock& c) {
        Clock temp;
        temp.second = second + c.second;
        temp.minute = minute + c.minute;
        temp.hour = hour + c.hour;
        return temp;
    }
    
    Clock operator-(const Clock& c) {
        Clock temp;
        temp.second = second - c.second;
        temp.minute = minute - c.minute;
        temp.hour = hour - c.hour;
        return temp;
    }
    //一个是前置，一个是后置。
    Clock& operator++() {
        second++;
        return *this;
    }
    
    Clock operator++(int) {
        Clock temp = *this;
        second++;
        return temp;
    }
    
    Clock& operator--() {
        second--;
        return *this;
    }
    
    Clock operator--(int) {
        Clock temp = *this;
        second--;
        return temp;
    }

};
int main() {
    Clock c1(10, 30, 45);
    Clock c2(3, 20, 30);
    
    Clock c3 = c1 + c2;
    cout << "c1 + c2 = ";
    c3.display();
    
    Clock c4 = c1 - c2;
    cout << "c1 - c2 = ";
    c4.display();
    
    ++c1;
    cout << "++c1 = ";
    c1.display();
    
    c2++;
    cout << "c2++ = ";
    c2.display();
    
    --c1;
    cout << "--c1 = ";
    c1.display();
    
    c2--;
    cout << "c2-- = ";
    c2.display();
    
    return 0;
}
