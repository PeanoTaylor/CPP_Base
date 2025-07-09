#include <iostream>
#include <pthread.h>
using namespace std;

class Singleton
{
public:
    static Singleton *getInstance()
    {
        pthread_once(&m_once_control,&initRoutine);
        return m_instance;
    }

    static void initRoutine()
    {
        m_instance = new Singleton();
        atexit(&destoryInstance);
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
    static pthread_once_t m_once_control;
};
Singleton *Singleton::m_instance = nullptr;
pthread_once_t Singleton::m_once_control = PTHREAD_ONCE_INIT;

int main()
{
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;
    return 0;
}
