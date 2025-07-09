#include <iostream>
#include <vector>
using namespace std;

class Point
{
public:
    Point(int x, int y) : m_x(x), m_y(y)
    {
        cout << "constructor" << endl;
    }

    Point(const Point &rhs)
    {
        m_x = rhs.m_x;
        m_y = rhs.m_y;
        cout << "const Point &rhs" << endl;
    }
    ~Point() {}

private:
    int m_x;
    int m_y;
};
int main()
{
    vector<Point> vec;
    //vec.push_back(Point(1,2));
    vec.emplace_back(1,2);
    return 0;
}
