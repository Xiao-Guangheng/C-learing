#include <iostream>
#include <vector>
#include <list>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T, int N>
void printArray(const T (&arr)[N]) {
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ========== 第三种：模板模板参数 ==========
template <typename T, template <typename, typename> class Container>
void printContainer(const Container<T, std::allocator<T>>& c) {
    for (const auto& element : c) {
        cout << element << " ";
    }
    cout << endl;
}

int main() {
    int x = 5, y = 10;
    cout << "Sum of integers: " << add(x, y) << endl;

    double a = 3.5, b = 2.5;
    cout << "Sum of doubles: " << add(a, b) << endl;

    int arr[] = {1, 2, 3, 4, 5};
    cout << "Array elements: ";
    printArray(arr);

    // 模板模板参数演示
    vector<int> vec = {10, 20, 30, 40, 50};
    cout << "Vector elements: ";
    printContainer(vec);

    list<int> lst = {100, 200, 300};
    cout << "List elements: ";
    printContainer(lst);

    return 0;
}

