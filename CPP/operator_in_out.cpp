#include <iostream>
using namespace std;

class Point {
public:
    Point() = default;
    Point(int x, int y)
    : m_x(x), m_y(y) {}

    int getX() const { return m_x; }
    int getY() const { return m_y; }

    // 正确的加法重载：返回值类型为值，函数是const
    /* Point operator+(const Point &rhs) const {
        return Point(m_x + rhs.m_x, m_y + rhs.m_y);
    } */

    friend ostream &operator<<(ostream &os, const Point &rhs);

    friend istream &operator>>(istream &is, Point &rhs);

    void print() const {
        cout << "Point(" << m_x << ", " << m_y << ")" << endl;
    }

private:
    int m_x;
    int m_y;
};

// 友元函数形式
ostream &operator<<(ostream &os, const Point &rhs){
    // os << rhs.m_x << "," << rhs.m_y << endl;
    os << "Point(" << rhs.m_x << ", " << rhs.m_y << ")" << endl;
    return os;
}

istream& operator>>(istream &is, Point &rhs) {
    is >> rhs.m_x >> rhs.m_y;
    return is;
}


int main() {

    Point pt;
    cin >> pt;
    cout << pt;
    return 0;
}
