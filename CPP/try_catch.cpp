#include <iostream>
#include <stdexcept> // 包含 std::runtime_error

using namespace std;

double divide(int a, int b)
{
    if (b == 0)
    {
        throw runtime_error("除数不能为0");
    }
    return static_cast<double>(a) / b;
}

int main()
{
    int a = 10, b = 0;
    try
    {
        double res = divide(a, b);
        cout << "res = " << res << endl;
    }
    catch (const exception &e)
    {
        cerr << "error info:" << e.what() << endl;
    }

    return 0;
}
