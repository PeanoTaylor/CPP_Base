#include <iostream>
using namespace std;

// 基类指针指向一个派生类对象
class Base {
public:
    virtual void show() { cout << "Base\n"; }
};

class Derived : public Base {
public:
    void show() override { cout << "Derived\n"; }
};

int main() {
    Derived d;
    Base* pb = &d;  // ✅ 合法
    pb->show();     // 输出：Derived（多态）
}

