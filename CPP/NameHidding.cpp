#include <iostream>
using namespace std;

class Base {
public:
    void show() {
        cout << "Base::show()" << endl;
    }

    void show(int x) {
        cout << "Base::show(int): " << x << endl;
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived::show()" << endl;
    }
};

int main() {
    Derived d;

    d.show();         // 调用 Derived::show()

    // d.show(10);    // ❌ 错误！Base::show(int) 被隐藏，不能直接访问

    d.Base::show(10); // ✅ 正确访问基类的 show(int)

    return 0;
}
