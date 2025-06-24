#include <iostream>
#include <cstring>
class Computer{
public:
    // 构造函数
    Computer(const char *name, int price)
    : m_price(price)
    {
        // 分配内存并且初始化
        m_name = new char[strlen(name) + 1];
        strcpy(m_name,name);
    };
    ~Computer(){
        delete [] m_name;
    };
    void display() const {
        std::cout << "Brand: " << m_name << ", Price: " << m_price << std::endl;
    }
private:
    char *m_name;
    int m_price;
    // 私有化new
    void* operator new(size_t size) = delete;
};
int main()
{
    Computer pc("Lenovo",6000);
    pc.display();
    return 0;
}

