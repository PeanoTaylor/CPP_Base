#include <iostream>
using namespace std;

class Base
{
    int a1,a2;
public:
    Base(int x1 = 0, int x2 = 0)
    : a1(x1)
    , a2(x2)
    {}
    int getValueA1(){
        return a1;
    }
    int getValueA2(){
        return a2;
    }
};


int main()
{
    Base data(2,3);
    cout << data.getValueA1() << endl;
    cout << data.getValueA2() << endl;

    return 0;
}

