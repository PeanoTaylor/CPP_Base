#include <iostream>
using namespace std;

// 利用atexit()函数 + destroyInstance函数
class Singleton{
public:
    static Singleton *getInstance(){
        if(!m_pInstance){
            m_pInstance = new Singleton{};
            // 把destroy函数注册到atexit中
            atexit(&destoryInstance);
        }
        return m_pInstance;
    }

    static void destoryInstance(){
        if(m_pInstance){
            delete m_pInstance;
            m_pInstance = nullptr;
        }
    }

    Singleton(const Singleton &) = delete;// 禁止拷贝构造
    Singleton & operator=(const Singleton &) = delete;// 禁止赋值操作
    friend class AutoRelease;
private:
    Singleton() = default;
    ~Singleton(){};
    static Singleton *m_pInstance;
};

/* Singleton * Singleton::m_pInstance = nullptr; */ //懒加载
Singleton * Singleton::m_pInstance = Singleton::getInstance(); // 立即加载
// 懒加载 : 懒汉
// 立即加载 : 饿汉


int main(int argc, char * argv[])
{
    cout << "main start" << endl;
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;
    cout << "main end" << endl;
    return 0;
}

