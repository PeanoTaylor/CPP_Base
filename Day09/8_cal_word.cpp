#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
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
    vector<Record> _dict;
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
            if(word.empty()){
                continue;
            }

            bool exist = false;// Vector是否已经存在该词汇
            for(auto &rec : _dict){
                if(rec._word == word){
                    rec._frequency++;
                    exist = true;
                    break;
                }
            }

            if(!exist){
                _dict.push_back({word,1});
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

    for(auto const &rec : _dict){
        ofs << rec._word << ":" << rec._frequency << endl; 
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

