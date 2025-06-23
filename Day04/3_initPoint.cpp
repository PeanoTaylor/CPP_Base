#include <iostream>
using namespace std;

class Point{
public:
    Point(int ix = 0, int iy = 2);
    void print(){
        cout << "(" << m_x << "," << m_y << ")" << endl;
    }
    /* Point(int x){ */
    /*     m_x = x; */
    /* } */
    /* Point(int x, int y){ */
    /*     m_x = x; */
    /*     m_y = y; */
    /* } */

private:
    int m_x;
    int m_y;
};
Point::Point(int ix, int iy)
    :m_x(ix)
    ,m_y(iy)
{}
int main(int argc,char *argv[])
{
    Point pt;
    pt.print();
    return 0;
}

