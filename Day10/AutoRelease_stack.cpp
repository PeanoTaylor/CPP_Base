#include <iostream>
using namespace std;

//方式一: 利用栈对象的生命周期
class Singleton{
public:
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
    static Singleton *m_pInstance;
};

Singleton *Singleton::m_pInstance = nullptr;

class AutoRelease{
public:
    AutoRelease(Singleton *p)
    : m_p(p)
    {
        cout << "AutoRelease(Singleton*)" << endl;
    }
    ~AutoRelease(){
        cout << "~AutoRelease()" << endl;
        if(m_p){
            delete m_p;
            m_p = nullptr;
        }
    }

private:
    Singleton *m_p;
};


int main()
{
    AutoRelease ar {Singleton::getInstance()};

    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;
    return 0;
}

