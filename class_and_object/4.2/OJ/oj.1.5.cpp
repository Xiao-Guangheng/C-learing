// oj.1.5.cpp
#include<iostream>
using namespace std;

class Complex{
public:
    Complex():r(1),i(2){}
    Complex(double r, double i):r(r),i(i){}

    void Show() {
        if (i == 0) {
            cout << r << endl;
        } 
        else if (r == 0) {
            cout << i << "i" << endl;
        }
        else {
            if (i > 0) {
                cout << r << "+" << i << "i" << endl;
            } else {
                cout << r << i << "i" << endl;
            }
        }
    }

    void Set (double real,double image){
        r = real;
        i = image;  
    }

private:
    double r;
    double i;
};

int main()
{
    Complex c1;
    cout<<"Show object c1:";
    c1.Show();
    double real,imag;
    cin>>real>>imag;
    Complex c2(real,imag);
    cout<<"Show object c2:";
    c2.Show();
    cin>>real>>imag;
    cout<<"Reset and Show object c1:";
    c1.Set(real,imag);
    c1.Show();
    return 0;
}