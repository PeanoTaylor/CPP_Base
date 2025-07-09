#include <iostream>
using namespace std;

class Point{
public:
    Point(int x, int y)
    : m_x(x)
    , m_y(y){}

    Point &operator=(const Point &rhs){
        this->m_x = rhs.m_x;
        this->m_y = rhs.m_y;
        return *this;
    }

    void print() const{
        cout << "Point(" << m_x << ", " << m_y << ")" << endl;
    }
private:
    int m_x;
    int m_y;
};

void test(){
    int a=1;
    int b=2;
    b=a;
    Point pt1{1,1};
    Point pt2{2,2};
    pt2.operator=(pt1);
    pt2.print();
}

int main()
{
    test();
    return 0;
}

