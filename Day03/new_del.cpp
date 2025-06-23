#include <iostream>
#include <cstring>
using namespace std;

int main(int argc,char *argv[])
{
    
    char *str = new char[20];

    strcpy(str,"Hello World!");
    cout << sizeof(str) << endl;
    cout << str << endl;
    delete[] str;
    return 0;
}

