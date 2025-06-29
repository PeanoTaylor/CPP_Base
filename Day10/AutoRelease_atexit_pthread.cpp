#include <iostream>
#include <pthread.h>
using namespace std;

class Singleton{
public:
    static Singleton *getinstance(){
        pthread_once(&m_once,init);
        return m_pInstance;
    }

    // 创建静态对象用于拷贝回收
    static void init(){
        m_pInstance = new Singleton();
        static GC gc;
    }
    
    class GC {
    public:
        ~GC() {
            if (m_pInstance) {
                delete m_pInstance;
                m_pInstance = nullptr;
            }
        }
    };
private:
    Singleton(){
        cout << "Singleton()" << endl;
    }
    ~Singleton(){
        cout << "~Singleton()" << endl;
    }

    static Singleton *m_pInstance;
    static pthread_once_t m_once;
};

Singleton * Singleton::m_pInstance = nullptr;
pthread_once_t Singleton::m_once = PTHREAD_ONCE_INIT;

int main() {
    cout << Singleton::getinstance() << endl;
    cout << Singleton::getinstance() << endl;
    cout << Singleton::getinstance() << endl;
    return 0;
}
