#include <iostream>
using namespace std;

class Base
{
public:
    int a = 1;
};

class Derived : public Base
{
public:
    int b = 2;
};

int main()
{
    Derived d;
    Base b = d;
    cout << b.a << endl;
    return 0;
}
