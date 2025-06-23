#include <iostream>
#include <cstring>
using namespace std;

class Computer{
public:
    Computer(const char *brand, double price)
    : m_brand(new char[strlen(brand) + 1])
    , m_price(price)
    {
        strcpy(m_brand,brand);
    }
    
    void print();
private:
    char *m_brand;
    double m_price;
};

void Computer::print(){
    cout << m_brand << ":" << m_price << endl;
}
int main(int argc,char *argv[])
{
    Computer pc("APPLE",20000);
    pc.print();
    return 0;
}

