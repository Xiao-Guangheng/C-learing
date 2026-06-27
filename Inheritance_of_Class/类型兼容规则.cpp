// 基类成员在派生类中的访问控制属性详解
#include <iostream>
#include <string>
using namespace std;

// ========= 基类：三种访问权限各一个 =========
class Base {
private:    int priv = 1;     // 只有 Base 自己能访问
protected:  int prot = 2;     // Base + 派生类能访问
public:     int pub  = 3;     // 所有人都能访问
public:
    void showBase() const {
        cout << "Base: priv=" << priv << " prot=" << prot << " pub=" << pub << endl;
    }
};

// ====== public 继承：不降级（最常用）=======
class PubDerived : public Base {
public:
    void test() {
        // cout << priv;  ❌ 派生类永远不能访问基类 private 成员
        cout << "PubDerived 可访问: prot=" << prot << " pub=" << pub << endl;
    }
    // 继承后成员属性：
    //   priv → 不可访问
    //   prot → protected（不变）
    //   pub  → public（不变）
};

// ====== protected 继承：全降到 protected ======
class ProtDerived : protected Base {
public:
    void test() {
        cout << "ProtDerived 可访问: prot=" << prot << " pub=" << pub << endl;
    }
    // 继承后成员属性：
    //   priv → 不可访问
    //   prot → protected（不变）
    //   pub  → protected（降级！）
};

// ====== private 继承：全降到 private ======
class PrivDerived : private Base {
public:
    void test() {
        cout << "PrivDerived 可访问: prot=" << prot << " pub=" << pub << endl;
    }
    // 继承后成员属性：
    //   priv → 不可访问
    //   prot → private（降级！）
    //   pub  → private（降级！）
};

int main() {
    PubDerived  pubObj;
    ProtDerived protObj;
    PrivDerived privObj;

    cout << "===== public 继承：pub 对外仍可用 =====" << endl;
    cout << "pubObj.pub = " << pubObj.pub << endl;    // ✅

    cout << "\n===== protected 继承：全部对外不可见 =====" << endl;
    // cout << protObj.pub;  ❌ pub 降级为 protected

    cout << "\n===== private 继承：全部对外不可见 =====" << endl;
    // cout << privObj.pub;  ❌ pub 降级为 private

    cout << "\n===== 各派生类内部 test() =====" << endl;
    pubObj.test();
    protObj.test();
    privObj.test();

    return 0;
}
