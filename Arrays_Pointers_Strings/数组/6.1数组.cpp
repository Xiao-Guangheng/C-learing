//数字组的储存与初始化
//数组作为函数参数

//使用数组名传递数据时，传递的是地址。
#include <iostream>
using namespace std;

void rowSum(int a[][4], int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < 4; j++) {
            a[i][0] += a[i][j];
        }
    }
}

int main(){
    int a[3][4] = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << a[i][j] << " ";
        }
    }
    rowSum(a, 3);

    for (int i = 0; i < 3; i++) {
        cout << a[i][0] << " ";
    }
    cout << endl;
    return 0;
}