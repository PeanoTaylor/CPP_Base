#include <iostream>
#include <cstring>
using namespace std;
/**
 * 请结合前面学到的知识完成这个功能：无论是创建多个Computer对象，还是进行Computer对象的复制、赋值，Computer的总价始终能够正确输出
 */
class Computer{
public:
    Computer():m_brand(nullptr), m_price(0){};
    // 构造函数
    Computer(const char *brand, float price)
    : m_price(price)
    {
        m_brand = new char[strlen(brand) + 1];
        strcpy(m_brand,brand);
        m_totalPrice += m_price;
    }
    // 拷贝构造函数
    Computer(const Computer &pc)
    : m_price(pc.m_price)
    {
        m_brand = new char[strlen(pc.m_brand) + 1];
        strcpy(m_brand,pc.m_brand);
        m_totalPrice += m_price;
    }
    // 析构函数
    ~Computer(){
        if(m_brand){
            delete [] m_brand;
            m_brand = nullptr;
        }
    }

    Computer &operator = (const Computer &pc){
        if(this != &pc){// 防止自赋值
            delete [] m_brand;
            m_brand = new char[strlen(pc.m_brand) + 1]{};
            // 减去原来价格
            m_totalPrice -= m_price;
            // 新价格
            m_price = pc.m_price;
            // 加上新价格
            m_totalPrice += m_price;
        }
        return *this;
    }

    static void display(){
        cout << "totalPrice:" << m_totalPrice << endl;
    }
private:
    char *m_brand;
    float m_price;
    static float m_totalPrice;
}; 
float Computer::m_totalPrice = 0.0;

int main()
{
    Computer pc1("APPLE",10000);
    pc1.display();

    Computer pc2("XIAOMI",10000);
    pc2.display();

    Computer pc3;
    pc3 = pc2;
    pc3.display();
    return 0;
}

