#include <iostream>
using namespace std;

int main(){
    int num = 2;
    int &ref = num;

    /* int num2 = 200;
    ref = num2; */

    cout << &ref << endl;
    cout << &num << endl;
}