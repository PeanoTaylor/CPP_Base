#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void readFile(){
    // 文件输入流对象的创建
    ifstream ifs;
    ifs.open("file.txt");

    // 读文件数据
    string word;
    // 只要ifs是goodbit状态就会一直读取
    while(ifs >> word){
        cout << word << endl;
    }
    // 规范操作, 使用完之后关闭流
    ifs.close();
}
int main()
{
    readFile();
    return 0;
}
