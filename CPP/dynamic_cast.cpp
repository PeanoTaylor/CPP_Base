#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base() {};
};

class Derived : public Base
{
public:
    void show() { cout << "Derived\n"; }
};

int main()
{
    Base *pb = new Derived();
    Derived *pd = dynamic_cast<Derived *>(pb); // 向下转型，强制转换
    if (pd)
    {
        pd->show();
    }

    Base *pb2 = new Base();
    Derived *pd2 = dynamic_cast<Derived *>(pb2); // ❌ 返回 nullptr
    if (!pd2)
        cout << "转换失败！" << endl;
    return 0;
}
