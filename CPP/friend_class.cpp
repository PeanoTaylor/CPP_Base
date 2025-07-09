#include <iostream>
using namespace std;


// 友元类

/* ===== 前向声明 ===== */
class Point;  


class MyClass {
public:
    
    void print(Point &p);
};


class Point {
public:
    
    Point(int x, int y) : m_x(x), m_y(y) {}

    // 声明 MyClass::print 为友元函数
    // 这样 print 就可以访问 Point 的私有成员 m_x 和 m_y
    friend class MyClass;

private:
    int m_x;  
    int m_y;  
};


void MyClass::print(Point &p) {
    // 尽管 m_x 和 m_y 是 Point 的私有成员，
    // 但 print 是 Point 的友元函数，所以可以直接访问
    cout << p.m_x << "," << p.m_y << endl;
}


int main() {
    Point p(4, 4);     
    MyClass mc;        
    mc.print(p);       
    return 0;
}
