#include <iostream>
using namespace std;

class Point{
public:
    // 构造函数
    Point(int x = 0, int y = 0)
        :m_x(x)
         ,m_y(y)
    {}
    // 赋值运算符重载
    Point &operator = (const Point &rhs){
        if(this != &rhs){// 防止自赋值
            this->m_x = rhs.m_x;
            this->m_y = rhs.m_y;
        }
        cout << "operater called " << endl;
        return *this;
    }
    void print(){
        cout << m_x << "," << m_y << endl;
    }
private:
    int m_x;
    int m_y;
};

int main(int argc,char *argv[])
{
    Point p1(1,2);
    Point p2;
    p2 = p1;// 调用赋值运算符
    p2.print();

    Point p3;
    p3 = p2 = p1;
    p3.print();
    return 0;
}

