#include <iostream>
using namespace std;

class Rectangle{
public:
    Rectangle(int length = 5, int width = 7);

private:
    int m_length;
    int m_width;
};

Rectangle::Rectangle(int length, int width)
:m_length(length)
,m_width(width)
{
    cout << "area = " << length * width << endl;
    cout << "perimeter = " << 2 * (length + width) << endl;
}

int main(int argc,char *argv[])
{
    Rectangle rectangle;
    return 0;
}

