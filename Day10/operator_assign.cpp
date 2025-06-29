#include <iostream>
using namespace std;

class Complex;// 前置声明

class Point{
public:
    Point(int x, int y)
    : m_x(x)
    , m_y(y){}
    friend class Complex;

    // 方式三：Point 转 Complex
    operator Complex() const;
private:
    int m_x;
    int m_y;
};

class Complex{
public:
    Complex(int real, int img)
    : m_real(real)
    , m_img(img){}

    void print() {
        cout << m_real << " + " << m_img << "i" << endl;
    }

    // 方式一：赋值运算符重载
    Complex &operator=(const Point &pt){
        cout << "operator= (const Point&)" << endl;
        m_real = pt.m_x;
        m_img = pt.m_y;
        return *this;
    }

    // 方式二：Point 转 Complex 构造函数
    Complex(const Point &pt) {
        cout << "Complex(Point) constructor" << endl;
        m_real = pt.m_x;
        m_img = pt.m_y;
    }
private:
    int m_real;
    int m_img;
};

Point::operator Complex() const{
    cout << "Point::operator Complex()" << endl;
    return Complex(m_x,m_y);
}
int main()
{
    Point pt(8, 9);

    cout << "=== 方式一：赋值运算符重载 ===" << endl;
    {
        Complex cx(4, 6);
        cx = pt;
        cx.print();
    }

    cout << "\n=== 方式二：构造函数转换 + 默认赋值 ===" << endl;
    {
        Complex cx(4, 6);
        cx = Complex(pt);
        cx.print();
    }

    cout << "\n=== 方式三：Point 提供转换运算符 ===" << endl;
    {
        Complex cx(4, 6);
        cx = pt;  // 调用 Point::operator Complex()
        cx.print();
    }

    return 0;
}

