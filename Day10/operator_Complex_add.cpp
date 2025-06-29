#include <iostream>
using namespace std;

class Complex {
public:
    Complex(int real, int img)
    : m_real(real), m_img(img) {}

    int getreal() const { return m_real; }
    int getimg() const { return m_img; }

    // 正确的加法重载：返回值类型为值，函数是const
    /* Complex operator+(const Complex &rhs) const {
        return Complex(m_real + rhs.m_real, m_img + rhs.m_img);
    } */

    Complex operator+=(const Complex &rhs){
        m_real += rhs.m_real;
        m_img += rhs.m_img;
        return *this;
    }

    Complex operator-=(const Complex &rhs){
        m_real -= rhs.m_real;
        m_img -= rhs.m_img;
        return *this;
    }

    Complex operator++(){
        m_real += 1;
        m_img += 1;
        return *this;
    }

    Complex operator--(){
        m_real -= 1;
        m_img -= 1;
        return *this;
    }

    friend Complex operator+(const Complex &lhs, const Complex &rhs);
    friend Complex operator-(const Complex &lhs, const Complex &rhs);


    void print() const {
        cout << "Complex(" << m_real << ", " << m_img << ")" << endl;
    }

private:
    int m_real;
    int m_img;
};

Complex operator+(const Complex &lhs, const Complex &rhs){
    return Complex {lhs.m_real + rhs.m_real, lhs.m_img + rhs.m_img};
}

Complex operator-(const Complex &lhs, const Complex &rhs){
    return Complex {lhs.m_real - rhs.m_real, lhs.m_img - rhs.m_img};
}



int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);

    cout << "初始值：" << endl;
    c1.print(); // Complex(3, 4)
    c2.print(); // Complex(1, 2)

    cout << "\n测试 + 运算符：" << endl;
    Complex c3 = c1 + c2;
    c3.print(); // Complex(4, 6)

    cout << "\n测试 - 运算符：" << endl;
    Complex c4 = c1 - c2;
    c4.print(); // Complex(2, 2)

    cout << "\n测试 += 运算符：" << endl;
    c1 += c2; // c1 变成 (4,6)
    c1.print(); // Complex(4, 6)

    cout << "\n测试 -= 运算符：" << endl;
    c1 -= c2; // c1 变回 (3,4)
    c1.print(); // Complex(3, 4)

    cout << "\n测试前置 ++ 运算符：" << endl;
    ++c1;
    c1.print(); // Complex(4, 5)

    cout << "\n测试前置 -- 运算符：" << endl;
    --c1;
    c1.print(); // Complex(3, 4)

    return 0;
}

