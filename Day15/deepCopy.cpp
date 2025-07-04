#include <iostream>
#include <cstring>
using namespace std;

class String
{
public:
    String()
        : m_str(new char[1]) {
        m_str[0] = '\0';
    }
    // 构造函数
    String(const char *str)
    {
        m_str = new char[strlen(str) + 1];
        strcpy(m_str, str);
    }
    // 拷贝构造函数（深拷贝）
    String(const String &rhs)
    {
        m_str = new char[strlen(rhs.m_str) + 1];
        strcpy(m_str, rhs.m_str);
    }
    // 拷贝赋值运算符（深拷贝）
    String &operator=(const String &rhs)
    {
        if (this != &rhs)
        {
            delete[] m_str;
            m_str = nullptr;

            m_str = new char[strlen(rhs.m_str) + 1];
            strcpy(m_str, rhs.m_str);
        }
        return *this;
    }
    // 移动构造函数
    String(String &&rhs) : m_str(rhs.m_str)
    {
        rhs.m_str = nullptr;
    }

    // 移动赋值运算符
    String &operator=(String &&rhs)
    {
        if (this != &rhs)
        {
            delete[] m_str;
            m_str = nullptr;

            m_str = new char[strlen(rhs.m_str) + 1];
            strcpy(m_str, rhs.m_str);
        }
        return *this;
    }
     void show() const {
        cout << "String: " << (m_str ? m_str : "[empty]") << endl;
    }
    // 析构函数
    ~String()
    {
        if (m_str)
        {
            delete[] m_str;
            m_str = nullptr;
        }
    }

private:
    char *m_str;
};

void test()
{
    cout << "====== 基础构造 ======" << endl;
    String s1("hello");
    s1.show();
    String s2("world");
    s2.show();

    cout << "\n====== 移动构造 ======" << endl;
    String s3 = move(s1); // 移动构造
    s3.show();
    s1.show(); // 已被掏空

    cout << "\n====== 拷贝赋值 ======" << endl;
    String s4;
    s4 = s2; // 拷贝赋值
    s4.show();

    cout << "\n====== 移动赋值 ======" << endl;
    String s5;
    s5 = move(s2); // 移动赋值
    s5.show();
    s2.show(); // 被掏空
}

int main()
{
    test();
    return 0;
}
