#include <iostream>
using namespace std;

void swap(int x, int y)
{ // 值传递，发生复制
    int temp = x;
    x = y;
    y = temp;
    cout << x << y << endl;
}

void swap2(int *px, int *py)
{ // 地址传递，不复制
    int temp = *px;
    *px = *py;
    *py = temp;
    cout << *px << *py << endl;
}

// 在实参传给swap3时，
// 其实就是发生了初始化int & x = a;
// int & y = b;
void swap3(int &x, int &y)
{ // 引用传递，不复制
    int temp = x;
    x = y;
    y = temp;
    cout << x << y << endl;
}

int main()
{
    int x = 1;
    int y = 2;
    swap3(x, y);
    
    cout << x << y << endl;
    return 0;
}
