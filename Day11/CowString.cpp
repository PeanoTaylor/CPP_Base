#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
using namespace std;

class CowString
{
public:
    // no arg constructor
    CowString()
        : m_pStr(new char[4 + 1]{} + 4)
    {
        initRefCount();
    }
    // arg constructor
    CowString(const char *pStr)
        : m_pStr(new char[4 + strlen(pStr) + 1]{} + 4)
    {
        strcpy(m_pStr, pStr);
        initRefCount();
    }
    // destructor
    ~CowString();
    // copy constructor
    CowString(const CowString &cowString) // 浅拷贝
        : m_pStr(cowString.m_pStr)
    {
        addRefCount();
    }
    // operator <<
    friend ostream &operator<<(ostream &os, const CowString &cowString);
    // operator =
    CowString &operator=(const CowString &cowString)
    {
        if (this != &cowString)
        {
            release();
            m_pStr = cowString.m_pStr;
            addRefCount();
        }
        return *this;
    }
    // operator []
    char &operator[](size_t index)
    {
        if (index >= strlen(m_pStr))
        {
            cout << "illegal index" << endl;
            static char nullstr = '\0';
            return nullstr;
        }

        if (getRefCount() > 1)
        { // 不是指向内存唯一拥有者
            // 原count--
            substactRefCount();

            // 开辟内存空间深拷贝
            char *newStr = new char[4 + strlen(m_pStr) + 1]{} + 4;
            strcpy(newStr, m_pStr);
            m_pStr = newStr;
            initRefCount();
        }
        return m_pStr[index];
    }

    const char &operator[](size_t index) const
    {
        if (index >= strlen(m_pStr))
        {
            static char nullchar = '\0';
            return nullchar;
        }
        return m_pStr[index];
    }
    // 用于获取字符串长度的方法
    size_t size()
    {
        return strlen(m_pStr);
    }
    // 返回C风格字符串
    char *c_str()
    {
        return m_pStr;
    }

    // 获取引用计数
    int getRefCount()
    {
        return *(int *)(m_pStr - 4);
    }

private:
    // 计数器函数
    void initRefCount()
    {
        *(int *)(m_pStr - 4) = 1;
    }
    void substactRefCount()
    {
        --*(int *)(m_pStr - 4);
    }
    void addRefCount()
    {
        ++*(int *)(m_pStr - 4);
    }
    // release
    void release()
    {
        substactRefCount();
        if (getRefCount() == 0)
        {
            delete[] (m_pStr - 4);
            cout << "release heap====" << endl;
        }
        m_pStr = nullptr;
    }
    // pointer to char array
    char *m_pStr;
};

ostream &operator<<(ostream &os, const CowString &cowString)
{
    os << cowString.m_pStr;
    return os;
}

CowString::~CowString()
{
    cout << "~CowString()" << endl;
    release();
}
void test1()
{
    // 拷贝构造
    CowString s1{"bcd"};
    CowString s2{"abc"};
    cout << "s1:" << s1 << endl;
    cout << "s2:" << s2 << endl;
    cout << "s2.cout:" << s2.getRefCount() << endl;
    cout << "------" << endl;
    CowString s3 = s2; // 拷贝构造
    cout << "s3:" << s3 << endl;
    cout << "s2.cout:" << s2.getRefCount() << endl;
    cout << "s3.cout:" << s3.getRefCount() << endl;
}

void test2()
{
    CowString s1("abc");
    CowString s2 = s1;
    CowString s3("bcd");
    cout << "s1:" << s1 << endl;
    cout << "s2:" << s2 << endl;
    cout << "s3:" << s3 << endl;
    cout << "s1.cout:" << s1.getRefCount() << endl;
    cout << "s2.cout:" << s2.getRefCount() << endl;
    cout << "s3.cout:" << s3.getRefCount() << endl;

    cout << "-----" << endl;
    s1 = s3;
    s2 = s3;
    cout << "s1:" << s1 << endl;
    cout << "s2:" << s2 << endl;
    cout << "s3:" << s3 << endl;
    cout << "s1.cout:" << s1.getRefCount() << endl;
    cout << "s2.cout:" << s2.getRefCount() << endl;
    cout << "s3.cout:" << s3.getRefCount() << endl;
}

void test3()
{
    // 测试访问下标
    CowString s1("abcd");
    CowString s2 = s1;
    cout << "s1[0]:" << s1[0] << endl;
    s1[0] = 'A';
    cout << "s1:" << s1 << endl;
    cout << "s2:" << s2 << endl;
}
int main()
{
    test1();
    test2();
    test3();
    return 0;
}
