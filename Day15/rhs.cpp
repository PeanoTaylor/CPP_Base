#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int a = 10;
    // 非const左值引用不能绑定右值
    int &r1 = a;
    // int &r2 = 1; // error

    // const左值引用既可以绑定左值，又可以绑定右值
    const int &r3 = 1;
    const int &r4 = a;

    // 右值引用只能绑定右值
    int &&rRef = 10;
    // int &&rRef2 = a; // error
    return 0;
}
