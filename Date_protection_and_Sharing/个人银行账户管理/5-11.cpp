// 5-11.cpp —— 主函数文件
#include <iostream>
#include "account.h"
using namespace std;

int main() {
    SavingsAccount sa0(0, 10000, 0.02);
    sa0.show();
    sa0.deposit(20240101, 5000);
    sa0.withdraw(20240102, 3000);
    sa0.settle(20240103);
    sa0.show();

    cout << "------" << endl;

    SavingsAccount sa1(1, 5000, 0.02);
    sa1.show();
    sa1.deposit(20240101, 2000);
    sa1.withdraw(20240102, 1000);
    sa1.settle(20240103);
    sa1.show();

    cout << "------" << endl;

    cout << "Total: " << SavingsAccount::getTotal() << endl;

    return 0;
}
