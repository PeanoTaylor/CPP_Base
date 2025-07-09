#include <iostream>
using namespace std;

class Singleton {
private:
    Singleton() {
        cout << "constructor" << endl;
    }

    ~Singleton() {
        cout << "destructor" << endl;
    }

    Singleton(const Singleton &rhs) = delete;             // 禁止拷贝构造
    Singleton &operator=(const Singleton &rhs) = delete;  // 禁止赋值运算

    static Singleton *m_Instance;

public:
    static Singleton *getInstance() {
        if(m_Instance == nullptr){
            m_Instance = new Singleton();
        }
        return m_Instance;
    }

    static void destory(){
        delete m_Instance;
        m_Instance = nullptr;
    }
};

Singleton *Singleton::m_Instance = nullptr;



int main()
{
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;
    cout << Singleton::getInstance() << endl;

    Singleton::destory();
    return 0;
}


