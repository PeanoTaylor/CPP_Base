#include <iostream>
using namespace std;

class Singleton
{
public:
    static Singleton *getInstance()
    {
        if (!m_instance)
        {
            m_instance = new Singleton();
            atexit(&destoryInstance);
        }
        return m_instance;
    }

    static void destoryInstance()
    {
        cout << "destroyInstance()" << endl;
        if (m_instance)
        {
            delete m_instance;
            m_instance = nullptr;
        }
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
    static Singleton *m_instance;
};
// Singleton *Singleton::m_instance = nullptr; 懒汉模式
Singleton * Singleton::m_instance = Singleton::getInstance();//饿汉模式

int main()
{
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;
    return 0;
}
