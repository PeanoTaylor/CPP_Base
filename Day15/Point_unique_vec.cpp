#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Point
{
public:
    Point() {}

    void print()
    {
        cout << "(" << m_x << "," << m_y << ")" << endl;
    }
    Point(int x, int y)
    {
        m_x = x;
        m_y = y;
    }

private:
    int m_x;
    int m_y;
};

int main()
{
    vector<unique_ptr<Point>> points;

    // 创建 Point 对象并加入容器
    points.push_back(unique_ptr<Point>(new Point(1, 2)));
    points.push_back(unique_ptr<Point>(new Point(2, 2)));
    points.push_back(unique_ptr<Point>(new Point(13, 2)));

    for (const auto &up : points)
    {
        up->print(); // 通过 unique_ptr 访问对象
    }
    return 0;
}
