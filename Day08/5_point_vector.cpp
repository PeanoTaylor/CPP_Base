#include <iostream>
#include <vector>
using namespace std;

class Point{
public:

    // 构造函数
    Point(int x, int y)
    : m_x(x)
    , m_y(y){}
    // 打印信息
    void print(){
        cout << "(" << m_x << "," << m_y << ")" << endl;
    }

private:
    int m_x;
    int m_y;
};
int main()
{
    Point p1(1,2);
    Point p2(3,4);
    Point p3(5,6);
    Point p4(7,8);

    vector <Point> vec_p;
    vec_p.push_back(p1);
    vec_p.push_back(p2);
    vec_p.push_back(p3);
    vec_p.push_back(p4);

    for(auto &point : vec_p){
        point.print();
    }
    return 0;
}
