#include <iostream>
#include <cstring>
using namespace std;

class String {
private:
    char* str;  
    int len;    
    
public:
    String(const char* s = "") {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }
    
    String(const String& s) {
        len = s.len;
        str = new char[len + 1];
        strcpy(str, s.str);
    }
    
    ~String() {
        delete[] str;
    }
    
    int Length() const {
        return len;
    }
    
    String& operator=(const String& s) {
        if (this != &s) {
            delete[] str;
            len = s.len;
            str = new char[len + 1];
            strcpy(str, s.str);
        }
        return *this;
    }
    
    String& operator=(const char* s) {
        delete[] str;
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
        return *this;
    }
    
    String& operator+=(const String& s) {
        char* temp = new char[len + s.len + 1];
        strcpy(temp, str);
        strcat(temp, s.str);
        delete[] str;
        str = temp;
        len = len + s.len;
        return *this;
    }
    
    friend String operator+(const String& s1, const String& s2) {
        String temp;
        delete[] temp.str;
        temp.len = s1.len + s2.len;
        temp.str = new char[temp.len + 1];
        strcpy(temp.str, s1.str);
        strcat(temp.str, s2.str);
        return temp;
    }
    
    char& operator[](int index) {
        return str[index];
    }
    
    bool operator==(const String& s) const {
        return strcmp(str, s.str) == 0;
    }
    
    bool operator<(const String& s) const {
        return strcmp(str, s.str) < 0;
    }
    
    friend ostream& operator<<(ostream& out, const String& s) {
        out << s.str;
        return out;
    }
    
    friend istream& operator>>(istream& in, String& s) {
        char buffer[1000];
        in >> buffer;
        delete[] s.str;
        s.len = strlen(buffer);
        s.str = new char[s.len + 1];
        strcpy(s.str, buffer);
        return in;
    }
};

int main() {
    String s1("Help!"), s2("Good!"), s3(s2), s4, s5;
    
    cout << "s1=" << s1 << endl;
    
    s3 = "Hello!";
    cout << "s3=" << s3 << endl;
    
    s3 = s2;
    cout << "s3=" << s3 << endl;
    
    s3 += s2;
    cout << "s3=" << s3 << endl;
    
    cout << "请输入s4: ";
    cin >> s4;
    cout << "s4=" << s4 << endl;
    
    s5 = s3 + s4;
    cout << "s5=" << s5 << endl;
    
    s5[0] = 'g';
    cout << "s5=" << s5 << endl;
    
    cout << "strlen(s5)=" << s5.Length() << endl;
    cout << "boolalpha=" << (s3 == s1) << endl;
    cout << boolalpha << (s3 < s1) << endl;
    
    return 0;
}