#include <iostream>
using namespace std;

template <typename T>
T add(T value)
{
    return value;
}

template <typename T, typename... Args>
T add(T value, Args... args)
{
    return value + add(args...);
}
int main()
{
    cout << add(1, 2, 3, 4, 5) << endl;
    cout << add(1.2, 3.4, 5.6) << endl;
    cout << add(1, 2.5, 3, 4.5) << endl;
    return 0;
    return 0;
}
