#include <iostream>
using namespace std;

// 单例类定义
class Singleton
{
public:
    // 嵌套类，用于自动释放单例对象
    class AutoRelease
    {
    public:
        AutoRelease()
        {
            cout << "AutoRelease()" << endl;
        }

        ~AutoRelease()
        {
            cout << "~AutoRelease()" << endl;
            delete m_instance;           // 释放 Singleton 实例
            m_instance = nullptr;        // 清空指针
        }
    };

    // 获取单例实例的静态方法
    static Singleton *getInstance()
    {
        if (!m_instance)
        {
            m_instance = new Singleton();  // 第一次创建实例
        }
        return m_instance;
    }

private:
    Singleton()
    {
        cout << "constructor" << endl;
    }

    ~Singleton()
    {
        cout << "destructor" << endl;
    }

    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

    static Singleton *m_instance;     // 静态单例指针
    static AutoRelease m_ar;          // 静态释放器对象，程序退出时析构

    friend class AutoRelease;         // 释放器可以访问私有析构
};

// 静态成员变量定义
Singleton *Singleton::m_instance = nullptr;
Singleton::AutoRelease Singleton::m_ar;

int main()
{
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;

    return 0;
    // 程序结束时，m_ar 析构 → 自动 delete Singleton
}
