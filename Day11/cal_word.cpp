#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

struct Record
{
	string _word;
	int _frequency;
};

class Dictionary
{
public:
	//......
    void read(const string &filename);
    void store(const string &filename);
private:
    map<string,int> _dict;
};

void Dictionary::read(const string &filename){
    ifstream ifs(filename);

    if(!ifs.is_open()){
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    while(getline(ifs,line)){// 从文件中逐行读取内容放到line字符串中
        stringstream ss(line);// 将该行包装成输入流
        string word;
        while (ss >> word){
            if(!word.empty()){
                ++_dict[word];
            }
        }
    }
    ifs.close();
}

void Dictionary::store(const string &filename){
    ofstream ofs(filename);
    if(!ofs.is_open()){
        cerr << "Error open file " << filename << endl;
        return;
    }

    for (const auto &pair : _dict)
    {
        ofs << pair.first << ":" << pair.second << endl;
    }
    ofs.close();
    
}

int main()
{
    Dictionary dict;
    dict.read("The_Holy_Bible.txt");
    dict.store("count_res.txt");
    cout << "finish cal The_Holy_Bible " << endl;
    return 0;
}

