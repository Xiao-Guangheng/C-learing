// 抽象类.cpp
// 包含纯虚函数的类称为抽象类，不能实例化

#include <iostream>
using namespace std;

// ========== 抽象类 ==========
// 抽象类：至少包含一个纯虚函数的类
// 特点：
//   1. 不能创建抽象类的对象
//   2. 可以定义抽象类的指针和引用
//   3. 派生类必须实现所有纯虚函数，否则也是抽象类
//   4. 抽象类可以有普通成员函数、成员变量、构造函数和析构函数

// 抽象基类：交通工具
class Vehicle {
private:
    string brand;   // 普通成员变量
public:
    Vehicle(const string& b) : brand(b) {
        cout << "Vehicle(" << brand << ") 构造函数" << endl;
    }

    // 纯虚函数：必须由派生类实现
    virtual void start() const = 0;
    virtual void stop() const = 0;

    // 普通成员函数：所有派生类共享
    string getBrand() const {
        return brand;
    }

    // 纯虚析构函数（也需要实现，因为派生类析构时会被调用）
    virtual ~Vehicle() {
        cout << "Vehicle(" << brand << ") 析构函数" << endl;
    }
};

// ========== 派生类必须实现所有纯虚函数 ==========

// 派生类：汽车
class Car : public Vehicle {
private:
    int doors;
public:
    Car(const string& b, int d) : Vehicle(b), doors(d) {
        cout << "Car(" << getBrand() << ") 构造函数" << endl;
    }

    // 必须实现 start()
    void start() const override {
        cout << getBrand() << " 汽车: 插入钥匙，发动引擎" << endl;
    }

    // 必须实现 stop()
    void stop() const override {
        cout << getBrand() << " 汽车: 踩刹车，熄火" << endl;
    }

    ~Car() {
        cout << "Car(" << getBrand() << ") 析构函数" << endl;
    }
};

// 派生类：自行车
class Bicycle : public Vehicle {
public:
    Bicycle(const string& b) : Vehicle(b) {
        cout << "Bicycle(" << getBrand() << ") 构造函数" << endl;
    }

    void start() const override {
        cout << getBrand() << " 自行车: 蹬脚踏板出发" << endl;
    }

    void stop() const override {
        cout << getBrand() << " 自行车: 捏刹车停下" << endl;
    }

    ~Bicycle() {
        cout << "Bicycle(" << getBrand() << ") 析构函数" << endl;
    }
};

// ========== 不实现纯虚函数 → 也是抽象类 ==========
// 下面的类没有实现 start()，所以它仍然是抽象类，不能实例化
class ElectricVehicle : public Vehicle {
public:
    ElectricVehicle(const string& b) : Vehicle(b) {}

    // 只实现了 stop()，没有实现 start()
    void stop() const override {
        cout << getBrand() << " 电动车: 断电停车" << endl;
    }
    // start() 未实现 → ElectricVehicle 仍然是抽象类
    // 如果去掉下面这行注释，会编译错误：
    // ElectricVehicle ev("Tesla");  // 错误！抽象类不能实例化
};

int main() {
    // ----- 错误使用 -----
    // Vehicle v("Toyota");          // 编译错误！抽象类不能实例化
    // Vehicle* p = new Vehicle("X"); // 编译错误！
    // ElectricVehicle ev("Tesla");   // 编译错误！没有实现 start()

    // ----- 正确使用 -----
    // 抽象类指针可以指向派生类对象
    cout << "========== 创建对象 ==========" << endl;
    Vehicle* v1 = new Car("丰田", 4);  //就是这个Vechicle本身不能创建对象，但是可以创建它的派生类对象，并用抽象类指针指向它，所以这时候
    //抽象类的指针指向了一个派生类对象，这就是多态的体现
    Vehicle* v2 = new Bicycle("捷安特");

    cout << "\n========== 通过抽象类指针调用 ==========" << endl;
    // 通过抽象类指针调用 — 多态
    Vehicle* vehicles[2] = { v1, v2 };
    for (int i = 0; i < 2; i++) {
        cout << "品牌: " << vehicles[i]->getBrand() << endl;
        vehicles[i]->start();
        vehicles[i]->stop();
        cout << endl;
    }

    // 抽象类引用
    cout << "-------- 通过引用调用 --------" << endl;
    Car myCar("宝马", 4);
    Vehicle& ref = myCar;
    ref.start();

    cout << "\n========== 删除对象 ==========" << endl;
    delete v1;
    delete v2;

    return 0;
}
