#include <iostream>
using namespace std;

class Point {
public:
    Point() = default;
    Point(int x, int y)
    : m_x(x), m_y(y) {}

    int getX() const { return m_x; }
    int getY() const { return m_y; }

    // operator++ 前置++重载
    // 返回值类型应该是自身类型对象的引用
    Point &operator++(){
        m_x += 1;
        m_y += 1;
        return *this;
    }
    
    // operator++ 后置++重载
    // 返回值类型为自身类型对象
    // 形参列表中加上int--->为了区分前置和后置++
    // int本身没啥意义
    Point operator++(int){
        Point temp = *this;
        m_x += 1;
        m_y += 1;
        // 返回临时对象
        return temp;
    }

    friend ostream &operator<<(ostream &os, const Point &rhs);

    friend istream &operator>>(istream &is, Point &rhs);


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

    Point pt1;
    cin >> pt1;
    Point pt2 = ++pt1;
    cout << pt2 << endl;
    return 0;
}
