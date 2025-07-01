#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
using namespace std;

class CowString
{
public:
    // 代理类，封装写时拷贝操作
    class CharProxy {
    public:
        CharProxy(CowString &cow, size_t index)
            : m_self(cow), m_index(index) {}

        // 写操作赋值
        CharProxy &operator=(char ch) {
            if (m_index >= m_self.size()) {
                cout << "illegal index" << endl;
                return *this;
            }
            // 写时拷贝逻辑
            if (m_self.getRefCount() > 1) {
                m_self.substactRefCount();
                char *newStr = new char[4 + strlen(m_self.m_pStr) + 1]{} + 4;
                strcpy(newStr, m_self.m_pStr);
                m_self.m_pStr = newStr;
                m_self.initRefCount();
            }
            m_self.m_pStr[m_index] = ch;
            return *this;
        }

        // 读操作隐式转换
        operator char() const {
            if (m_index >= m_self.size())
                return '\0';
            return m_self.m_pStr[m_index];
        }

    private:
        CowString &m_self;
        size_t m_index;
    };
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
    // const版本读取下标，返回const char&
    const char &operator[](size_t index) const
    {
        static char nullchar = '\0';
        if (index >= strlen(m_pStr))
            return nullchar;
        return m_pStr[index];
    }

    // 非const版本operator[]返回代理类，封装写操作
    CharProxy operator[](size_t index)
    {
        return CharProxy(*this, index);
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
