#include <iostream>
#include <math.h>
using namespace std;

class Figure
{
public:
    virtual string getName() const = 0;
    virtual double getArea() const = 0;
    virtual ~Figure() {}
};
// 矩形类
class Rectangle : public Figure
{
public:
    Rectangle(double length, double width)
        : m_length(length), m_width(width) {}

    string getName() const override
    {
        return "矩形";
    }

    double getArea() const override
    {
        return m_length * m_width;
    }

private:
    double m_length;
    double m_width;
};

class Circle : public Figure
{
public:
    Circle(double radius) : m_radius(radius) {}

    string getName() const override
    {
        return "圆";
    }

    double getArea() const override
    {
        return 3.14 * m_radius * m_radius;
    }

private:
    double m_radius;
};
// 三角形
class Triangle : public Figure
{
public:
    Triangle(double a, double b, double c) : m_a(a), m_b(b), m_c(c) {}

    string getName() const override
    {
        return "三角形";
    }

    double getArea() const override
    {
        double s = (m_a + m_b + m_c) / 2;
        double area = sqrt(s * (s - m_a) * (s - m_b) * (s - m_c));
        return area;
    }

private:
    double m_a;
    double m_b;
    double m_c;
};

void display(Figure &fig)
{
    cout << fig.getName()
         << "的面积是:"
         << fig.getArea() << endl;
}

void test()
{
    Rectangle r(10, 20);
    Circle c(15);
    Triangle t(3, 4, 5);
    display(r);
    display(c);
    display(t);
}
int main()
{
    test();
    return 0;
}
