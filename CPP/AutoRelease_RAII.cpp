#include <iostream>
using namespace std;

// 单例类定义
class Singleton
{
public:
    // 获取单例实例的静态方法
    static Singleton *getInstance()
    {
        if (!m_instance)
        {
            m_instance = new Singleton();  // 第一次调用时创建实例
        }
        return m_instance;
    }

private:
    // 私有构造函数，防止外部直接创建对象
    Singleton()
    {
        cout << "constructor" << endl;
    }

    // 私有析构函数，防止外部直接销毁对象
    ~Singleton()
    {
        cout << "destructor" << endl;
    }

    // 禁止拷贝构造函数
    Singleton(const Singleton &) = delete;

    // 禁止赋值操作
    Singleton &operator=(const Singleton &) = delete;

    // 静态成员变量，用于保存唯一的单例对象
    static Singleton *m_instance;

    // 声明 AutoRelease 为友元类，可以访问私有析构函数
    friend class AutoRelease;
};

// 静态成员变量初始化
Singleton *Singleton::m_instance = nullptr;

// 自动释放类，RAII 管理 Singleton 对象的释放
class AutoRelease
{
public:
    // 构造函数，接收一个 Singleton* 指针
    AutoRelease(Singleton *p) : m_p(p)
    {
        cout << "AutoRelease(Singleton*)" << endl;
    }

    // 析构函数，在作用域结束时自动释放 Singleton 实例
    ~AutoRelease()
    {
        cout << "~AutoRelease()" << endl;
        if (m_p)
        {
            delete m_p;                    // 释放单例对象（调用析构）
            m_p = nullptr;
            Singleton::m_instance = nullptr;  // 清空静态指针
        }
    }

private:
    Singleton *m_p;  // 持有 Singleton 实例的指针
};

// 程序入口
int main()
{
    // 创建 AutoRelease 对象，管理 Singleton 实例
    AutoRelease ar(Singleton::getInstance());

    // 多次获取 Singleton 实例，地址应相同
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;

    return 0;
    // 退出 main() 时，ar 的析构函数被调用，自动释放 Singleton
}
