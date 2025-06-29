#include <iostream>
using namespace std;

class MyClass {
public:
    int data;
    void show() {
        cout << "data = " << data << endl;
    }
};

int main() {
    MyClass obj;
    obj.data = 42;

    // 成员变量指针
    int MyClass::* ptrData = &MyClass::data;
    cout << "成员变量 data = " << obj.*ptrData << endl;

    // 成员函数指针
    void (MyClass::* ptrFunc)() = &MyClass::show;
    (obj.*ptrFunc)();

    // 通过对象指针访问
    MyClass* pObj = &obj;
    cout << "通过指针访问成员变量 data = " << pObj->*ptrData << endl;
    (pObj->*ptrFunc)();

    return 0;
}
