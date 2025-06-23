#include <iostream>
using namespace std;
#define SQUARE ((x) * (x))

inline double square(double x){
    return x * x;
}
int main(int argc,char *argv[])
{
    double x;
    cin >> x;
    double res = square(x);
    cout << "res_inline = " << res << endl;
    cout << "res_def = " << SQUARE << endl;
    return 0;
}

