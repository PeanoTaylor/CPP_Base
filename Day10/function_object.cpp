#include <iostream>
using namespace std;

class MyFunc {
public:
    int operator()(int x) {
        return x * x;
    }
};

int main() {
    MyFunc f;         // 创建函数对象
    cout << f(5);     // 像函数一样调用：f(5)
    return 0;
}
