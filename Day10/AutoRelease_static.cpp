#include <iostream>
using namespace std;

// 利用嵌套类+静态对象 (利用静态对象的生命周期结束调用析构函数)
class Singleton{
    // 定义一个内部类
public:
    class AutoRelease
    {
    public:
        AutoRelease(){
            cout << "AutoRelease()" << endl;
        }
        ~AutoRelease(){
            cout << "~AutoRelease()" << endl;
            if(!m_pInstance){
                delete [] m_pInstance;
                m_pInstance = nullptr;
            }
        }
    };

    static Singleton *getInstance(){
        if(!m_pInstance){
            m_pInstance = new Singleton{};
        }
        return m_pInstance;
    }
    Singleton(const Singleton &) = delete;// 禁止拷贝构造
    Singleton & operator=(const Singleton &) = delete;// 禁止赋值操作
    friend class AutoRelease;
private:
    Singleton() = default;
    ~Singleton(){};
    // 自身类型的static指针
    static Singleton * m_pInstance;
    // 内部类对象作为数据成员 static 
    static AutoRelease m_ar;
};

Singleton * Singleton::m_pInstance = nullptr;
Singleton::AutoRelease m_ar; // 调用无参构造函数

int main()
{
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;
    return 0;
}

