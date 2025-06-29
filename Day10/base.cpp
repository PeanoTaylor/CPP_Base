#include <iostream>
using namespace std;

class Base{
public:
    // 构造函数
    Base(int x):m_x(x){
    }


    int getValue() const{
        return m_x;
    }
    friend Base operator+(const Base &lhs, const Base &rhs);
    friend bool operator==(const Base &lhs, int rhs); 

private:
    int m_x;
};

// 友元成员函数
Base operator+(const Base &lhs, const Base &rhs){
    return {rhs.m_x - lhs.m_x};
}

bool operator==(const Base &lhs, int rhs) {
        return lhs.m_x == rhs;
    }

int main()
{
    int i = 2;
    int j = 7;
    Base x{i};
    Base y{j};

    cout << (x+y == j - i) << endl;
    return 0;
}

