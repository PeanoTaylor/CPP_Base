#include <iostream>
using namespace std;
class Point{
public:
    // 3.返回值为引用，避免复制
    static Point & getInstance(){
        // 2.初始化一次，每次返回同一对象
        static Point  instance;
        return instance;
    }

private:
    // 1.私有化构造函数，确保外部无法创建
    Point(){
        cout << "default constructor" << endl;
    }
};

int main()
{
    Point &instance1= Point::getInstance();
    cout << &instance1 << endl;

    Point &instance2 = Point::getInstance();
    cout << &instance2 << endl;
    return 0;
}

