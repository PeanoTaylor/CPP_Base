#include <iostream>            
using namespace std;            

// 友元之普通函数

class Point {
public:
    // 构造函数
    Point(int x, int y): m_x(x), m_y(y) {}

    // 声明友元函数 print，可以访问 Point 类的私有成员变量
    friend void print(const Point &p);

private:
    int m_x;  
    int m_y;  
};

/* 定义友元函数 print
 * 注意：虽然 print 不是 Point 的成员函数，但因为被声明为 friend，
 * 所以可以访问 Point 的私有成员变量 m_x 和 m_y
 */
void print(const Point &p) {
    cout << p.m_x << "," << p.m_y << endl;  // 输出点的坐标
}

int main() {
    Point p(3, 4);     
    print(p);          
    return 0;
}
