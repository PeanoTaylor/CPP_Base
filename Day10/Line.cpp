#include "Line.hpp"
#include <iostream>
using namespace std;
class Line::LineImpl{
    class Point{
    public:
        Point(int x, int y)
        : m_x(x)
        , m_y(y)
        {}
        void print()
        {
            cout << m_x << " " << m_y << endl;
        }
    private:
        int m_x;
        int m_y;
    };
public:
    LineImpl(int x1, int y1, int x2, int y2)
    : pt1(x1,y1)
    , pt2(x2,y2)
    {}
    void print()
    {
        pt1.print();
        pt2.print();
    }
private:
    Point pt1;
    Point pt2;
};

// Line的构造函数实现
Line::Line(int x1, int y1, int x2, int y2)
: m_pimpl(new LineImpl{x1,y1,x2,y2})
{
    cout << "Line()" << endl;
}
// Line的析构函数实现
Line::~Line()
{
    cout << "~Line()" << endl;
    if(m_pimpl)
    {
        delete m_pimpl;
        m_pimpl = nullptr;
    }
}
// Line的printLine的实现
void Line::printLine()
{
    m_pimpl->print();
}

int main()
{
    Line line{1, 2, 3, 4};
    line.printLine();
    return 0;
}

