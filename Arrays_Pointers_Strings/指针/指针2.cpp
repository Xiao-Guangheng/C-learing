#include <iostream>
#include <cstdlib>
using namespace std;

int cmp_int(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int cmp_desc(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

void sortAndShow(int arr[], int n, int (*cmp)(const void*, const void*)) {
    qsort(arr, n, sizeof(int), cmp);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = { 5, 2, 9, 1, 7, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int choice;

    cout << "1. 升序  2. 降序  请选择：";
    cin >> choice;

    int (*cmp)(const void*, const void*);  // 函数指针变量
    if (choice == 1)
        cmp = cmp_int;
    else
        cmp = cmp_desc;

    sortAndShow(arr, n, cmp);

    return 0;
}

