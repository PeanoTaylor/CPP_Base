#include <iostream>
using namespace std;

class Point {
public:
    Point(int x, int y)
    : m_x(x), m_y(y) {}

    int getX() const { return m_x; }
    int getY() const { return m_y; }

    // 正确的加法重载：返回值类型为值，函数是const
    Point operator+=(const Point &rhs) {
        m_x += rhs.m_x;
        m_y += rhs.m_y;
        return *this;
    }

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
    int a = 1;
    a += 1;
    // a = a + 1

    Point pt1 { 1, 1 };
    Point pt2 { 2, 2 };
    /* cx1 += cx2; */
    // 本质
    pt2.operator+=(pt1);
    pt2.print();
    return 0;
}
