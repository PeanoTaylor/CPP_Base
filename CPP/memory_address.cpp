#include <iostream>
#include <algorithm>  // std::swap
using namespace std;

int global_var = 100;              // 数据段
const int const_global = 200;     // 只读常量区
static int uninit_global;         // BSS段

int main() {
    int local_var = 10;                     // 栈区
    const char* str = "hello";             // 栈上指针变量
    int* heap_var = new int(42);           // 堆区

    // 数组存储变量名和地址（用指针数组）
    const char* names[] = {
        "全局变量         ",
        "常量全局变量     ",
        "未初始化全局变量 ",
        "局部变量         ",
        "指针str自身地址  ",
        "字符串常量地址   ",
        "堆变量地址       "
    };

    void* addresses[] = {
        (void*)&global_var,
        (void*)&const_global,
        (void*)&uninit_global,
        (void*)&local_var,
        (void*)&str,
        (void*)str,
        (void*)heap_var
    };

    // 冒泡排序，按地址从低到高排序，交换name和address同步
    for (int i = 0; i < 7 - 1; ++i) {
        for (int j = 0; j < 7 - 1 - i; ++j) {
            if (addresses[j] > addresses[j + 1]) {
                swap(addresses[j], addresses[j + 1]);
                swap(names[j], names[j + 1]);
            }
        }
    }

    cout << "【按地址从低到高排序】" << endl;
    for (int i = 0; i < 7; ++i) {
        cout << names[i] << " : " << addresses[i] << endl;
    }

    delete heap_var;
    return 0;
}
