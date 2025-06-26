#include <iostream>
#include <sstream>
#include <limits>
using namespace std;

int main()
{
    string input;
    int num;
    while(1){
        cout << "input a integer num:";
        getline(cin, input);

        stringstream ss(input);
        if (ss >> num && ss.eof()) {
            cout << "你输入的整数是：" << num << endl;
        } else {
            cout << "input again" << endl;
        }
        
    }
    return 0;
}

