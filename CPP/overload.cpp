#include <iostream>
using namespace std;

void print(int x) {
    cout << "整型: " << x << endl;
}

void print(double x) {
    cout << "浮点型: " << x << endl;
}

void print(int x, int y) {
    cout << "两个整型: " << x << ", " << y << endl;
}

int main() {
    print(10);        // 调用 void print(int)
    print(3.14);      // 调用 void print(double)
    print(1, 2);      // 调用 void print(int, int)
}
