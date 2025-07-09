#include <iostream>
using namespace std;

class Base
{
public:
    virtual void speak()
    {
        cout << "狗叫" << endl;
    }
};

class Derived : public Base
{
public:
    void speak() override
    {
        cout << "猫叫" << endl;
    }
};

int main()
{
    Derived d;
    d.speak();
    return 0;
}
