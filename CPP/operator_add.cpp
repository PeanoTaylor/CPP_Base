#include <iostream>
using namespace std;

class Point {
public:
    Point(int x, int y)
    : m_x(x), m_y(y) {}

    int getX() const { return m_x; }
    int getY() const { return m_y; }

    // 正确的加法重载：返回值类型为值，函数是const
    /* Point operator+(const Point &rhs) const {
        return Point(m_x + rhs.m_x, m_y + rhs.m_y);
    } */

    friend Point operator+(const Point &lhs, const Point &rhs);

    void print() const {
        cout << "Point(" << m_x << ", " << m_y << ")" << endl;
    }

private:
    int m_x;
    int m_y;
};

Point operator+(const Point &lhs, const Point &rhs){
    return Point {lhs.m_x + rhs.m_x, lhs.m_y + rhs.m_y};
}

int main() {
    Point p1(3, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2;  

    p3.print();  // 输出: Point(4, 6)
    return 0;
}
