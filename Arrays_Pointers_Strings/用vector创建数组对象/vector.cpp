// vector 基本用法
#include <iostream>
#include <vector>
using namespace std;

double average(const vector<double>& arr){
    double sum=0;
    for (int i=0; i<arr.size(); i++){
        sum+=arr[i];
    }
    return sum/arr.size();
}

int main() {
    // 1. 创建 —— 比 new[] 简单多了
    vector<int> v = {10, 20, 30, 40, 50};

    // 2. 遍历
    cout << "遍历: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // 3. 动态添加 —— new[] 做不到
    v.push_back(60);
    v.push_back(70);
    cout << "添加后: ";
    for (int x : v) cout << x << " ";   // 范围 for 循环
    cout << endl;

    // 4. 删除末尾
    v.pop_back();
    cout << "删除末尾后，大小 = " << v.size() << endl;

    // 5. 访问
    cout << "第一个元素: " << v.front() << endl;
    cout << "最后一个: " << v.back() << endl;

    // 6. vector 存对象
    vector<string> names = {"小明", "小红", "小刚"};
    names.push_back("小丽");
    for (const string& name : names) cout << name << " ";
    cout << endl;

    // 不用 delete，自动释放
    return 0;
}
