#include <iostream>
using namespace std;

class Point{
public:
    // 获取单例对象实例
    static Point *getInstance(){
        // 堆上创建对象
        if(instance == nullptr){
            instance = new Point();
        }
        return instance;
    }
    // 回收空间
    static void destoryInstance(){
        if(instance != nullptr){
            delete instance;
            instance = nullptr;
        }
    }

    // 设置数据成员值
    void setData(int x, int y) {
        m_x = x;
        m_y = y;
    }

    // 获取数据成员值
    void display() const {
        cout << "Point(" << m_x << ", " << m_y << ")" << endl;
    }

private:
    Point(){
        cout << "default constructor" << endl;
    }
    ~Point(){
        cout << "destructor" << endl;
    }
    static Point *instance;// 持有单例对象

    // 禁止复制和赋值，保证单例
    Point(const Point &) = delete;
    Point & operator = (const Point &) = delete;
    int m_x,m_y;
};

Point *Point::instance = nullptr;
int main()
{
    Point *p1 = Point::getInstance();
    p1->display();

    p1->setData(2,3);
    p1->display();

    p1->destoryInstance();

    return 0;
}

