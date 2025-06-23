#include <iostream>
using namespace std;

class Point{
public:
    Point(){
        m_x = 0;
        m_y = 0;
    }
    void print(){
        cout << "(" << m_x << "," << m_y << ")" << endl;
    }
    Point(int x){
        m_x = x;
    }
    Point(int x, int y){
        m_x = x;
        m_y = y;
    }

private:
    int m_x;
    int m_y;
};
// 无参
void test1(){
    Point pt;
    pt.print();
}
// 一个参数
void test2(int x){
    Point pt(x);
    pt.print();
}
// 两个参数
void test3(int x, int y){
    Point pt(x,y);
    pt.print();
}
int main(int argc,char *argv[])
{
    // test1();
    // test2(10);
    test3(2,5);
    return 0;
}

