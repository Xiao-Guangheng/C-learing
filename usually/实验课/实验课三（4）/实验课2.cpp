// 分别定义一个教师类Teacher和干部类Leader，采用多重继承来派生一个新类—双职教师类DbTeacher。
// 假设要管理下述几类人员的一些相关数据：
// 教师类：姓名、性别、出生日期、职称、电话；
// 干部类：姓名、性别、出生日期、职务、电话；
// 双职教师类：姓名、性别、出生日期、职务、职称、电话、工资。
// 请设计每个类的构造函数及显示类对象数据的成员函数。编写主函数，测试这些类。
// 提示：
// (1) 教师类和干部类都有姓名、性别、出生日期、电话等属性，请设计它们的基类—职员类Staff。
// (2) 理解为了避免同一基类出现多个重复的副本而采用的虚基类概念和虚拟继承，
// 学习利用虚基类解决二义性问题。

#include <iostream>
#include <string>
using namespace std;


class Staff {
public:
    Staff(string n, string gender, string birthDate, string phone) 
        : name(n), gender(gender), birthDate(birthDate), phone(phone) {}

    ~Staff() {}

    void displayStaff() {
        cout << "Name: " << name << "\nGender: " << gender 
             << "\nBirth Date: " << birthDate << "\nPhone: " << phone << endl;
    }
    
protected:  
    string name;
    string gender;
    string birthDate;
    string phone;
};

class Teacher : virtual public Staff {
public:
    Teacher(string n, string gender, string birthDate, string phone, string title)
        : Staff(n, gender, birthDate, phone), title(title) {}

    ~Teacher() {}

    void displayTeacher() {
        displayStaff();
        cout << "Title: " << title << endl;
    }

protected:
    string title;
};

class Leader : virtual public Staff {
public:
    Leader(string n, string gender, string birthDate, string phone, string position)
        : Staff(n, gender, birthDate, phone), position(position) {}

    ~Leader() {}

    void displayLeader() {
        displayStaff();
        cout << "Position: " << position << endl;
    }

protected:
    string position;
};

class DbTeacher : public Teacher, public Leader {
public:
    DbTeacher(string n, string gender, string birthDate, string phone, 
              string title, string position, double salary)
        : Staff(n, gender, birthDate, phone), 
          Teacher(n, gender, birthDate, phone, title), 
          Leader(n, gender, birthDate, phone, position), 
          salary(salary) {}

    ~DbTeacher() {}

    void displayDbTeacher() {
        displayStaff(); // 直接调用共同基类的显示成员
        cout << "Title: " << title << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }

private:
    double salary;
};

int main() {
    DbTeacher dt("John Doe", "Male", "1980-05-15", "13800000000", "Associate Professor", "Department Head", 8000.50);
    
    cout << "--- Double-role Teacher Info ---" << endl;
    dt.displayDbTeacher();

    return 0;
}


