#include <iostream>
#include <cstring>
using namespace std;

class Computer
{
public:
    Computer(int price, const char *brand) : m_price(price)
    {
        m_brand = new char[strlen(brand) + 1];
        strcpy(m_brand, brand);
    }

    ~Computer()
    {
        if (m_brand)
        {
            delete[] m_brand;
            m_brand = nullptr;
        }
    }
    // 拷贝构造函数（深拷贝）
    Computer(const Computer &rhs)
        : m_price(rhs.m_price)
    {
        m_brand = new char[strlen(rhs.m_brand) + 1];
        strcpy(m_brand, rhs.m_brand);
    }

    // 拷贝赋值运算符（深拷贝）
    Computer &operator=(const Computer &rhs)
    {
        if (this != &rhs)
        {
            delete[] m_brand;
            m_price = rhs.m_price;
            m_brand = new char[strlen(rhs.m_brand) + 1];
            strcpy(m_brand, rhs.m_brand);
        }
        return *this;
    }

    // 移动构造函数
    Computer(Computer &&rhs) 
        : m_price(rhs.m_price), m_brand(rhs.m_brand)
    {
        rhs.m_brand = nullptr;
    }

    // 移动赋值运算符
    Computer &operator=(Computer &&rhs) 
    {
        if (this != &rhs)
        {
            delete[] m_brand;
            m_price = rhs.m_price;
            m_brand = rhs.m_brand;
            rhs.m_brand = nullptr;
        }
        return *this;
    }

    void show() const
    {
        cout << "Computer: " << m_brand << ", Price: " << m_price << endl;
    }

private:
    int m_price;
    char *m_brand;
};


void test(){
    Computer c1(5000, "Lenovo");
    Computer c2 = c1;              // 拷贝构造
    Computer c3(6000, "Dell");
    c3 = c1;                       // 拷贝赋值

    Computer c4 = move(c1);   // 移动构造
    Computer c5(7000, "Asus");
    c5 = move(c2);            // 移动赋值

    c3.show();
    c4.show();
    c5.show();
}
int main()
{
    test();
    return 0;
}
