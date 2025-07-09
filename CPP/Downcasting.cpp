#include <iostream>
using namespace std;

// 派生类指针指向一个基类对象
class Base {
public:
    virtual void show() { cout << "Base\n"; }
};

class Derived : public Base {
public:
    void show() override { cout << "Derived\n"; }
};
int main()
{
    Base b;
    // Derived *pd = &b;// 编译错误，不能隐式转换
    
    return 0;
}

