#include <iostream>
#include <cstring>
using namespace std;

class Base
{
public:
    // 构造函数
    Base(const char *str)
    {
        m_str = new char[strlen(str) + 1];
        strcpy(m_str, str);
        cout << "Base构造" << endl;
    }

    // 深拷贝
    Base(const Base &rhs)
    {
        m_str = new char[strlen(rhs.m_str) + 1];
        strcpy(m_str, rhs.m_str);
        cout << "Base拷贝构造" << endl;
    }

    // 赋值运算(深拷贝)
    Base &operator=(const Base &rhs)
    {
        if (this != &rhs)
        {
            delete[] m_str;
            m_str = new char[strlen(rhs.m_str) + 1];
            strcpy(m_str, rhs.m_str);
            cout << "Base 赋值运算: " << endl;
        }
        return *this;
    }
    // 析构函数
    ~Base()
    {
        delete[] m_str;
        m_str = nullptr;
        cout << "Base 析构" << endl;
    }

private:
    char *m_str;
};

class Derived : public Base
{
public:
    // 构造函数
    Derived(const char *baseStr, int value) : Base(baseStr), m_value(value)
    {
        cout << "Derived构造" << endl;
    }
    // 深拷贝
    Derived(const Derived &rhs) : Base(rhs), m_value(rhs.m_value)
    {
        cout << "Derived 拷贝构造" << endl;
    }
    // 赋值运算(深拷贝)
    Derived &operator=(const Derived &rhs)
    {
        if (this != this)
        {
            Base::operator=(rhs);
            m_value = rhs.m_value;
            cout << "Derived 赋值运算: " << endl;
        }
        return *this;
    }
    // 析构函数
    ~Derived()
    {
        cout << "Derived 析构" << endl;
    }

private:
    int m_value;
};

int main()
{
    Derived d1("Hello World!", 100);
    Derived d2 = d1;
    return 0;
}