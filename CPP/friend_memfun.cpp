#include <iostream>
using namespace std;


// 友元之成员函数

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
    friend void MyClass::print(Point &p);

private:
    int m_x;  
    int m_y;  
};

/* ===== MyClass 的成员函数定义 ===== */
void MyClass::print(Point &p) {
    // 尽管 m_x 和 m_y 是 Point 的私有成员，
    // 但 print 是 Point 的友元函数，所以可以直接访问
    cout << p.m_x << "," << p.m_y << endl;
}

/* ===== 主函数入口 ===== */
int main() {
    Point p(3, 4);     // 创建一个 Point 对象，坐标初始化为 (3, 4)
    MyClass mc;        // 创建 MyClass 类对象
    mc.print(p);       // 调用 MyClass 的成员函数，打印坐标：3,4
    return 0;
}
