#include <iostream>
#include <string>
using namespace std;

int main(){
    string data;
    cout << "请输入需要保护的数据：";
    getline(cin, data);

    // 数据保护逻辑
    string protectedData = "****" + data.substr(4); // 仅显示后面的部分

    cout << "保护后的数据：" << protectedData << endl;

    return 0;
}