#include <iostream>
using namespace std;

class Singleton {
private:
    Singleton() {
        cout << "constructor" << endl;
    }

    Singleton(const Singleton &rhs) = delete;             // 禁止拷贝构造
    Singleton &operator=(const Singleton &rhs) = delete;  // 禁止赋值运算

public:
    static Singleton &getInstance() {
        static Singleton instance; // 局部静态变量，C++11 后是线程安全的
        return instance;
    }
};



int main()
{
    cout << &Singleton::getInstance() << endl;
    cout << &Singleton::getInstance() << endl;
    cout << &Singleton::getInstance() << endl;
    return 0;
}


