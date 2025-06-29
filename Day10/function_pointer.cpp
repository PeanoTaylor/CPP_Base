#include <iostream>
using namespace std;

int add(int x, int y){
    return x + y;
}

int substract(int x, int y){
    return x - y;
}

int main()
{
    // 定义函数指针，返回值也应为int
    int (*funAdd)(int ,int);

    funAdd = add; // 指向add函数
    cout << "add:" << funAdd(10,5) << endl;

    funAdd = substract; // 指向add函数
    cout << "substract:" << funAdd(10,5) << endl;
    return 0;
}

