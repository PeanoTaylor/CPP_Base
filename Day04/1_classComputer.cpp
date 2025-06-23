#include <iostream>
#include <cstring>
using namespace std;

class Computer{
public:
    void setBrand(const char *brand);// 设置品牌

    void setPrice(float price);// 设置价格

    void print();//打印信息
private:
    char m_brand[20];
    float m_price;
};

void Computer::setBrand(const char *brand){
    strcpy(m_brand,brand);
}
void Computer::setPrice(float price){
    m_price = price;
}
void Computer::print(){
    cout << m_brand << ":" << m_price << endl;
}

int main(int argc,char *argv[])
{
    Computer pc;
    pc.setBrand("APPLE");
    pc.setPrice(9999);
    pc.print();
    return 0;
}

